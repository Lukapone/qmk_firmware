// Useful tapdance functions!

//user
#include "tapdances.h"

/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 * For the third point, there does exist the 'DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */
int cur_dance (tap_dance_state_t *state) {
  if (state->count == 1) {
    // if (state->interrupted || !state->pressed)  return SINGLE_TAP;
    // //key has not been interrupted, but they key is still held. Means you want to send a 'HOLD'.
    // else return SINGLE_HOLD;
    if (!state->pressed)  return SINGLE_TAP;
    //key has not been interrupted, but they key is still held. Means you want to send a 'HOLD'.
    else return SINGLE_HOLD; //we want the ctrl + c work and not think it was th pressed
  }
  else if (state->count == 2) {
    /*
     * DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
     * action when hitting 'pp'. Suggested use case for this return value is when you want to send two
     * keystrokes of the key, and not the 'double tap' action/macro.
    */
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  //Assumes no one is trying to type the same letter three times (at least not quickly).
  //If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
  //an exception here to return a 'TRIPLE_SINGLE_TAP', and define that enum just like 'DOUBLE_SINGLE_TAP'
  if (state->count == 3) {
    if (state->interrupted || !state->pressed)  return TRIPLE_TAP;
    else return TRIPLE_HOLD;
  }
  else return 8; //magic number. At some point this method will expand to work for more presses
}

//instanalize an instance of 'tap' for the 'x' tap dance.
static tap xtap_state = {
  .is_press_action = true,
  .state = 0
};

// A -> . -> LT(3)
void a_dot_lt_finished (tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP:
      tap_code(KC_A);
      break;
    case SINGLE_HOLD:
      layer_on(_LAYER_3_ARROWS_CTRL_C);
      break;
    case DOUBLE_TAP:
            tap_code(KC_DOT);
      break;
  }
}

void a_dot_lt_reset (tap_dance_state_t *state, void *user_data) {
  //if the key was held down and now is released then switch off the layer
  if (xtap_state.state==SINGLE_HOLD) {
    layer_off(_LAYER_3_ARROWS_CTRL_C);
  }
  xtap_state.state = NONE;
}

// N -> V -> LT(6)
void n_v_lt_finished (tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP:
      tap_code(KC_N);
      break;
    case SINGLE_HOLD:
      layer_on(_LAYER_5_SYMBOLS);
      break;
    case DOUBLE_TAP:
            tap_code(KC_V);
      break;
  }
}

void n_v_lt_reset (tap_dance_state_t *state, void *user_data) {
  //if the key was held down and now is released then switch off the layer
  if (xtap_state.state==SINGLE_HOLD) {
    layer_off(_LAYER_5_SYMBOLS);
  }
  xtap_state.state = NONE;
}


// T -> B -> LT(6)
void t_b_lt_finished (tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP:
      tap_code(KC_T);
      break;
    case SINGLE_HOLD:
      layer_on(_LAYER_3_ARROWS_CTRL_C);
      break;
    case DOUBLE_TAP:
            tap_code(KC_B);
      break;
  }
}

void t_b_lt_reset (tap_dance_state_t *state, void *user_data) {
  //if the key was held down and now is released then switch off the layer
  if (xtap_state.state==SINGLE_HOLD) {
    layer_off(_LAYER_3_ARROWS_CTRL_C);
  }
  xtap_state.state = NONE;
}

// H -> P -> LT(2)
void h_p_lt_finished (tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP:
      tap_code(KC_H);
      break;
    case SINGLE_HOLD:
      layer_on(_LAYER_2_NUM);
      break;
    case DOUBLE_TAP:
            tap_code(KC_P);
      break;
  }
}

void h_p_lt_reset (tap_dance_state_t *state, void *user_data) {
  //if the key was held down and now is released then switch off the layer
  if (xtap_state.state==SINGLE_HOLD) {
    layer_off(_LAYER_2_NUM);
  }
  xtap_state.state = NONE;
}

// M -> G -> LT(1)
void m_g_lt_finished (tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP:
      tap_code(KC_M);
      break;
    case SINGLE_HOLD:
      layer_on(_LAYER_1);
      break;
    case DOUBLE_TAP:
            tap_code(KC_G);
      break;
  }
}

void m_g_lt_reset (tap_dance_state_t *state, void *user_data) {
  //if the key was held down and now is released then switch off the layer
  if (xtap_state.state==SINGLE_HOLD) {
    layer_off(_LAYER_1);
  }
  xtap_state.state = NONE;
}
