#include QMK_KEYBOARD_H

#undef LAYOUT
#define LAYOUT LAYOUT_2key

enum layers {
    _QWERTY,
    _GAME,
    _FLIP,
    _NAV,
    _MOARNAV,
    _SYM
};

#define GAME TG(_GAME)
#define NAV MO(_NAV)
#define FLIP MO(_FLIP)
#define MOARNAV MO(_MOARNAV)
#define SYM MO(_SYM)

#define W_BSPC LCTL(KC_BSPC)
#define W_DEL LCTL(KC_DEL)
#define W_LEFT LCTL(KC_LEFT)
#define W_RGHT LCTL(KC_RGHT)
#define P_UP LCTL(KC_UP)
#define P_DOWN LCTL(KC_DOWN)

#define MICMUTE KC_F20

#define S_TAP_z LSFT_T(KC_Z)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT( \
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_WFAV, KC_SLEP,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_BSLS,         KC_ESC , KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, \
    KC_LGUI, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_INS,          KC_BSPC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, S_TAP_z, KC_X,    KC_C,    KC_V,    KC_B,                              KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    KC_LCTL, KC_LCTL, _______,          KC_LALT, NAV,     KC_SPC ,         KC_ENT,  SYM,     KC_RALT,          _______, KC_RCTL, FLIP     \
  ),

  [_FLIP] = LAYOUT(
    RESET,   _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, GAME,    \
    _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______, \
    _______, _______, _______,          _______, SYM,     _______,         KC_SPC,  NAV,     _______,          _______, _______, _______ \
  ),

  [_GAME] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,            _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, KC_Y,            _______, _______, _______, _______, _______, _______, _______, \
    KC_BSLS, _______, _______, _______, _______, _______, KC_H,            _______, _______, _______, _______, _______, _______, _______, \
    _______, KC_Z,    _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______, \
    _______, _______, _______,          _______, _______, _______,         _______, _______, _______,          _______, _______, _______  \
  ),

  [_NAV] = LAYOUT(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
    _______, _______, _______, W_BSPC,  W_DEL,   _______, _______,         _______, _______, W_LEFT,  KC_UP,   W_RGHT,  _______, _______, \
    _______, KC_LSFT, _______, KC_BSPC, KC_DEL,  _______, _______,         _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_RSFT, _______, \
    _______, KC_LCTL, KC_CUT,  KC_COPY, KC_PSTE, KC_ESC,                            KC_END,  KC_ENT,  _______, _______, KC_RCTL, _______, \
    _______, _______, _______,          _______, _______, _______,         KC_SPC,  MOARNAV, _______,          _______, _______, _______ \
  ),

  [_SYM] = LAYOUT(
    _______, _______, KC_2,    KC_3,    KC_4,    KC_6,    _______,         _______, KC_6,    KC_7,    _______, _______, _______, _______, \
    _______, KC_TILD, KC_1,    _______, KC_5,    KC_6,    _______,         _______, KC_6,    KC_8,    _______, _______, KC_EQL,  KC_BSLS, \
    _______, KC_GRV,  _______, _______, _______, _______, _______,         _______, _______, KC_7,    _______, _______, KC_RBRC, KC_PIPE, \
    _______, _______, KC_Z,    _______, _______, _______,                           _______, _______, _______, _______, _______, _______, \
    _______, _______, _______,          _______, _______, _______,         _______, _______, _______,          _______, _______, _______  \
  ),

  [_MOARNAV] = LAYOUT(
    RESET,   _______, _______, KC_BRID, KC_BRIU, _______, _______,         _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, MICMUTE, _______,         _______, _______, P_UP,    KC_PGUP, P_DOWN,  _______, _______, \
    _______, KC_MPLY, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,         _______, _______, _______, KC_PGDN, _______, _______, _______, \
    _______, _______, _______, KC_BRID, KC_BRIU, _______,                           _______, _______, _______, _______, _______, _______, \
    _______, _______, _______,          _______, _______, _______,         _______, _______, _______,          _______, _______, _______  \
  )
};
