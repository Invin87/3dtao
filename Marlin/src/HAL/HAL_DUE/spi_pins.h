#pragma once

/**
 * Define SPI Pins: SCK, MISO, MOSI, SS
 *
 * Available chip select pins for HW SPI are 4 10 52 77
 */
#if SDSS == 4 || SDSS == 10 || SDSS == 52 || SDSS == 77 || SDSS == 87
  #if SDSS == 4
    #define SPI_PIN         87
    #define SPI_CHAN         1
  #elif SDSS == 10
    #define SPI_PIN         77
    #define SPI_CHAN         0
  #elif SDSS == 52
    #define SPI_PIN         86
    #define SPI_CHAN         2
  #elif SDSS == 77
    #define SPI_PIN         77
    #define SPI_CHAN         0
  #else
    #define SPI_PIN         87
    #define SPI_CHAN         1
  #endif
  #define SCK_PIN           76
  #define MISO_PIN          74
  #define MOSI_PIN          75
#else
  // defaults
  #define DUE_SOFTWARE_SPI
  #ifndef SCK_PIN
    #define SCK_PIN           52
  #endif
  #ifndef MISO_PIN
    #define MISO_PIN          50
  #endif
  #ifndef MOSI_PIN
    #define MOSI_PIN          51
  #endif
#endif

/* A.28, A.29, B.21, C.26, C.29 */
#define SS_PIN            SDSS
