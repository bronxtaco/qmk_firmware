/*
Copyright 2022 x123 <@x123>
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum layer_names {
    _BASE_DVORAK,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
  ADJUST,
  //ONESHOT,
  DT_UP_50,
  DT_DOWN_50,
  DT_UP_X2,
  DT_DOWN_X2,
  DT_200,
  DT_MAX,
};

#define LSFT_KA LSFT_T(KC_A)
#define LCTL_KS LCTL_T(KC_S)
#define LGUI_KD LGUI_T(KC_D)
#define LALT_KF LALT_T(KC_F)
#define LALT_KJ LALT_T(KC_J)
#define RGUI_KK RGUI_T(KC_K)
#define RCTL_KL RCTL_T(KC_L)
#define RS_SCLN RSFT_T(KC_SCLN)

#define LCTL_KR LCTL_T(KC_R)
#define LGUI_KS LGUI_T(KC_S)
#define LALT_KT LALT_T(KC_T)
#define LALT_KN LALT_T(KC_N)
#define RGUI_KE RGUI_T(KC_E)
#define RCTL_KI RCTL_T(KC_I)
#define RSFT_KO RSFT_T(KC_O)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE_DVORAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_QUOT,    KC_COMM,    KC_DOT,    KC_P,    KC_Y,                 KC_F,    KC_G,    KC_C,    KC_R,   KC_L,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                         KC_D,    KC_H,    KC_T,    KC_N, KC_S, KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_LALT,    KC_Q,    KC_J,    KC_K,    KC_X,                         KC_B,    KC_M, KC_W,  KC_V, KC_Z, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LWIN,   LOWER,  KC_BSPC,     KC_SPC,   RAISE, _______
                                      //`--------------------------'  `--------------------------'

  ),

  [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       C(KC_TAB), _______, _______,   _______, _______,  _______,                _______,    KC_7,    KC_8,    KC_9,    KC_EQL,  KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    C(KC_A),    C(KC_S),    C(KC_C),    C(KC_V),    C(KC_X),       _______,    KC_4,    KC_5,    KC_6,    KC_SCLN, KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      KC_RCBR,    KC_1,    KC_2,    KC_3,    KC_SLSH, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, KC_0, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_GRV, _______, KC_HOME, KC_UP, KC_END, KC_LBRC,                          KC_RBRC, KC_F7,   KC_F8,  KC_F9,  KC_F10, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, S(KC_LBRC),                   S(KC_RBRC), KC_F4, KC_F5, KC_F6, KC_F11, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      C(KC_F), KC_F1, KC_F2, KC_F3, KC_F12, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, KC_DEL,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    /*case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case QWERTY_NOHOMEROW:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY_NOHOMEROW);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case COLEMAK_NOHOMEROW:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK_NOHOMEROW);
      }
      return false;
      break;*/
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    /*case ONESHOT:
      if (record->event.pressed) {
        set_oneshot_layer(_ONESHOT, ONESHOT_START);
      } else {
        clear_oneshot_layer_state(ONESHOT_PRESSED);
      }
      return false;
      break;*/
    case DT_UP_50:
      if (record->event.pressed) {
        g_tapping_term += 50;
      }
      return false;
      break;
    case DT_DOWN_50:
      if (record->event.pressed) {
        g_tapping_term -= 50;
      }
      return false;
      break;
    case DT_UP_X2:
      if (record->event.pressed) {
        g_tapping_term *= 2;
      }
      return false;
      break;
    case DT_DOWN_X2:
      if (record->event.pressed) {
        g_tapping_term /= 2;
      }
      return false;
      break;
    case DT_200:
      if (record->event.pressed) {
        g_tapping_term = 200;
      }
      return false;
      break;
    case DT_MAX:
      if (record->event.pressed) {
        g_tapping_term = 34464;
      }
      return false;
      break;
  }
  return true;
}