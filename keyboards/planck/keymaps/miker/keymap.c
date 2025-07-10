/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "keymap_dvorak.h"
#include "sendstring_dvorak.h"
#include "print.h"

enum planck_layers {
    _MY_DVORAK,
    _DVORAK,
    _QWERTY,
    _LOWER,
    _RAISE,
    _TMUX,
    _PLOVER,
    _ADJUST
};

enum planck_keycodes {
    MY_DVORAK = SAFE_RANGE,
    DVORAK,
    QWERTY,
    TMUX,
    BACKLIT,
    TMUX0,
    TMUX1,
    TMUX2,
    TMUX3,
    TMUX4,
    TMUX5,
    TMUX6,
    TMUX7,
    TMUX8,
    TMUX9,
    TMUX10,
    TMUX11,
    TMUX12,
    TMUX13,
    TMUX14,
    TMUX15,
    TMUX16,
    TMUX17,
    TMUX18
};

enum {
    TD_SHIFT_CAPS = 0,
    TD_COPYCUT,
    TD_DOTCOMMA,
    TD_UNDERSCORE
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define MAC_SLEEP LALT(LGUI(KC_SYSTEM_SLEEP))
#define MAC_CUT LGUI(DV_X)
#define MAC_COPY LGUI(DV_C)
#define MAC_PASTE LGUI(DV_V)
#define LINUX_CUT LCTL(DV_X)
#define LINUX_COPY LCTL(DV_C)
#define LINUX_PASTE LCTL(DV_V)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* My Dvorak
     * ,-----------------------------------------------------------------------------------.
     * | Tab  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Play | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Up   | Down |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_MY_DVORAK] = {
        {KC_TAB, DV_QUOT, DV_COMM, DV_DOT, DV_P, DV_Y, DV_F, DV_G, DV_C, DV_R, DV_L, KC_BSPC},
        {MT(MOD_MEH, KC_ESC), DV_A, DV_O, DV_E, DV_U, DV_I, DV_D, DV_H, DV_T, DV_N, DV_S, DV_SLSH},
        {TD(TD_SHIFT_CAPS), DV_SCLN, DV_Q, DV_J, DV_K, DV_X, DV_B, DV_M, DV_W, DV_V, DV_Z, KC_ENT},
        {LT(_TMUX, KC_MPLY), OSM(MOD_LCTL), OSM(MOD_LALT), KC_LGUI, TT(_LOWER), KC_SPC, KC_SPC, TT(_RAISE), KC_LEFT, KC_UP, KC_DOWN, KC_RGHT}
    },

    /* Dvorak
     * ,-----------------------------------------------------------------------------------.
     * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_DVORAK] = {
        {KC_TAB, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_BSPC},
        {KC_ESC, KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S, KC_SLSH},
        {KC_LSFT, KC_SCLN, KC_Q, KC_J, KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z, KC_ENT},
        {BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT}
    },

    /* Qwerty
     * ,-----------------------------------------------------------------------------------.
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_QWERTY] = {
        {KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC},
        {KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT},
        {KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT},
        {BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT}
    },

    /* Lower
     * ,-----------------------------------------------------------------------------------.
     * |   ~  |   !  |   @  |   #  |   $  |   %  | PgUp |   7  |   8  |   9  |  +   |  ?   |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |  F1  |  F2  |  F3  |  F4  |  F5  |PgDown|   4  |   5  |   6  |  -   |  -_  |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |  F6  |  F7  |  F8  |  F9  |  F10 |   `  |   1  |   2  |   3  |  *   |  \|  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |  F11 |  F12 |      |      |             |      |   0  | Home |  End | Bksp |
     * `-----------------------------------------------------------------------------------'
     */
    [_LOWER] = {
        {LSFT(KC_GRV), KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_PGUP, KC_7, KC_8, KC_9, DV_PLUS, LSFT(DV_SLSH)},
        {_______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_PGDN, KC_4, KC_5, KC_6, DV_MINS, TD(TD_UNDERSCORE)},
        {_______, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_GRV, KC_1, KC_2, KC_3, DV_ASTR, DV_BSLS},
        {_______, KC_F11, KC_F12, _______, _______, _______, _______, TD(TD_DOTCOMMA), KC_0, KC_HOME, KC_END, KC_BSPC}
    },

    /* Raise
     * ,-----------------------------------------------------------------------------------.
     * |   ~  |   !  |   @  |   #  |   $  |   %  |  ^   |   (  |  )   |  =   |  +   |  Del |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   {  |  }   |  &   |  -   |  \   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   [  |  ]   |  ^   |  *   |PRTSCR|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |Copy/P| Cut  | Cut  | Play |
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = {
        {LSFT(KC_GRV), KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, _______, KC_LPRN, KC_RPRN, DV_EQL, DV_PLUS, KC_DEL},
        {KC_DEL, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, DV_LCBR, DV_RCBR, KC_AMPERSAND, DV_MINS, KC_BSLS},
        {_______, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, DV_LBRC, DV_RBRC, KC_CIRCUMFLEX, DV_ASTR, KC_PRINT_SCREEN},
        {_______, _______, _______, _______, _______, _______, _______, _______, TD(TD_COPYCUT), LINUX_PASTE, KC_MUTE, MAC_SLEEP}
    },

    /* TMUX
     * ,-----------------------------------------------------------------------------------.
     * |  T0  |  T1  |  T2  |  T3  |  T4  |  T5  |  T6  |  T7  |  T12 |      |  T9  |      |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |  S1  |  S2  |  S3  |  S4  |  S5  |PGD   |      |  T11 |  T10 |  T18 |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |  SB  |  A1  |  A2  |  A3  |  A4  |  A4  |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |    KC_TRNS  |      |Copy/P| Cut  | Cut  | Play |
     * `-----------------------------------------------------------------------------------'
     */
    [_TMUX] = {
        {TMUX0, TMUX1, TMUX2, TMUX3, TMUX4, TMUX5, TMUX6, TMUX7, TMUX12, _______, TMUX9, _______},
        {_______, LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5), KC_PGDN, _______, TMUX11, TMUX10, TMUX18, _______},
        {LSFT(DV_B), LALT(KC_1), LALT(KC_2), LALT(KC_3), LALT(KC_4), LALT(KC_5), _______, _______, _______, _______, _______, _______},
        {_______, _______, _______, _______, _______, KC_TRNS, _______, _______, _______, _______, _______, _______}
    },

    /* Plover layer (http://opensteno.org)
     * ,-----------------------------------------------------------------------------------.
     * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_PLOVER] = {
        {KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1},
        {XXXXXXX, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC},
        {XXXXXXX, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT},
        {_______, XXXXXXX, XXXXXXX, KC_C, KC_V, XXXXXXX, XXXXXXX, KC_N, KC_M, XXXXXXX, XXXXXXX, XXXXXXX}
    },

    /* Adjust (Lower + Raise)
     * ,-----------------------------------------------------------------------------------.
     * |Sleep | Reset|      |      |      |      |      |      |      |      |      |Qwerty|
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |      |      |Aud on|Audoff|AGnorm|AGswap|      |      |      |      |Dvr+MY|
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |Scrn+ |Scrn- |      |Dvorak|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      | Vol+ | Vol- | Mouse|Plover|
     * `-----------------------------------------------------------------------------------'
     */
    [_ADJUST] = {
        {MAC_SLEEP, QK_BOOT, QK_DEBUG_TOGGLE, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, QWERTY},
        {KC_SYSTEM_SLEEP, _______, _______, AU_ON, AU_OFF, AG_NORM, AG_SWAP, _______, _______, _______, _______, MY_DVORAK},
        {_______, _______, _______, MU_ON, MU_OFF, MI_ON, MI_OFF, _______, KC_SCRL, KC_PAUS, _______, DVORAK},
        {_______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______}
    }
};

// Tap dance state and functions
typedef struct {
    bool is_press_action;
    uint8_t state;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD
};

static tap shift_caps_tap_state = {.is_press_action = true, .state = 0};
static tap copy_cut_tap_state = {.is_press_action = true, .state = 0};
static tap dot_comma_tap_state = {.is_press_action = true, .state = 0};
static tap minus_underscore_tap_state = {.is_press_action = true, .state = 0};

uint8_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return SINGLE_TAP;
        return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (!state->pressed) return DOUBLE_TAP;
        return DOUBLE_HOLD;
    }
    return 0; // Default for unhandled cases
}

void shift_caps_finished(tap_dance_state_t *state, void *user_data) {
    shift_caps_tap_state.state = cur_dance(state);
    switch (shift_caps_tap_state.state) {
        case SINGLE_TAP:
        case SINGLE_HOLD:
            register_code(KC_LSFT);
            break;
        case DOUBLE_TAP:
        case DOUBLE_HOLD:
            register_code(KC_CAPS);
            break;
    }
}

void shift_caps_reset(tap_dance_state_t *state, void *user_data) {
    switch (shift_caps_tap_state.state) {
        case SINGLE_TAP:
        case SINGLE_HOLD:
            unregister_code(KC_LSFT);
            break;
        case DOUBLE_TAP:
        case DOUBLE_HOLD:
            unregister_code(KC_CAPS);
            break;
    }
    shift_caps_tap_state.state = 0;
}

void copy_cut_finished(tap_dance_state_t *state, void *user_data) {
    copy_cut_tap_state.state = cur_dance(state);
    switch (copy_cut_tap_state.state) {
        case SINGLE_TAP:
            register_code(KC_LCTL);
            register_code(DV_C);
            break;
        case DOUBLE_TAP:
            register_code(KC_LCTL);
            register_code(DV_X);
            break;
    }
}

void copy_cut_reset(tap_dance_state_t *state, void *user_data) {
    switch (copy_cut_tap_state.state) {
        case SINGLE_TAP:
            unregister_code(DV_C);
            unregister_code(KC_LCTL);
            break;
        case DOUBLE_TAP:
            unregister_code(DV_X);
            unregister_code(KC_LCTL);
            break;
    }
    copy_cut_tap_state.state = 0;
}

void dot_comma_finished(tap_dance_state_t *state, void *user_data) {
    dot_comma_tap_state.state = cur_dance(state);
    switch (dot_comma_tap_state.state) {
        case SINGLE_TAP:
            register_code(DV_DOT);
            break;
        case DOUBLE_TAP:
            register_code(DV_COMM);
            break;
    }
}

void dot_comma_reset(tap_dance_state_t *state, void *user_data) {
    switch (dot_comma_tap_state.state) {
        case SINGLE_TAP:
            unregister_code(DV_DOT);
            break;
        case DOUBLE_TAP:
            unregister_code(DV_COMM);
            break;
    }
    dot_comma_tap_state.state = 0;
}

void minus_underscore_finished(tap_dance_state_t *state, void *user_data) {
    minus_underscore_tap_state.state = cur_dance(state);
    switch (minus_underscore_tap_state.state) {
        case SINGLE_TAP:
            register_code(DV_MINS);
            break;
        case DOUBLE_TAP:
            register_code(KC_LSFT);
            register_code(DV_MINS);
            break;
    }
}

void minus_underscore_reset(tap_dance_state_t *state, void *user_data) {
    switch (minus_underscore_tap_state.state) {
        case SINGLE_TAP:
            unregister_code(DV_MINS);
            break;
        case DOUBLE_TAP:
            unregister_code(DV_MINS);
            unregister_code(KC_LSFT);
            break;
    }
    minus_underscore_tap_state.state = 0;
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_SHIFT_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, shift_caps_finished, shift_caps_reset),
    [TD_COPYCUT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, copy_cut_finished, copy_cut_reset),
    [TD_DOTCOMMA] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dot_comma_finished, dot_comma_reset),
    [TD_UNDERSCORE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, minus_underscore_finished, minus_underscore_reset)
};

bool send_string_if_keydown(keyrecord_t *record, const char *s) {
    if (record->event.pressed) {
        send_string(s);
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                print("mode just switched to qwerty\n");
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case MY_DVORAK:
            if (record->event.pressed) {
                print("mode just switched to my dvorak\n");
                set_single_persistent_default_layer(_MY_DVORAK);
            }
            return false;
        case DVORAK:
            if (record->event.pressed) {
                print("mode just switched to dvorak\n");
                set_single_persistent_default_layer(_DVORAK);
            }
            return false;
        case BACKLIT:
            if (record->event.pressed) {
#ifdef BACKLIGHT_ENABLE
                backlight_step();
#endif
            }
            return false;
        case KC_ESC:
            if (record->event.pressed) {
                bool queue = true;
                if ((get_oneshot_mods()) && !has_oneshot_mods_timed_out()) {
                    clear_oneshot_mods();
                    queue = false;
                }
                return queue;
            }
        case TMUX0:
            send_string_if_keydown(record, SS_LCTL("a") SS_TAP(X_0));
            break;
        case TMUX1:
            send_string_if_keydown(record, SS_LCTL("a") SS_TAP(X_1));
            break;
        case TMUX2:
            send_string_if_keydown(record, SS_LCTL("a") SS_TAP(X_2));
            break;
        case TMUX3:
            send_string_if_keydown(record, SS_LCTL("a") SS_TAP(X_3));
            break;
        case TMUX4:
            send_string_if_keydown(record, SS_LCTL("a") SS_TAP(X_4));
            break;
        case TMUX5:
            send_string_if_keydown(record, SS_LCTL("a") SS_TAP(X_5));
            break;
        case TMUX6:
            send_string_if_keydown(record, SS_LCTL("a") SS_TAP(X_6));
            break;
        case TMUX7:
            send_string_if_keydown(record, SS_LCTL("a") SS_TAP(X_7));
            break;
        case TMUX8:
            send_string_if_keydown(record, SS_LCTL("a") SS_TAP(X_8));
            break;
        case TMUX9:
            send_string_if_keydown(record, SS_LCTL("a") SS_DELAY(100) SS_TAP(X_P));
            break;
        case TMUX10:
            send_string_if_keydown(record, SS_LCTL("a") SS_DELAY(100) SS_TAP(X_L));
            break;
        case TMUX11:
            send_string_if_keydown(record, SS_LCTL("a") SS_DELAY(100) SS_TAP(X_R));
            break;
        case TMUX12:
            send_string_if_keydown(record, SS_LCTL("a") SS_DELAY(100) SS_TAP(X_I));
            break;
        case TMUX13:
            send_string_if_keydown(record, SS_LCTL("a") SS_DELAY(100) SS_TAP(X_D));
            break;
        case TMUX14:
            send_string_if_keydown(record, SS_LCTL("a") SS_DELAY(100) SS_TAP(X_E));
            break;
        case TMUX15:
            send_string_if_keydown(record, SS_LCTL("a") SS_DELAY(100) SS_TAP(X_U));
            break;
        case TMUX16:
            send_string_if_keydown(record, SS_LCTL("a") SS_DELAY(100) SS_TAP(X_O));
            break;
        case TMUX17:
            send_string_if_keydown(record, SS_LCTL("a") SS_DELAY(100) SS_TAP(X_F));
            break;
        case TMUX18:
            send_string_if_keydown(record, SS_LCTL("a") SS_DELAY(100) SS_TAP(X_SCLN));
            break;
    }
    return true;
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
        case RAISE:
        case LOWER:
            return false;
        default:
            return true;
    }
}
