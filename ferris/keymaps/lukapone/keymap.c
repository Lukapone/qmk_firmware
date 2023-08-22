// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

#include "tapdances.h"

#include "keycodes.h"
#include "g/keymap_combo.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define xxxxxxx KC_NO


// qmk config compile.keyboard=ferris/sweep compile.keymap=lukapone

//  \\wsl$\QMK\home\qmk\qmk_firmware
//  C:\Users\Lukas_PC\qmk_firmware\ferris_sweep_lukapone.hex

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
    * Base Layer: Modified RSTHD for some reason the thumb keys are swapped
    */
    // [RSDT_0] = LAYOUT(
    //        _______,    KC_C,    KC_Y,    KC_D, _______,                         _______, KC_L, KC_F, KC_U, _______,
    //   LSFT_T(KC_R),    KC_S, LT(CNT,KC_T), LT(NUM,KC_H), DB_TOGG,               DB_TOGG, LT(NUM,KC_N), LT(CNT,KC_A), KC_I, KC_O,
    //        _______, _______, _______, _______, QK_BOOT,                         QK_BOOT, _______, _______, _______, _______,
    //                          LT(RSDT_1,KC_SPACE),  LT(RSDT_1,KC_W),                         LT(RSDT_1,KC_M), LT(RSDT_1,KC_E)
    //                         // LT(RSDT_1,KC_W), KC_SPACE,                           KC_E, LT(RSDT_1,KC_M)
    // ),

    [_LAYER_0] = LAYOUT(
           _______,TD(TD_C_ESC),TD(TD_Y_DOUBLE_QUOTE),TD(TD_D_J),_______,                                                 _______, KC_L,TD(TD_F_COMMA),TD(TD_U_QUOTE), _______,
LSFT_T(KC_R),LT(_LAYER_4_BRACKETS,KC_S),TD(TD_T_B_LT),TD(TD_H_P_LT),DB_TOGG,                 DB_TOGG,TD(TD_N_V_LT),TD(TD_A_DOT_LT),TD(TD_I_K), KC_O,
           _______, _______, _______, _______, QK_BOOT,                                                                      QK_BOOT, _______, _______, _______, _______,
                             TD(TD_M_G_LT),  LT(_LAYER_1,KC_M),                                                          LT(_LAYER_1,KC_SPACE), LT(_LAYER_1,KC_E)
    ),

    [_LAYER_1] = LAYOUT(
      _______, KC_QUOT, KC_DLR, KC_PERC, _______,                                                      _______,    KC_G,    KC_B,    KC_P, _______,
      LSFT_T(KC_Z),    KC_Q, KC_X, KC_J, _______,                                                      _______,    KC_V, KC_PDOT,    KC_K, LSFT_T(KC_SLSH),
      _______, _______, _______, _______, _______,                                                     _______, _______, _______, _______, _______,
                              KC_SCLN,    KC_BSLS,                                                      KC_EQL, KC_MINS
    ),

    [_LAYER_2_NUM] = LAYOUT(
      _______,  KC_GRV, KC_DLR, KC_PERC, _______,                                                      _______,    KC_5,    KC_6,    KC_7, _______,
      LSFT_T(KC_Z),    KC_Q, KC_X, KC_J, _______,                                                      _______,    KC_1,    KC_2,    KC_3, LSFT_T(KC_4),
      _______, _______, _______, _______, _______,                                                     _______, _______, _______, _______, _______,
                                KC_9,    _______,                                                      KC_8, KC_0
    ),

    [_LAYER_3_ARROWS_CTRL_C] = LAYOUT(
      _______,  LCTL(KC_X), _______,LCTL(KC_N), _______,                                                   _______,  _______,    KC_UP,  _______, _______,
      LCTL(KC_A),LCTL(KC_V),_______,LCTL(KC_C), _______,                                                   _______,  KC_LEFT,  KC_DOWN, KC_RIGHT, _______,
      _______, _______, _______, _______, _______,                                                     _______, _______, _______, _______, _______,
                                LCTL(KC_Z), LCTL(KC_R),                                                      KC_LT, KC_GT
    ),

    [_LAYER_4_BRACKETS] = LAYOUT(
      _______, _______, _______, _______, _______,                                                   _______,  KC_LEFT_BRACKET,KC_RIGHT_BRACKET,  _______, _______,
      _______, _______, C(KC_SLASH), C(KC_D), _______,                                                   _______,  KC_LEFT_PAREN,KC_RIGHT_PAREN, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE,
      _______, _______, _______, _______, _______,                                                     _______, _______, _______, _______, _______,
                                _______, _______,                                                      KC_COLON, KC_SEMICOLON
    ),

    [_LAYER_5_SYMBOLS] = LAYOUT(
      _______, KC_AMPERSAND, C_KC_AT, KC_PERCENT, _______,                                                   _______,  _______,KC_CIRCUMFLEX,  KC_TILDE, _______,
      LSFT_T(KC_PIPE), KC_HASH, KC_DOLLAR, KC_ASTERISK, _______,                                         _______,  _______,KC_MINUS, KC_EQUAL, KC_GRAVE,
      _______, _______, _______, _______, _______,                                                     _______, _______, _______, _______, _______,
                                _______, _______,                                                      _______, _______
    ),

    [_LAYER_6_F_KEYS] = LAYOUT(
      _______, TO(_LAYER_0), _______, KC_F5, _______,                                                   _______,  KC_F5, KC_F6, KC_F7, _______,
      _______, _______, A(KC_ENTER), KC_F12, _______,                                                     _______,  KC_F1,KC_F2, KC_F3, KC_F4,
      _______, _______, _______, _______, _______,                                                     _______, _______, _______, _______, _______,
                                KC_F9, KC_F10,                                                      KC_F8, KC_F11
    )

};


//      [RSDT_0] = LAYOUT( /* QWERTY */
//     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,  KC_I,    KC_O,   KC_P,
//     KC_A,    KC_S,    KC_D,    KC_F,    KC_G,            KC_H,    KC_J,  KC_K,    KC_L,   KC_5,
//     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,            KC_N,    KC_M,  KC_2,    KC_3,   KC_4,
//                                     KC_0, KC_1,      KC_0, KC_1
//   )

//the finished function is called after the tap dance term TAPPING_TERM
tap_dance_action_t tap_dance_actions[] = {
    //left
    [TD_C_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_C, KC_ESC),
    [TD_Y_DOUBLE_QUOTE] = ACTION_TAP_DANCE_DOUBLE(KC_Y, C_KC_DOUBLE_QUOTE),
    [TD_D_J] = ACTION_TAP_DANCE_DOUBLE(KC_D, KC_J),

    [TD_T_B_LT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, t_b_lt_finished, t_b_lt_reset),
    [TD_H_P_LT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, h_p_lt_finished, h_p_lt_reset),

    [TD_M_G_LT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, m_g_lt_finished, m_g_lt_reset),
    //right
    [TD_F_COMMA] = ACTION_TAP_DANCE_DOUBLE(KC_F, KC_COMMA),
    [TD_U_QUOTE] = ACTION_TAP_DANCE_DOUBLE(KC_U, KC_QUOTE),

    [TD_N_V_LT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, n_v_lt_finished, n_v_lt_reset),
    [TD_A_DOT_LT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, a_dot_lt_finished, a_dot_lt_reset),
    [TD_I_K] = ACTION_TAP_DANCE_DOUBLE(KC_I, KC_K),
};


//what functions would be nice when working
//snipping tool: GUI -> Shift -> S

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  //debug_mouse=true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
  return true;
}
