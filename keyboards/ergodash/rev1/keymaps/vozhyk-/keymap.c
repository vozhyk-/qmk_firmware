#include QMK_KEYBOARD_H

#undef LAYOUT
#define LAYOUT LAYOUT_2key

#define _QWERTY 0
#define _NAV 1
#define _MOARNAV 2
#define _SYM 3

#define NAV MO(_NAV)
#define MOARNAV MO(_MOARNAV)
#define SYM MO(_SYM)

#define W_BSPC LCTL(KC_BSPC)
#define W_DEL LCTL(KC_DEL)
#define W_LEFT LCTL(KC_LEFT)
#define W_RGHT LCTL(KC_RGHT)
#define P_UP LCTL(KC_UP)
#define P_DOWN LCTL(KC_DOWN)

#define S_TAP_z LSFT_T(KC_Z)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT( \
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_BSLS,         KC_ESC , KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, \
    KC_LGUI, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_INS,          KC_BSPC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, S_TAP_z, KC_X,    KC_C,    KC_V,    KC_B,                              KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    KC_LCTL, KC_LCTL, _______,          KC_LALT, NAV,     KC_SPC ,         KC_ENT,  SYM,     KC_RALT,          _______, KC_LCTL, KC_RGHT \
  ),

  [_NAV] = LAYOUT(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
    _______, _______, _______, W_BSPC,  W_DEL,   _______, _______,         _______, _______, W_LEFT,  KC_UP,   W_RGHT,  _______, _______, \
    _______, KC_LSFT, _______, KC_BSPC, KC_DEL,  _______, _______,         _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_LSFT, _______, \
    _______, KC_LCTL, KC_CUT,  KC_COPY, KC_PSTE, KC_ESC,                            KC_END,  KC_ENT,  _______, _______, KC_LCTL, _______, \
    _______, _______, _______,          _______, _______, _______,         KC_SPC,  MOARNAV, _______,          _______, _______, _______ \
  ),

  [_SYM] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, \
    _______, KC_TILD, KC_1,    _______, KC_5,    _______, _______,         _______, _______, KC_8,    _______, _______, KC_EQL,  KC_BSLS, \
    _______, KC_GRV,  _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, KC_RBRC, KC_PIPE, \
    _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______, \
    _______, _______, _______,          _______, _______, _______,         _______, _______, _______,          _______, _______, _______  \
  ),

  [_MOARNAV] = LAYOUT(
    RESET,   _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,         _______, _______, P_UP,    KC_PGUP, P_DOWN,  _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, KC_PGDN, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______, \
    _______, _______, _______,          _______, _______, _______,         _______, _______, _______,          _______, _______, _______  \
  )
};
