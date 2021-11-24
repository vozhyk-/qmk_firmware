#include QMK_KEYBOARD_H

#include "keymap_polish.h"
#include "keymap_dvp_polish.h"
#include "keymap_belarusian_latin.h"
#include "keymap_jp.h"

#undef LAYOUT
#define LAYOUT LAYOUT_2key

enum layers {
    _QWERTY,
    _DVP, // Programmer Dvorak
    _GAME,
    _NAV,
    _LANGSW,
    _DVP_PL,
    _PL,
    _DVP_BY,
    _JP,
    _SWAPH, // More swap-hand keys
    _SYM,
    _DVP_SYM,
    _MOARNAV
};

#define GAME TG(_GAME)
#define DVP TG(_DVP)
#define SWAPH TG(_SWAPH)

#define NAV MO(_NAV)
#define LANGSW OSL(_LANGSW)
#define SYM MO(_SYM)
#define DVP_SYM MO(_DVP_SYM)
#define MOARNAV MO(_MOARNAV)

#define W_BSPC LCTL(KC_BSPC)
#define W_DEL LCTL(KC_DEL)
#define W_LEFT LCTL(KC_LEFT)
#define W_RGHT LCTL(KC_RGHT)
#define P_UP LCTL(KC_UP)
#define P_DOWN LCTL(KC_DOWN)

#define SH_SPC SH_T(KC_SPC)
#define SH_ENT SH_T(KC_ENT)

// Close tab.
#define CLT LCTL(DP_W)
#define DVP_CLT LCTL(KC_W)
// Reopen tab.
#define REOPENT LCTL(LSFT(DP_T))

#define MICMUTE KC_F20

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
    DVP_AT,

    LSYM,
    DVPLSYM,

    L_NONE,
    L_PL,
    L_BY_LA,
    L_JP,

    PL_SZ,
    PL_CZ,
    PL_RZ,

    DP_PL_SZ,
    DP_PL_CZ,
    DP_PL_RZ,

    CTAB,     // Control-Tab with Control released after a timeout.
    RF12,     // Rapid-fire F12 to enter the Boot Menu on ThinkPads.
    CUTHOME,  // Cut to beginning-of-line.
    CUTEND,   // Cut to end-of-line.
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT( \
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_WFAV, KC_SLEP,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    CLT,             CTAB,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, \
    KC_LGUI, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_INS,          KC_BSPC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_LSFT, KC_X,    KC_C,    KC_V,    KC_B,                              KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    KC_LCTL, KC_LCTL, LANGSW,           KC_LALT, NAV,     KC_SPC ,         KC_ENT,  SYM,     LSYM,             LANGSW,  KC_RCTL, SH_MON \
  ),

  [_DVP] = LAYOUT( \
    DVP_AMP, DVP_LBR, DVP_LCB, DVP_RCB, DVP_LPR, _______, _______,         DVP_EQL, DVP_AST, DVP_RPR, DVP_PLS, DVP_RBR, DVP_EXC, DVP_HSH, \
    _______, KC_SCLN, KC_COMM, KC_DOT,  KC_P,    KC_Y,    DVP_CLT,         _______, KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH, \
    _______, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    _______,         _______, KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS, \
    _______, KC_LSFT, KC_Q,    KC_J,    KC_K,    KC_X,                              KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    _______, \
    _______, _______, _______,          _______, _______, _______,         _______, DVP_SYM, DVPLSYM,          _______, _______, _______  \
  ),

  [_GAME] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,            _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, KC_Y,            _______, _______, _______, _______, _______, _______, _______, \
    KC_BSLS, _______, _______, _______, _______, _______, KC_H,            _______, _______, _______, _______, _______, _______, _______, \
    _______, KC_Z,    _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______, \
    _______, _______, _______,          _______, _______, _______,         _______, _______, _______,          _______, _______, _______  \
  ),

  [_LANGSW] = LAYOUT(
    RESET,   _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, GAME,    \
    _______, _______, _______, _______, L_PL,    _______, REOPENT,         _______, _______, _______, _______, _______, _______, DVP,     \
    _______, _______, _______, _______, _______, _______, _______,         _______, _______, SWAPH,   _______, _______, _______, KC_APP, \
    _______, _______, _______, L_JP,    _______, _______,                           L_BY_LA, _______, _______, _______, _______, _______, \
    _______, _______, _______,          _______, MOARNAV, L_NONE,          _______, _______, _______,          _______, _______, _______ \
  ),

  [_DVP_PL] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, PL_CZ,   PL_CACU, PL_LSTR, _______, \
    _______, PL_AOGO, PL_OACU, PL_EOGO, _______, _______, _______,         _______, _______, PL_RZ,   _______, PL_NACU, PL_SZ,   PL_SACU, \
    _______, _______, _______, _______, _______, _______,                           _______, _______, _______, PL_ZACU, PL_ZDOT, _______, \
    _______, _______, _______,          _______, _______, _______,         _______, _______, _______,          _______, _______, _______  \
  ),

  [_PL] = LAYOUT(
    _______, _______,    _______,    _______,    _______, _______, _______, _______, _______, _______,  _______,  _______,    _______,    _______, \
    _______, _______,    _______,    _______,    _______, _______, _______, _______, _______, _______,  DP_PL_CZ, DP_PL_CACU, DP_PL_LSTR, _______, \
    _______, DP_PL_AOGO, DP_PL_OACU, DP_PL_EOGO, _______, _______, _______, _______, _______, DP_PL_RZ, _______,  DP_PL_NACU, DP_PL_SZ,   DP_PL_SACU, \
    _______, _______,    _______,    _______,    _______, _______,                   _______, _______,  _______,  DP_PL_ZACU, DP_PL_ZDOT, _______, \
    _______, _______,    _______,                _______, _______, _______, _______, _______, _______,            _______,    _______,    _______  \
  ),

  [_DVP_BY] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, BY_CCAR, BY_CACU, BY_LSTR, _______, \
    _______, _______, _______, _______, BY_UBRV, _______, _______,         _______, _______, _______, _______, BY_NACU, BY_SCAR, BY_SACU, \
    _______, _______, _______, _______, _______, _______,                           _______, _______, _______, BY_ZACU, BY_ZCAR, _______, \
    _______, _______, _______,          _______, _______, _______,         _______, _______, _______,          _______, _______, _______  \
  ),

  [_JP] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, JP_YEN,  _______,         _______, _______, _______, _______, _______, _______, JP_BSLS, \
    _______, _______, _______, _______, JP_ZKHK, _______, _______,         _______, _______, JP_KANA, _______, _______, _______, JP_UNDS, \
    _______, _______, _______, _______, _______, _______,                           _______, JP_HENK, _______, _______, _______, _______, \
    _______, _______, _______,          _______, _______, JP_MHEN,         _______, _______, _______,          _______, _______, _______  \
  ),

  [_SWAPH] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, KC_ENT,          _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______, \
    SH_MON,  _______, _______,          _______, _______, SH_SPC,          SH_ENT,  _______, _______,          _______, _______, _______ \
  ),

  [_NAV] = LAYOUT(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  RF12,    \
    _______, _______, _______, W_BSPC,  W_DEL,   _______, _______,         _______, KC_FIND, W_LEFT,  KC_UP,   W_RGHT,  _______, _______, \
    _______, KC_LSFT, _______, KC_BSPC, KC_DEL,  CUTEND,  KC_INS,          _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_RSFT, KC_UNDO, \
    _______, KC_LCTL, KC_CUT,  KC_COPY, KC_PSTE, KC_ESC,                            KC_END,  KC_ENT,  _______, _______, KC_RCTL, _______, \
    _______, _______, _______,          _______, _______, _______,         KC_SPC,  MOARNAV, _______,          _______, _______, _______ \
  ),

  [_SYM] = LAYOUT(
    _______, KC_1,    KC_1,    KC_3,    KC_4,    KC_6,    _______,         _______, KC_6,    _______, _______, _______, _______, _______, \
    _______, KC_TILD, KC_2,    KC_3,    KC_5,    KC_6,    _______,         _______, KC_6,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_RBRC, \
    KC_1,    KC_GRV,  KC_1,    KC_Z,    KC_4,    _______, _______,         _______, _______, KC_7,    _______, _______, KC_BSLS, KC_EQL, \
    _______, _______, KC_Z,    _______, _______, _______,                           _______, _______, _______, _______, KC_Z,    _______, \
    _______, _______, _______,          _______, MOARNAV, _______,         _______, _______, _______,          _______, _______, _______  \
  ),

  [_DVP_SYM] = LAYOUT(
    _______, DVP_AMP, DVP_AMP, DVP_LCB, DVP_RCB, DVP_EQL, _______,         _______, DVP_EQL, DVP_AST, _______, _______, _______, _______, \
    _______, KC_TILD, DVP_LBR, DVP_LCB, DVP_LPR, DVP_EQL, _______,         _______, DVP_EQL, DVP_RPR, DVP_PLS, DVP_RBR, DVP_EXC, DVP_AT,  \
    DVP_AMP, DVP_DLR, DVP_AMP, KC_QUOT, DVP_RCB, _______, _______,         _______, _______, DVP_AST, _______, _______, KC_BSLS, DVP_HSH, \
    _______, _______, KC_QUOT, _______, _______, _______,                           _______, _______, _______, _______, KC_QUOT, _______, \
    _______, _______, _______,          _______, MOARNAV, _______,         _______, _______, _______,          _______, _______, _______  \
  ),

  [_MOARNAV] = LAYOUT(
    RESET,   _______, _______, KC_BRID, KC_BRIU, _______, _______,         _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, MICMUTE, _______,         _______, _______, P_UP,    KC_PGUP, P_DOWN,  _______, _______, \
    _______, KC_MPLY, KC_MPRV, KC_MPLY, KC_MNXT, CUTHOME, _______,         _______, _______, _______, KC_PGDN, _______, KC_PSCR, _______, \
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

void press_or_release_code(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed)
        register_code16(keycode);
    else
        unregister_code16(keycode);
}

void process_momentary_layer_switch(uint8_t layer, keyrecord_t *record) {
    if (record->event.pressed)
        layer_on(layer);
    else
        layer_off(layer);
}

// Based on https://beta.docs.qmk.fm/using-qmk/advanced-keycodes/feature_macros#super-alt-tab
bool is_control_tab_active = false;
uint16_t control_tab_timer = 0;
#define CONTROL_TAB_TIME 1000

void process_control_tab(keyrecord_t *record) {
    if (!record->event.pressed) {
        unregister_code(KC_TAB);
        return;
    }

    if (!is_control_tab_active) {
        is_control_tab_active = true;
        register_code(KC_LCTL);
    }
    control_tab_timer = timer_read();
    register_code(KC_TAB);
}

void matrix_scan_control_tab(void) {
    if (!is_control_tab_active)
        return;

    if (timer_elapsed(control_tab_timer) > CONTROL_TAB_TIME) {
        unregister_code(KC_LCTL);
        is_control_tab_active = false;
    }
}

bool rapid_f12_pressed = false;
uint16_t rapid_f12_timer = 0;
#define RAPID_F12_TIME 50

void process_rapid_f12(keyrecord_t *record) {
    if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_F12));
        rapid_f12_timer = timer_read();
        rapid_f12_pressed = true;
    } else {
        rapid_f12_pressed = false;
    }
}

void matrix_scan_rapid_f12(void) {
    if (!rapid_f12_pressed)
        return;

    if (timer_elapsed(rapid_f12_timer) > RAPID_F12_TIME) {
        SEND_STRING(SS_TAP(X_F12));
        rapid_f12_timer = timer_read();
    }
}

enum lang {
    NONE,
    BY_LATIN,
    PL,
    JP
} lang = NONE;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == LSYM) {
        switch (lang) {
        case NONE:
        case BY_LATIN:
            press_or_release_code(KC_RALT, record);
            return false;
        case PL:
            process_momentary_layer_switch(_PL, record);
            return false;
        case JP:
            process_momentary_layer_switch(_JP, record);
            return false;
        }
    }

    if (keycode == DVPLSYM) {
        switch (lang) {
        case NONE:
            press_or_release_code(KC_RALT, record);
            return false;
        case BY_LATIN:
            process_momentary_layer_switch(_DVP_BY, record);
            return false;
        case PL:
            process_momentary_layer_switch(_DVP_PL, record);
            return false;
        case JP:
            process_momentary_layer_switch(_JP, record);
            return false;
        }
    }

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

    if (keycode == CTAB) {
        process_control_tab(record);
        return false;
    }

    if (keycode == RF12) {
        process_rapid_f12(record);
        return false;
    }

    if (!record->event.pressed)
        return true;

    switch (keycode) {
    case L_NONE:
        lang = NONE;
        return false;
    case L_BY_LA:
        lang = BY_LATIN;
        return false;
    case L_PL:
        lang = PL;
        return false;
    case L_JP:
        lang = JP;
        return false;

    // TODO: Make Shift+PL_SZ produce Sz, not SZ.
    case PL_SZ:
        SEND_STRING("sz");
        return false;
    case PL_CZ:
        SEND_STRING("cz");
        return false;
    case PL_RZ:
        SEND_STRING("rz");
        return false;

    // TODO: Make Shift+PL_SZ produce Sz, not SZ.
    case DP_PL_SZ:
        SEND_STRING(";/"); // interpreted as "sz" on dvp
        return false;
    case DP_PL_CZ:
        SEND_STRING("i/"); // interpreted as "cz" on dvp
        return false;
    case DP_PL_RZ:
        SEND_STRING("o/"); // interpreted as "rz" on dvp
        return false;

    case CUTHOME:
        SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_HOME) SS_UP(X_LSFT) SS_TAP(X_CUT));
        return false;
    case CUTEND:
        SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_END) SS_UP(X_LSFT) SS_TAP(X_CUT));
        return false;
    }

    return true;
}

void matrix_scan_user(void) {
    matrix_scan_control_tab();
    matrix_scan_rapid_f12();
}
