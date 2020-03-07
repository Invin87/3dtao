#pragma once

#include "../inc/MarlinConfigPre.h"

void host_action(const char * const pstr, const bool eol=true);

#ifdef ACTION_ON_KILL
  void host_action_kill();
#endif
#ifdef ACTION_ON_PAUSE
  void host_action_pause(const bool eol=true);
#endif
#ifdef ACTION_ON_PAUSED
  void host_action_paused(const bool eol=true);
#endif
#ifdef ACTION_ON_RESUME
  void host_action_resume();
#endif
#ifdef ACTION_ON_RESUMED
  void host_action_resumed();
#endif
#ifdef ACTION_ON_CANCEL
  void host_action_cancel();
#endif

#if ENABLED(HOST_PROMPT_SUPPORT)

  extern const char CONTINUE_STR[], DISMISS_STR[];

  enum PromptReason : uint8_t {
    PROMPT_NOT_DEFINED,
    PROMPT_FILAMENT_RUNOUT,
    PROMPT_USER_CONTINUE,
    PROMPT_FILAMENT_RUNOUT_REHEAT,
    PROMPT_PAUSE_RESUME,
    PROMPT_INFO
  };

  extern PromptReason host_prompt_reason;

  void host_response_handler(const uint8_t response);
  void host_action_notify(const char * const message);
  void host_action_prompt_begin(const PromptReason reason, const char * const pstr, const char extra_char='\0');
  void host_action_prompt_button(const char * const pstr);
  void host_action_prompt_end();
  void host_action_prompt_show();
  void host_prompt_do(const PromptReason reason, const char * const pstr, const char * const btn1=nullptr, const char * const btn2=nullptr);
  inline void host_prompt_open(const PromptReason reason, const char * const pstr, const char * const btn1=nullptr, const char * const btn2=nullptr) {
    if (host_prompt_reason == PROMPT_NOT_DEFINED) host_prompt_do(reason, pstr, btn1, btn2);
  }

  void filament_load_host_prompt();

#endif
