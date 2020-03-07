/***********
 * rgb_t.h *
 ***********/

#pragma once

/**
 * Implementation of hsl_to_rgb as constexpr functions based on:
 *
 *   https://www.rapidtables.com/convert/color/hsl-to-rgb.html
 */

constexpr float _hsl_fmod(float x, float y) {
  return x - int(x/y)*y;
}

constexpr float _hsl_c(float, float S, float L) {
  return (1.0f - fabs(2*L-1.0f)) * S;
}

constexpr float _hsl_x(float H, float S, float L) {
  return _hsl_c(H,S,L) * (1.0f - fabs(_hsl_fmod(H/60, 2) - 1));
}

constexpr float _hsl_m(float H, float S, float L) {
  return L - _hsl_c(H,S,L)/2;
}

constexpr float _hsl_rgb(float H, float S, float L, float r, float g, float b) {
  return ((uint32_t((r + _hsl_m(H,S,L))*255+0.5) << 16) |
          (uint32_t((g + _hsl_m(H,S,L))*255+0.5) <<  8) |
          (uint32_t((b + _hsl_m(H,S,L))*255+0.5) <<  0));
}

constexpr uint32_t hsl_to_rgb(float H, float S, float L) {
  return (H <  60) ? _hsl_rgb(H,S,L,_hsl_c(H,S,L), _hsl_x(H,S,L), 0) :
         (H < 120) ? _hsl_rgb(H,S,L,_hsl_x(H,S,L), _hsl_c(H,S,L), 0) :
         (H < 180) ? _hsl_rgb(H,S,L,            0, _hsl_c(H,S,L), _hsl_x(H,S,L)) :
         (H < 240) ? _hsl_rgb(H,S,L,            0, _hsl_x(H,S,L), _hsl_c(H,S,L)) :
         (H < 300) ? _hsl_rgb(H,S,L,_hsl_x(H,S,L),             0, _hsl_c(H,S,L)) :
                     _hsl_rgb(H,S,L,_hsl_c(H,S,L),             0, _hsl_x(H,S,L));
}

/**
 * Structure for RGB colors
 */
struct rgb_t {
    union {
      struct {
        uint8_t  b,g,r,a;
      };
      uint32_t packed;
    };

    rgb_t()                                : packed(0)              {}
    rgb_t(uint32_t rgb)                    : packed(rgb)            {}
    rgb_t(uint8_t r, uint8_t g, uint8_t b) : b(b), g(g), r(r), a(0) {}
    operator uint32_t() const              {return packed;};

    static void lerp(float t, const rgb_t a, const rgb_t b, rgb_t &c) {
      c.r = a.r + t * (b.r - a.r);
      c.g = a.g + t * (b.g - a.g);
      c.b = a.b + t * (b.b - a.b);
    }

    uint8_t luminance() const {return 0.299*r + 0.587*g + 0.114*b;}
};