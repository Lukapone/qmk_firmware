#pragma once

#include QMK_KEYBOARD_H

#include "quantum.h"

enum layers {
  _LAYER_0 = 0,
  _LAYER_1,
  _LAYER_2_NUM,
  _LAYER_3_ARROWS_CTRL_C
};

//if we need custom keycode support
// enum custom_keycodes {
//     // Direct dead keys ~`^
//     ENTER = QK_USER,
//     BACKSPACE,
//     TAB,
//     ESC
// };
