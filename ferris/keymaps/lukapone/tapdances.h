#pragma once

#include "keycodes.h"

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
    TD_Y_DOUBLE_QUOTE,
    TD_D_J,
    TD_T_B_LT,
    TD_H_P_LT,
    TD_M_G_LT,
    TD_F_COMMA,
    TD_U_QUOTE,
    TD_N_V_LT,
    TD_A_DOT_LT,
    TD_I_K,

};

void a_dot_lt_finished(tap_dance_state_t *state, void *user_data); //A -> . -> LT(3)
void a_dot_lt_reset(tap_dance_state_t *state, void *user_data);
void n_v_lt_finished(tap_dance_state_t *state, void *user_data); // N -> V -> LT(6)
void n_v_lt_reset(tap_dance_state_t *state, void *user_data);
void t_b_lt_finished(tap_dance_state_t *state, void *user_data); // T -> B -> LT(3)
void t_b_lt_reset(tap_dance_state_t *state, void *user_data);
void h_p_lt_finished(tap_dance_state_t *state, void *user_data); // H -> P -> LT(2)
void h_p_lt_reset(tap_dance_state_t *state, void *user_data);
void m_g_lt_finished(tap_dance_state_t *state, void *user_data); // M -> G -> LT(1)
void m_g_lt_reset(tap_dance_state_t *state, void *user_data);
void c_esc_lt_finished(tap_dance_state_t *state, void *user_data); // C -> ESC -> LALT()
void c_esc_lt_reset(tap_dance_state_t *state, void *user_data);
void u_quote_alt_finished(tap_dance_state_t *state, void *user_data); // U -> QUOTE -> LALT()
void u_quote_alt_reset(tap_dance_state_t *state, void *user_data);
