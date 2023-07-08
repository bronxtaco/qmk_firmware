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
	_EDIT,
    _LOWER,
    _RAISE,
	_WINDOWS,
	_NUMPAD,
};

enum custom_keycodes {
  LOWER = SAFE_RANGE,
  LOWER_SHIFT,
  RAISE,
  SELECT_WORD,
  VERT_LEAP,
  //ADJUST,
  //ONESHOT,
  DAVE,
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
      LM(_WINDOWS, MOD_LGUI), LOWER_SHIFT,    KC_Q,    KC_J,    KC_K,    KC_X,       KC_B,    KC_M, KC_W,  KC_V, KC_Z, KC_LSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LSFT,   LOWER,  KC_BSPC,     KC_SPC,   RAISE, KC_LALT
                                      //`--------------------------'  `--------------------------'

  ),
  
  [_EDIT] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, A(KC_O), C(KC_F), S(KC_F3), KC_F3, XXXXXXX,                       XXXXXXX, KC_HOME, KC_UP, KC_END, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, C(KC_A), C(KC_S), SELECT_WORD, C(KC_C), C(KC_V),                  XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, C(KC_X), C(KC_D), C(KC_Z), C(KC_Y),                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, LOWER, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       C(KC_GRV), CW_TOGG, XXXXXXX,   XXXXXXX, XXXXXXX,  TO(_NUMPAD),                KC_LCBR,    KC_7,    KC_8,    KC_9,    KC_EQL,  KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    TO(_EDIT),    XXXXXXX,     KC_LPRN,    KC_4,    KC_5,    KC_6,    KC_SCLN, KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LBRC,    KC_1,    KC_2,    KC_3,    KC_SLSH, KC_GRV,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, _______, XXXXXXX,    _______, KC_0, _______
                                      //`--------------------------'  `--------------------------'
  ),
  
  [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_F7,   KC_F8,  KC_F9,  KC_F10, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, DM_REC1, DM_PLY1, XXXXXXX,                     XXXXXXX, KC_F4, KC_F5, KC_F6, KC_F11, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, KC_F1, KC_F2, KC_F3, KC_F12, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, KC_DEL,    XXXXXXX, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
  
  [_WINDOWS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UP, KC_7,   KC_8,  KC_9, KC_DOWN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, S(KC_S), XXXXXXX, XXXXXXX, KC_V,                         C(KC_LEFT), KC_4, KC_5, KC_6, C(KC_RGHT), _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_1, KC_2, KC_3, KC_RGHT, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),
  
  [_NUMPAD] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, A(KC_F4), KC_CALC,                      KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PMNS, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_PAST, KC_P4, KC_P5, KC_P6, KC_PPLS, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_P1, KC_P2, KC_P3, KC_PDOT, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, LOWER_FROM_LAYER, _______,    _______, KC_P0, _______
                                      //`--------------------------'  `--------------------------'
  ),
  
  /*
  [_EDIT] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
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
	case LOWER:
		if (record->event.pressed) {
			layer_move(_BASE_DVORAK);
			layer_on(_LOWER);
		} else {
			layer_off(_LOWER);
		}
		return false;
		break;
	case LOWER_SHIFT:
		if (record->event.pressed) {
			layer_move(_BASE_DVORAK);
			layer_on(_LOWER);
		} else {
			layer_off(_LOWER);
		}
		return false;
		break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        //update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        del_mods(MOD_MASK_CTRL);
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
	case CTRL_TAB:
		if (record->event.pressed) {
			if (!(mod_state & MOD_MASK_CTRL)) {
				register_code(KC_LCTL);
			}
			register_code(KC_TAB);
		} else {
			unregister_code(KC_TAB);
		}
		return false;
	case KC_UP: {
		static bool vert_leap_enabled;
		if (record->event.pressed) {
			if (vert_leap_enabled) {
				SEND_STRING(SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP)SS_TAP(X_UP));
				return false;
			}
			return true;
		} else {

		}
		return true;
	}
	case KC_DOWN: {
		static bool vert_leap_enabled;
		if (record->event.pressed) {
			if (vert_leap_enabled) {
				SEND_STRING(SS_TAP(X_DOWN)SS_TAP(X_DOWN)SS_TAP(X_DOWN)SS_TAP(X_DOWN)SS_TAP(X_DOWN));
				return false;
			}
			return true;
		} else {

		}
		return true;
	}
	case VERT_LEAP: {
		static bool vert_leap_enabled;
		if (record->event.pressed) {
			vert_leap_enabled = true;
		} else {
			if (vert_leap_enabled) {
				vert_leap_enabled = false;
			}
		}
		return false;
	}
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
	case DAVE:
		/*
		enter
		tab
		tab
		shift tab
		space
		ctrl shift R
		right
		*/
		if (record->event.pressed) {
			SEND_STRING(SS_TAP(X_ENT)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_DOWN(X_LSFT)SS_TAP(X_TAB)SS_UP(X_LSFT)SS_TAP(X_SPC)SS_DOWN(X_LCTL)SS_DOWN(X_LSFT)SS_TAP(X_R)SS_UP(X_LCTL)SS_UP(X_LSFT)SS_TAP(X_RGHT));
			//SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_RGHT)SS_TAP(X_LEFT)SS_DOWN(X_LSFT)SS_TAP(X_RGHT)SS_UP(X_LCTL)SS_UP(X_LSFT));
		} else {
			
		}
		return false;
		break;
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