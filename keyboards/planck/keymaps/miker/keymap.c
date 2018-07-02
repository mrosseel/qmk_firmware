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

#include "planck.h"
#include "action_layer.h"
#include "keymap_dvorak.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _MY_DVORAK,
  //_DVORAK_TM2030,
  _DVORAK,
  _QWERTY,
  // _COLEMAK,
  _LOWER,
  _RAISE,
  _TMUX,
  _PLOVER,
  _ADJUST,
  _MOUSE
};

enum planck_keycodes {
  MY_DVORAK = SAFE_RANGE,
  //DVORAK_TM2030 = SAFE_RANGE,
  DVORAK,
  // COLEMAK,
  QWERTY,
  PLOVER,
  TMUX,
  BACKLIT,
  EXT_PLV,
  MOUSE
};

/* Tap Dance keys */
enum {
  TD_SHIFT_CAPS = 0,
  TD_COPYPASTE,
  TD_LAYER_3,
  TD_DOUBLE,
  TD_LAYER_1
};

/* Fn keys */
enum {
  F_BSE = 0,
  F_HUN,
  F_GUI,
  F_SFT,
  F_ALT,
  F_CTRL,
  F_LOWER,
  F_RAISE
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define MAC_SLEEP LALT(LGUI(KC_SYSTEM_SLEEP))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* My Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Play | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Up   | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_MY_DVORAK] = {
  {KC_TAB,  DV_QUOT, DV_COMM, DV_DOT,  DV_P,    DV_Y,    DV_F,    DV_G,    DV_C,    DV_R,    DV_L,    KC_BSPC},
  {KC_ESC,  DV_A,    DV_O,    DV_E,    DV_U,    DV_I,    DV_D,    DV_H,    DV_T,    DV_N,    DV_S,    DV_SLSH},
  {F(F_SFT), DV_SCLN, DV_Q,    DV_J,    DV_K,    DV_X,    DV_B,    DV_M,    DV_W,    DV_V,    DV_Z,    KC_ENT },
  {KC_MPLY, F(F_CTRL), F(F_ALT), KC_LGUI, TT(_LOWER),   LT(_TMUX, KC_SPC),KC_SPC,  TT(_RAISE),   KC_LEFT, KC_UP, KC_DOWN, KC_RGHT}
},

  /* TM2030 Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  | Bksp |   F  |   G  |   C  |   R  |  L   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |Enter |   D  |   H  |   T  |   N  |  S   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |  /   |   B  |   M  |   W  |   V  |  Z   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Play | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'

[_DVORAK_TM2030] = {
  {KC_TAB,    KC_QUOT,   KC_COMM,  KC_DOT,  KC_P,       KC_Y,               KC_BSPC, KC_F,        KC_G,    KC_C,    KC_R,    KC_L},
  {KC_ESC,    KC_A,      KC_O,     KC_E,    KC_U,       KC_I,               KC_ENT,  KC_D,        KC_H,    KC_T,    KC_N,    KC_S},
  {F(F_SFT),  KC_SCLN,   KC_Q,     KC_J,    KC_K,       KC_X,               KC_SLSH, KC_B,        KC_M,    KC_W,    KC_V,    KC_Z},
  {KC_MPLY,   F(F_CTRL), F(F_ALT), KC_LGUI, LOWER, LT(_TMUX, KC_SPC),  KC_SPC,  RAISE,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},
*/
/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  | PgUp |   1  |   2  |   3  |  +   | /?   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |PgDown|   4  |   5  |   6  |  -   |  -_  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |   7  |   8  |   9  |  *   |  \|  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |   0  | Home |  End | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {DV_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,  KC_PGUP,        KC_1,    KC_2,     KC_3,     KC_KP_PLUS,     DV_SLSH},
  {_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_PGDN,        KC_4,    KC_5,     KC_6,     KC_KP_MINUS,    DV_MINS},
  {_______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   LSFT(KC_NUHS),  KC_7,    KC_8,     KC_9,     KC_KP_ASTERISK, DV_BSLS},
  {_______, KC_F11,  KC_F12,  _______, _______, _______,  _______,        _______, KC_0,     KC_HOME,  KC_END,         KC_END}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |  ^   |   (  |  )   |  =   |  +   |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   {  |  }   |      |   -  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   [  |  ]   |      |   *  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Copy | Paste|Cut   | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,  _______,    KC_LPRN,  KC_RPRN, KC_KP_EQUAL , KC_KP_PLUS,    KC_DEL},
  {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,       DV_LCBR,  DV_RCBR, KC_NO    , KC_KP_MINUS,    KC_BSLS},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,      DV_LBRC,  DV_RBRC, KC_NO    , KC_KP_ASTERISK, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______,        TD(1), KC_PASTE, KC_CUT, KC_FIND}
},



// most macros will switch tmux screens
// two macros are for vi's save/quit at 'w' and 'q'
[_TMUX] = {
  { _______, M(14),   M(13),   _______, _______, _______, _______, _______, _______, _______,    M(11),   _______ },
  { M(0),    M(1),    M(2),    M(3),    M(4),    M(5),    M(6),    M(7),    M(8),    M(9),       _______, _______ },
  { _______, _______, _______, M(12),   _______, _______, M(10),      _______, _______, _______, _______, _______ },
  { _______, _______, _______, _______, _______, KC_TRNS,    _______, _______, _______, _______, _______, _______ }
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
  {KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   },
  {XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC},
  {XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX}
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
  {MAC_SLEEP, RESET,   DEBUG,    RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD,        QWERTY},
  {KC_SYSTEM_SLEEP, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______,  _______, _______, _______,  MY_DVORAK},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, KC_SLCK, KC_PAUS, _______,           DVORAK},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, MOUSE,             PLOVER}
},

/* Mouse
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |Click1|Click3|Click2|      |      |MouseL|MouseD|MouseU|MouseR|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |Accel0|Accel1|Accel2|      |      |ScrllL|ScrllD|ScrllU|ScrllR|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = {
  { XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  { XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2, XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX},
  { XXXXXXX, XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX, XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX},
  { _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX}
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
  {KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC},
  {KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH},
  {KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT },
  {BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
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
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'

[_COLEMAK] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC},
  {KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},
 */

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'

[_LOWER] = {
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_BSPC, KC_CIRC, KC_AMPR,        KC_ASTR,        KC_LPRN,  KC_RPRN},
  {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,        KC_PLUS,        KC_LCBR,  KC_RCBR, KC_PIPE},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  LSFT(KC_NUHS),  LSFT(KC_NUBS),   KC_HOME, KC_END,  _______},
  {_______, _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY}
},
*/

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  //float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    // case COLEMAK:
    //   if (record->event.pressed) {
    //     set_single_persistent_default_layer(_COLEMAK);
    //   }
    //   return false;
    //   break;
    case MY_DVORAK:
      if (record->event.pressed) {
        print("mode just switched to my dvorak\n");
        set_single_persistent_default_layer(_MY_DVORAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        print("mode just switched to dvorak\n");
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        PORTE &= ~(1<<6);
      } else {
        unregister_code(KC_RSFT);
        PORTE |= (1<<6);
      }
      return false;
      break;
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case KC_ESC:
      if (record->event.pressed) {
        bool queue = true;

        if ((get_oneshot_mods ()) && !has_oneshot_mods_timed_out ()) {
          clear_oneshot_mods ();
          queue = false;
        }
        return queue;
      }
    // case EXT_PLV:
    //   if (record->event.pressed) {
    //     #ifdef AUDIO_ENABLE
    //       PLAY_SONG(plover_gb_song);
    //     #endif
    //     layer_off(_PLOVER);
    //   }
    //   return false;
    //   break;
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

qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_SHIFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
  [TD_COPYPASTE] = ACTION_TAP_DANCE_DOUBLE(LGUI(DV_C), LGUI(DV_V)),

//  [TD_LAYER_3]  = ACTION_TAP_DANCE_DUAL_ROLE(KC_ESC, 3),
//  [TD_DOUBLE] = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_2),
//  [TD_LAYER_1]  = ACTION_TAP_DANCE_DUAL_ROLE(KC_ESC, 1)
// Other declarations would go here, separated by commas, if you have them
};

const uint16_t PROGMEM fn_actions[] = {
   [F_BSE]  = ACTION_LAYER_CLEAR(ON_PRESS)
  ,[F_SFT]  = ACTION_MODS_ONESHOT (MOD_LSFT)
  ,[F_ALT]  = ACTION_MODS_ONESHOT (MOD_LALT)
  ,[F_CTRL] = ACTION_MODS_ONESHOT (MOD_LCTL)
  // ,[F_LOWER] = ACTION_MODS_ONESHOT (LOWER)
  // ,[F_RAISE] = ACTION_MODS_ONESHOT (RAISE)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
          return MACRODOWN( DOWN(KC_LCTL), TYPE(KC_B), UP(KC_LCTL), TYPE(KC_0), END );
          break;
        case 1:
          return MACRODOWN( DOWN(KC_LCTL), TYPE(KC_B), UP(KC_LCTL), TYPE(KC_1), END );
          break;
        case 2:
          return MACRODOWN( DOWN(KC_LCTL), TYPE(KC_B), UP(KC_LCTL), TYPE(KC_2), END );
          break;
        case 3:
          return MACRODOWN( DOWN(KC_LCTL), TYPE(KC_B), UP(KC_LCTL), TYPE(KC_3), END );
          break;
        case 4:
          return MACRODOWN( DOWN(KC_LCTL), TYPE(KC_B), UP(KC_LCTL), TYPE(KC_4), END );
          break;
        case 5:
          return MACRODOWN( DOWN(KC_LCTL), TYPE(KC_B), UP(KC_LCTL), TYPE(KC_5), END );
          break;
        case 6:
          return MACRODOWN( DOWN(KC_LCTL), TYPE(KC_B), UP(KC_LCTL), TYPE(KC_6), END );
          break;
        case 7:
          return MACRODOWN( DOWN(KC_LCTL), TYPE(KC_B), UP(KC_LCTL), TYPE(KC_7), END );
          break;
        case 8:
          return MACRODOWN( DOWN(KC_LCTL), TYPE(KC_B), UP(KC_LCTL), TYPE(KC_8), END );
          break;
        case 9:
          // tmux last window
          return MACRODOWN( DOWN(KC_LCTL), TYPE(KC_B), UP(KC_LCTL), TYPE(KC_L), END );
          break;
          // tmux next window
        case 10:
          return MACRODOWN( DOWN(KC_LCTL), TYPE(KC_B), UP(KC_LCTL), TYPE(KC_N), END );
          break;
          // tmux previous window
        case 11:
          return MACRODOWN( DOWN(KC_LCTL), TYPE(KC_B), UP(KC_LCTL), TYPE(KC_P), END );
          break;
          // tmux new window
        case 12:
          return MACRODOWN( DOWN(KC_LCTL), TYPE(KC_B), UP(KC_LCTL), TYPE(KC_C), END );
          break;
        case 13:
          // vi save document
          return MACRODOWN( TYPE(KC_ESC), DOWN(KC_LSFT), TYPE(KC_SCLN), UP(KC_LSFT), TYPE(KC_W), TYPE(KC_ENT), END );
          break;
        case 14:
          // vi quit
          return MACRODOWN( TYPE(KC_ESC), DOWN(KC_LSFT), TYPE(KC_SCLN), UP(KC_LSFT), TYPE(KC_Q), TYPE(KC_ENT), END );
          break;
          // tmux press ctrl-b
        case 15:
          return MACRODOWN( DOWN(KC_LCTL), TYPE(KC_B), UP(KC_LCTL), END );
          break;
      }
    return MACRO_NONE;
};
