#pragma once

#include QMK_KEYBOARD_H

#include "quantum.h"

enum layers {
  RSDT_0 = 0,
  RSDT_1,
  NUM,
  CNT
};

//if we need custom keycode support
// enum custom_keycodes {
//     // Direct dead keys ~`^
//     ENTER = QK_USER,
//     BACKSPACE,
//     TAB,
//     ESC
// };
