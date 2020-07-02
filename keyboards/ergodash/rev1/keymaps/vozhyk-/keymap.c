#include QMK_KEYBOARD_H

#undef LAYOUT
#define LAYOUT LAYOUT_2key

enum layers {
    _QWERTY,
    _DVP, // Programmer Dvorak
    _GAME,
    _FLIP,
    _NAV,
    _SYM,
    _DVP_SYM,
    _MOARNAV
};

#define GAME TG(_GAME)
#define DVP TG(_DVP)
#define NAV MO(_NAV)
#define FLIP MO(_FLIP)
#define SYM MO(_SYM)
#define DVP_SYM MO(_DVP_SYM)
#define MOARNAV MO(_MOARNAV)

#define W_BSPC LCTL(KC_BSPC)
#define W_DEL LCTL(KC_DEL)
#define W_LEFT LCTL(KC_LEFT)
#define W_RGHT LCTL(KC_RGHT)
#define P_UP LCTL(KC_UP)
#define P_DOWN LCTL(KC_DOWN)

#define CTAB LCTL(KC_TAB)

#define MICMUTE KC_F20

#define S_TAP_z LSFT_T(KC_Z)
#define StapQUO LSFT_T(KC_QUOT)

enum custom_keycodes {
    DVP_DLR = SAFE_RANGE,
    DVP_AMP,
    DVP_LBR,
    DVP_LCB,
    DVP_RCB,
    DVP_LPR,
    DVP_EQL,
    DVP_AST,
    DVP_RPR,
    DVP_PLS,
    DVP_RBR,
    DVP_EXC,
    DVP_HSH,
    DVP_AT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT( \
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_WFAV, KC_SLEP,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______,         CTAB,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, \
    KC_LGUI, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_INS,          KC_BSPC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, S_TAP_z, KC_X,    KC_C,    KC_V,    KC_B,                              KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    KC_LCTL, KC_LCTL, _______,          KC_LALT, NAV,     KC_SPC ,         KC_ENT,  SYM,     KC_RALT,          _______, KC_RCTL, FLIP     \
  ),

  [_DVP] = LAYOUT( \
    DVP_AMP, DVP_LBR, DVP_LCB, DVP_RCB, DVP_LPR, _______, _______,         DVP_EQL, DVP_AST, DVP_RPR, DVP_PLS, DVP_RBR, DVP_EXC, DVP_HSH, \
    _______, KC_SCLN, KC_COMM, KC_DOT,  KC_P,    KC_Y,    _______,         _______, KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH, \
    _______, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    _______,         _______, KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS, \
    _______, StapQUO, KC_Q,    KC_J,    KC_K,    KC_X,                              KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    _______, \
    _______, _______, _______,          _______, _______, _______,         _______, DVP_SYM, _______,          _______, _______, _______  \
  ),

  [_FLIP] = LAYOUT(
    RESET,   _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, GAME,    \
    _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, DVP,     \
    _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, KC_APP,  \
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
    _______, _______, KC_2,    KC_3,    KC_4,    KC_6,    _______,         _______, KC_6,    KC_7,    _______, KC_MINS, _______, _______, \
    _______, KC_TILD, KC_1,    KC_4,    KC_5,    KC_6,    _______,         _______, KC_6,    KC_8,    KC_9,    KC_0,    KC_EQL,  KC_BSLS, \
    _______, KC_GRV,  _______, _______, _______, _______, _______,         _______, _______, KC_7,    _______, _______, KC_RBRC, KC_PIPE, \
    _______, _______, KC_Z,    _______, _______, _______,                           _______, _______, _______, _______, _______, _______, \
    _______, _______, _______,          _______, MOARNAV, _______,         _______, _______, _______,          _______, _______, _______  \
  ),

  [_DVP_SYM] = LAYOUT(
    _______, _______, DVP_LBR, DVP_LCB, DVP_RCB, DVP_EQL, _______,         _______, DVP_EQL, DVP_AST, _______, DVP_EXC, _______, _______, \
    _______, KC_TILD, DVP_AMP, DVP_RCB, DVP_LPR, DVP_EQL, _______,         _______, DVP_EQL, DVP_RPR, DVP_PLS, DVP_RBR, DVP_HSH, KC_BSLS, \
    _______, DVP_DLR, _______, _______, _______, _______, _______,         _______, _______, DVP_AST, _______, _______, DVP_AT,  KC_PIPE, \
    _______, _______, KC_QUOT, _______, _______, _______,                           _______, _______, _______, _______, _______, _______, \
    _______, _______, _______,          _______, MOARNAV, _______,         _______, _______, _______,          _______, _______, _______  \
  ),

  [_MOARNAV] = LAYOUT(
    RESET,   _______, _______, KC_BRID, KC_BRIU, _______, _______,         _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, MICMUTE, _______,         _______, _______, P_UP,    KC_PGUP, P_DOWN,  _______, _______, \
    _______, KC_MPLY, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,         _______, _______, _______, KC_PGDN, _______, _______, _______, \
    _______, _______, _______, KC_BRID, KC_BRIU, _______,                           _______, _______, _______, _______, _______, _______, \
    _______, _______, _______,          _______, _______, _______,         _______, _______, _______,          _______, _______, _______  \
  )
};

// If custom_keycode is pressed, send {un,}shifted_output depending on whether the Shift modifier is active.
// Returns true if the key event should be processed further.
// Inspired by:
// - ergodox_ez/keymaps/lukaus
// - https://www.reddit.com/r/olkb/comments/94zmyf/custom_keycode_when_key_is_hit_while_holding_shift/e3r38ng/
// Name inspired by the ShapeShifter Kaleidoscope plugin, which does something slightly different.
// TODO:
// - Don't release/press Shift multiple times unnecessarily.
// - Make autorepeat work with these keys?
bool process_shape_shifter(uint16_t custom_keycode, char unshifted_output, char shifted_output, uint16_t keycode, keyrecord_t *record) {
    if (keycode != custom_keycode)
        return true;

    if (!record->event.pressed)
        return false;

    bool left_shift_down = keyboard_report->mods & MOD_BIT(KC_LSHIFT);
    bool right_shift_down = keyboard_report->mods & MOD_BIT(KC_RSHIFT);

    if (left_shift_down)
        unregister_code(KC_LSHIFT);
    if (right_shift_down)
        unregister_code(KC_RSHIFT);

    if (left_shift_down || right_shift_down) {
        send_char(shifted_output);
    } else {
        send_char(unshifted_output);
    }

    if (left_shift_down)
        register_code(KC_LSHIFT);
    if (right_shift_down)
        register_code(KC_RSHIFT);

    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_shape_shifter(DVP_DLR, '$', '~', keycode, record))
        return false;
    if (!process_shape_shifter(DVP_AMP, '&', '%', keycode, record))
        return false;
    if (!process_shape_shifter(DVP_LBR, '[', '7', keycode, record))
        return false;
    if (!process_shape_shifter(DVP_LCB, '{', '5', keycode, record))
        return false;
    if (!process_shape_shifter(DVP_RCB, '}', '3', keycode, record))
        return false;
    if (!process_shape_shifter(DVP_LPR, '(', '1', keycode, record))
        return false;
    if (!process_shape_shifter(DVP_EQL, '=', '9', keycode, record))
        return false;
    if (!process_shape_shifter(DVP_AST, '*', '0', keycode, record))
        return false;
    if (!process_shape_shifter(DVP_RPR, ')', '2', keycode, record))
        return false;
    if (!process_shape_shifter(DVP_PLS, '+', '4', keycode, record))
        return false;
    if (!process_shape_shifter(DVP_RBR, ']', '6', keycode, record))
        return false;
    if (!process_shape_shifter(DVP_EXC, '!', '8', keycode, record))
        return false;
    if (!process_shape_shifter(DVP_HSH, '#', '`', keycode, record))
        return false;
    if (!process_shape_shifter(DVP_AT,  '@', '^', keycode, record))
        return false;

    return true;
}
