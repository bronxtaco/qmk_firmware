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
    _EDIT,
};

enum custom_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
  SELECT_WORD,
  //ADJUST,
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
      KC_LWIN, LM(_LOWER, MOD_LSFT),    KC_Q,    KC_J,    KC_K,    KC_X,                         KC_B,    KC_M, KC_W,  KC_V, KC_Z, KC_LALT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LSFT,   LOWER,  KC_BSPC,     KC_SPC,   RAISE, _______
                                      //`--------------------------'  `--------------------------'

  ),

  [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       C(KC_GRV), CW_TOGG, _______,   _______, _______,  _______,                KC_LCBR,    KC_7,    KC_8,    KC_9,    KC_EQL,  KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    _______,    _______,    _______,    TO(_EDIT),    _______,     KC_LPRN,    KC_4,    KC_5,    KC_6,    KC_SCLN, KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, KC_LWIN,                      KC_LBRC,    KC_1,    KC_2,    KC_3,    KC_SLSH, KC_GRV,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, KC_0, _______
                                      //`--------------------------'  `--------------------------'
  ),
  
  [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      C(KC_TAB), _______, _______, _______, _______, _______,                   _______, KC_F7,   KC_F8,  KC_F9,  KC_F10, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                     _______, KC_F4, KC_F5, KC_F6, KC_F11, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                     _______, KC_F1, KC_F2, KC_F3, KC_F12, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, KC_DEL,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),
  
  [_EDIT] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, C(S(KC_F3)), C(KC_F3), _______,                 _______, KC_HOME, KC_UP, KC_END, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, C(KC_A), C(KC_S), SELECT_WORD, C(KC_C), C(KC_V),                  C(KC_LEFT), KC_LEFT, KC_DOWN, KC_RGHT, C(KC_RGHT), _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, C(KC_Z), C(KC_X), C(KC_D), C(KC_F), KC_LWIN,                      _______, DM_PLY1, DM_PLY2, DM_REC1, DM_REC2, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, TO(_BASE_DVORAK), _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),
  
  /*
  [_EDIT] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),
  */
};

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	mod_state = get_mods();
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
      break;*/
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        //update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        //update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        //update_tri_layer(_LOWER, _RAISE, _ADJUST);h
      } else {
        layer_off(_RAISE);
        //update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
	 case SELECT_WORD:
		if (record->event.pressed) {
			SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_RGHT)SS_TAP(X_LEFT)SS_DOWN(X_LSFT)SS_TAP(X_RGHT)SS_UP(X_LCTL)SS_UP(X_LSFT));
		} else {
			
		}
		return false;
		break;
	case KC_LCBR: {
		static bool rcbr_registered;
		if (record->event.pressed) {
			if (mod_state & MOD_MASK_SHIFT) {
				//del_mods(MOD_MASK_SHIFT);
				register_code(KC_RBRC);
				rcbr_registered = true;
				//set_mods(mod_state);
				return false;
			}
		} else {
			if (rcbr_registered) {
				unregister_code(KC_RBRC);
				rcbr_registered = false;
				return false;
			}
		}
		return true;
	}
	case KC_LPRN: {
		static bool rprn_registered;
		if (record->event.pressed) {
			if (mod_state & MOD_MASK_SHIFT) {
				//del_mods(MOD_MASK_SHIFT);
				register_code(KC_0);
				rprn_registered = true;
				//set_mods(mod_state);
				return false;
			}
		} else {
			if (rprn_registered) {
				unregister_code(KC_0);
				rprn_registered = false;
				return false;
			}
		}
		return true;
	}
	case KC_LBRC: {
		static bool rbrc_registered;
		if (record->event.pressed) {
			if (mod_state & MOD_MASK_SHIFT) {
				del_mods(MOD_MASK_SHIFT);
				register_code(KC_RBRC);
				rbrc_registered = true;
				set_mods(mod_state);
				return false;
			}
		} else {
			if (rbrc_registered) {
				unregister_code(KC_RBRC);
				rbrc_registered = false;
				return false;
			}
		}
		return true;
	}			
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