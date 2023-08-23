// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

#include "tapdances.h"

#include "g/keymap_combo.h"
#include "keycodes.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define xxxxxxx KC_NO
enum user_custom_keycodes {
    UNUSED              = QK_USER,
    CUT                 = LCTL(KC_X),
    COPY                = LCTL(KC_C),
    PASTE               = LCTL(KC_V),
    NEW_FILE            = LCTL(KC_N),
    SELECT_ALL          = LCTL(KC_A),
    UNDO                = LCTL(KC_Z),
    REDO                = LCTL(KC_Y),
    DUPLICATE_LINE      = LCTL(KC_D),
    COMMENT_OUT         = LCTL(KC_SLASH),
    SAVE                = LCTL(KC_S),
    PIPE                = S(KC_NONUS_BACKSLASH),
    HASH                = KC_NONUS_HASH,
    TILDE               = S(KC_NONUS_HASH),
    UNDERSCORE          = S(KC_MINUS),
    COLON               = S(KC_SCLN)
};

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
           _______,TD(TD_C_ESC),TD(TD_Y_DOUBLE_QUOTE),KC_D,_______,                                                 _______, KC_L,TD(TD_F_COMMA),TD(TD_U_QUOTE), _______,
LSFT_T(KC_R),LT(_LAYER_4_BRACKETS,KC_S),TD(TD_T_B_LT),TD(TD_H_P_LT),DB_TOGG,                 DB_TOGG,TD(TD_N_V_LT),TD(TD_A_DOT_LT),TD(TD_I_K),LSFT_T(KC_O),
           DT_PRNT,DT_UP,DT_DOWN,S(RSFT(KC_V)), QK_BOOT,                                                                      QK_BOOT, _______, _______, _______, _______,
                             LT(_LAYER_1,KC_W),TD(TD_M_G_LT),                                                          LT(_LAYER_1,KC_SPACE), LT(_LAYER_1,KC_E)
    ),

    [_LAYER_1] = LAYOUT(
      _______, KC_G, KC_B, KC_P, _______,                                                           _______,KC_G,KC_B,KC_P, _______,
      LSFT_T(KC_Z),KC_Q, KC_X, KC_J, _______,                                                       _______,KC_V, KC_PDOT,KC_K, LSFT_T(KC_SLSH),
      _______, _______, _______, _______, _______,                                                     _______, _______, _______, _______, _______,
                              KC_SCLN,KC_NONUS_BACKSLASH,                                                      KC_EQL, KC_MINS
    ),

    [_LAYER_2_NUM] = LAYOUT(
      _______,KC_ASTERISK, KC_EQUAL, _______, _______,                                                      _______,    KC_5,    KC_6,    KC_7, _______,
      LSFT_T(KC_SLASH),KC_MINS,KC_PLUS,_______, _______,                                                      _______,    KC_1,    KC_2,    KC_3, LSFT_T(KC_4),
      _______, _______, _______, _______, _______,                                                     _______, _______, _______, _______, _______,
                                KC_9,    _______,                                                      KC_8, KC_0
    ),

    [_LAYER_3_ARROWS_CTRL_C] = LAYOUT(
      _______,CUT, _______,NEW_FILE, _______,                                                   _______,  _______,    KC_UP,  TO(_LAYER_0), _______,
      SELECT_ALL,PASTE,_______,COPY, _______,                                                   _______,  KC_LEFT,  KC_DOWN, KC_RIGHT, _______,
      _______, _______, _______, _______, _______,                                                     _______, _______, _______, _______, _______,
                                UNDO,REDO,                                                      KC_LT, KC_GT
    ),

    [_LAYER_4_BRACKETS] = LAYOUT(
      _______, _______, _______, _______, _______,                                                   _______,  KC_LEFT_BRACKET,KC_RIGHT_BRACKET,  _______, _______,
      _______, _______,COMMENT_OUT,DUPLICATE_LINE, _______,                                                   _______,  KC_LEFT_PAREN,KC_RIGHT_PAREN, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE,
      _______, _______, _______, _______, _______,                                                     _______, _______, _______, _______, _______,
                                _______, _______,                                                      KC_COLON, KC_SEMICOLON
    ),

    [_LAYER_5_SYMBOLS] = LAYOUT(
      _______, KC_GRAVE, C_KC_AT, KC_PERCENT, _______,                                                   _______,  _______,COLON,KC_SCLN, _______,
      PIPE, HASH, KC_DOLLAR, KC_ASTERISK, _______,                                         _______,  _______,KC_EQUAL,UNDERSCORE,TILDE,
      _______, _______, _______, _______, _______,                                                     _______, _______, _______, _______, _______,
                                _______, _______,                                                      _______, _______
    ),

    [_LAYER_6_F_KEYS] = LAYOUT(
      _______, TO(_LAYER_0),KC_F2,KC_F5, _______,                                                   _______,  KC_F5, KC_F6, KC_F7, _______,
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

// void keyboard_post_init_user(void) {
//   // Customise these values to desired behaviour
//   debug_enable=false;
//   debug_matrix=false;
//   debug_keyboard=false;
//   //debug_mouse=true;
// }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n",
        keycode,
        record->event.key.col,
        record->event.key.row,
        record->event.pressed,
        record->event.time,
        record->tap.interrupted,
        record->tap.count);

    uprintf("Tapping term: %u\n",g_tapping_term);
#endif
  return true;
}
