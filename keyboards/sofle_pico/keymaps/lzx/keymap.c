// Copyright 2024 Ryan Neff (@JellyTitan)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "keycodes.h"
#include QMK_KEYBOARD_H

enum sofle_layers {
    _QWERTY,
    _SYMBOL,
    _DIRECTION,
    _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
        /*
        * QWERTY
        * ,-----------------------------------------.                    ,-----------------------------------------.
        * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
        * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
        * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
        * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
        * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
        * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
        * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
        * `-----------------------------------------/       /     \      \-----------------------------------------'
        *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
        *            |      |      |      |      |/       /         \      \ |      |      |      |      |
        *            `----------------------------------'           '------''---------------------------'
        */

        [_QWERTY] = LAYOUT(
        KC_ESC,   KC_1,   KC_2,    KC_3,          KC_4,    KC_5,                                    KC_6,          KC_7,         KC_8,    KC_9,       KC_0,    KC_BSPC,
        KC_TAB,   KC_Q,   KC_W,    KC_E,          KC_R,    KC_T,                                    KC_Y,          KC_U,         KC_I,    KC_O,       KC_P,    KC_NUBS,
        LT(_DIRECTION, KC_RCTL),    KC_A,   KC_S,    KC_D,          KC_F,    KC_G,                                    KC_H,          KC_J,         KC_K,    KC_L,       KC_SCLN, KC_ENT,
        KC_LSFT,  KC_Z,   KC_X,    KC_C,          KC_V,    KC_B,    KC_B,                  KC_NO,   KC_N,          KC_M,         KC_COMM, KC_DOT,     KC_SLSH, KC_RSFT,
                          KC_LCTL, MO(_ADJUST),   KC_LGUI, KC_LALT, LCTL_T(KC_SPC),        KC_SPC , MO(_SYMBOL),   MO(_DIRECTION),   KC_NO,   MO(_ADJUST)
        ),
        /* SYMBOL
        * ,-----------------------------------------.                    ,-----------------------------------------.
        * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
        * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
        * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
        * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
        * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
        * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
        * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
        * `-----------------------------------------/       /     \      \-----------------------------------------'
        *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
        *            |      |      |      |      |/       /         \      \ |      |      |      |      |
        *            `----------------------------------'           '------''---------------------------'
        */
        [_SYMBOL] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,          KC_F3,      KC_F4,          KC_F5,                           KC_F6,   KC_F7,          KC_F8,      KC_F9,        KC_F10,  KC_BSPC,
        KC_GRV,  _______, KC_LBRC,        LSFT(KC_9), LSFT(KC_LBRC),  _______,                         _______, LSFT(KC_RBRC),  LSFT(KC_0), KC_RBRC,      _______, KC_BSLS,
        _______, _______, LSFT(KC_COMMA), KC_QUOTE,   KC_MINUS,       KC_NO,                           _______, KC_EQUAL,       KC_QUOTE,   LSFT(KC_DOT), _______, KC_F11,
        _______, _______, _______,        _______,    LSFT(KC_MINUS), KC_NO,   _______,       _______, _______, LSFT(KC_EQUAL), _______,    _______,      _______, KC_F12,
                          _______,        _______,    _______,        _______, _______,       _______, _______, _______, _______, _______
        ),
        /* DIRECTION
        * ,----------------------------------------.                    ,-----------------------------------------.
        * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
        * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
        * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
        * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
        * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |
        * |------+------+------+------+------+------|  MUTE  |    |       |------+------+------+------+------+------|
        * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
        * `-----------------------------------------/       /     \      \-----------------------------------------'
        *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
        *            |      |      |      |      |/       /         \      \ |      |      |      |      |
        *            `----------------------------------'           '------''---------------------------'
        */
        [_DIRECTION] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,                           KC_F6,    KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_DEL,
        XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX,  XXXXXXX,                       XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX,                       KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT, XXXXXXX,  KC_F11,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_F12,
                          XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX
        ),
        /* ADJUST
        * ,-----------------------------------------.                    ,-----------------------------------------.
        * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
        * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
        * |QK_BOOT|     |      |      |      |      |                    |      |      |      |      |      |      |
        * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
        * |      |      |MACWIN|      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
        * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
        * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
        * `-----------------------------------------/       /     \      \-----------------------------------------'
        *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
        *            |      |      |      |      |/       /         \      \ |      |      |      |      |
        *            `----------------------------------'           '------''---------------------------'
        */
        [_ADJUST] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,                           KC_F6,    KC_F7,   KC_F8,   KC_F9,  KC_F10,  XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX,                       XXXXXXX, XXXXXXX, UG_TOGG, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, XXXXXXX, QK_BOOT, KC_B,     QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
        )
    // clang-format on
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [1] = {ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [2] = {ENCODER_CCW_CW(_______, _______)},
    [3] = {ENCODER_CCW_CW(_______, _______)},
};
#endif

#ifdef OLED_ENABLE
bool render_status(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("QWERTY\n"), false);
            break;
        case _SYMBOL:
            oled_write_P(PSTR("LOWER\n"), false);
            break;
        case _DIRECTION:
            oled_write_P(PSTR("RAISE\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("ADJUST\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    return false;
}

static void render_logo(void) {
    // clang-format off
    static const char PROGMEM sofle_pico_logo[] = {
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x0c, 0x3c, 0x00, 0x00, 0x0c, 0x3c, 0x00,
        0x00, 0xfc, 0xfc, 0x00, 0x00, 0xfc, 0xfc, 0x00, 0x00, 0xff, 0xf0, 0x00, 0x00, 0xff, 0xf0, 0x00,
        0x03, 0x03, 0xf0, 0x00, 0x03, 0x03, 0xf0, 0x00, 0x00, 0x33, 0xc0, 0x00, 0x00, 0x33, 0xc0, 0x00,
        0xf0, 0x3f, 0xc0, 0x00, 0xf0, 0x3f, 0xc0, 0x00, 0xc3, 0x3f, 0xc0, 0x00, 0xc3, 0x3f, 0xc0, 0x00,
        0xcf, 0x3f, 0xf0, 0x00, 0xcf, 0x3f, 0xf0, 0x00, 0x0f, 0xcf, 0xff, 0xc0, 0x0f, 0xcf, 0xff, 0xc0,
        0xcf, 0xff, 0xff, 0xc0, 0xcf, 0xff, 0xff, 0xc0, 0x03, 0xff, 0xc0, 0xc0, 0x03, 0xff, 0xc0, 0xe0,
        0x03, 0xff, 0xff, 0xc0, 0x03, 0xff, 0xff, 0xc0, 0x00, 0xff, 0xcf, 0xc0, 0x00, 0xff, 0xcf, 0xc0,
        0x00, 0xff, 0x0c, 0x00, 0x00, 0xff, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    // clang-format on
    oled_write_raw_P(sofle_pico_logo, sizeof(sofle_pico_logo));
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_logo(); // Renders a static logo
        // render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_logo(); // Renders a static logo
        // oled_scroll_left(); // Turns on scrolling
    }
    return false;
}

#endif
