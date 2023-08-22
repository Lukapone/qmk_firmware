#pragma once

#include "process_tap_dance.h"
#include "action.h"

typedef struct {
  bool is_press_action;
  int state;
} tap;

enum {
  NONE = 0,
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  DOUBLE_SINGLE_TAP = 5, //send two single taps
  TRIPLE_TAP = 6,
  TRIPLE_HOLD = 7
};

// Tap Dance declarations
enum {
    TD_C_ESC,
    TD_F_COMMA,
    TD_Y_DOUBLE_QUOTE,
    TD_A_COMMA_LT
};

void a_comma_lt_finished(tap_dance_state_t *state, void *user_data); //A -> , -> LT(3)
void a_comma_lt_reset(tap_dance_state_t *state, void *user_data);
