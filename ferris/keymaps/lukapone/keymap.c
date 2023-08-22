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

//C:\Users\Lukas_PC\qmk_firmware\ferris_sweep_lukapone.hex

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
           _______,    TD(TD_C_ESC),TD(TD_Y_DOUBLE_QUOTE),KC_D, _______,                         _______, KC_L, TD(TD_F_COMMA), KC_U, _______,
      LSFT_T(KC_R),    KC_S, LT(_LAYER_3_ARROWS_CTRL_C,KC_T), LT(_LAYER_2_NUM,KC_H), DB_TOGG,       DB_TOGG, LT(_LAYER_2_NUM,KC_N), TD(TD_A_COMMA_LT), KC_I, KC_O,
           _______, _______, _______, _______, QK_BOOT,                                             QK_BOOT, _______, _______, _______, _______,
                             LT(_LAYER_1,KC_W),  LT(_LAYER_1,KC_M),                                  LT(_LAYER_1,KC_SPACE), LT(_LAYER_1,KC_E)
                            // LT(RSDT_1,KC_W), KC_SPACE,                                               KC_E, LT(RSDT_1,KC_M)
    ),

    [_LAYER_1] = LAYOUT(
      _______, KC_QUOT, KC_DLR, KC_PERC, _______,                                                      _______,    KC_G,    KC_B,    KC_P, _______,
      LSFT_T(KC_Z),    KC_Q, KC_X, KC_J, _______,                                                      _______,    KC_V, KC_PDOT,    KC_K, LSFT_T(KC_SLSH),
      _______, _______, _______, _______, _______,                                                     _______, _______, _______, _______, _______,
                              KC_SCLN,    KC_BSLS,                                                      KC_EQL, KC_MINS
                            //   KC_BSLS,    KC_SCLN,                                                      KC_MINS, KC_EQL
    ),

    [_LAYER_2_NUM] = LAYOUT(
      _______,  KC_GRV, KC_DLR, KC_PERC, _______,                                                      _______,    KC_5,    KC_6,    KC_7, _______,
      LSFT_T(KC_Z),    KC_Q, KC_X, KC_J, _______,                                                      _______,    KC_1,    KC_2,    KC_3, LSFT_T(   KC_4),
      _______, _______, _______, _______, _______,                                                     _______, _______, _______, _______, _______,
                                KC_9,    _______,                                                      KC_8, KC_0
                                // KC_9,    _______,                                                      KC_8, KC_0
    ),

    [_LAYER_3_ARROWS_CTRL_C] = LAYOUT(
      _______,  LCTL(KC_X), _______,LCTL(KC_N), _______,                                                   _______,  _______,    KC_UP,  _______, _______,
      LCTL(KC_A),LCTL(KC_V),_______,LCTL(KC_C), _______,                                                   _______,  KC_LEFT,  KC_DOWN, KC_RIGHT, _______,
      _______, _______, _______, _______, _______,                                                     _______, _______, _______, _______, _______,
                                LCTL(KC_Z), LCTL(KC_R),                                                      KC_LT, KC_GT
                                // LCTL(KC_R), LCTL(KC_Z),                                                      KC_GT, KC_LT
    )

};


//      [RSDT_0] = LAYOUT( /* QWERTY */
//     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,  KC_I,    KC_O,   KC_P,
//     KC_A,    KC_S,    KC_D,    KC_F,    KC_G,            KC_H,    KC_J,  KC_K,    KC_L,   KC_5,
//     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,            KC_N,    KC_M,  KC_2,    KC_3,   KC_4,
//                                     KC_0, KC_1,      KC_0, KC_1
//   )
