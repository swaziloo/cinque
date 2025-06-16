#include "quantum.h"
#include QMK_KEYBOARD_H
#include "../../../common/common_keymap.h"

enum custom_keycodes {
    KC_LWR = SAFE_RANGE,
    KC_RSE
};

enum {
    TD_CTL_ALT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* QWERTY
 *                 ,----------------------------------.                    ,----------------------------------.
 *                 |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |
 *          ,------+------+------+------+------+------|                    |------+------+------+------+------+------.
 *          | TAB  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |   \  |
 *          |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 *     =     | ESC  |   A  |   S  |   D  |   F  |   G  |                    |   H  |   J  |   K  |   L  |   ;  |   '  |
 *          |------+------+------+------+------+------|------.      ,------|------+------+------+------+------+------|
 *          |   =  |   Z  |   X  |   C  |   V  |   B  |  F3  |      | MPLY |   N  |   M  |   ,  |   .  |   /  |   -  |
 *          `-----------------------------------------'---------.,---------'-----------------------------------------'
 *                           | LEFT | RGHT | CTRL | LSFT | BSPC || ENT  | SPC  | MOD  |  UP  | DOWN |
 *                           `----------------------------------'`----------------------------------'
 *                       Trackball Buttons | BTN1 | BTN2 | BTN3 ||      |      |      |  
 *                                         `--------------------'`--------------------'
 */
  [_QWERTY] = LAYOUT(
             KC_1,   KC_2,    KC_3,    KC_4,           KC_5,                      KC_6,   KC_7,     KC_8,    KC_9,   KC_0, 
    KC_TAB,  KC_Q,   KC_W,    KC_E,    KC_R,           KC_T,                      KC_Y,   KC_U,     KC_I,    KC_O,   KC_P,    KC_BSLS,
    KC_ESC,  KC_A,   KC_S,    KC_D,    KC_F,           KC_G,                      KC_H,   KC_J,     KC_K,    KC_L,   KC_SCLN, KC_QUOT,
    KC_EQL,  KC_Z,   KC_X,    KC_C,    KC_V,           KC_B,    KC_F3,   KC_MPLY, KC_N,   KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_MINS,
                     KC_LEFT, KC_RGHT, TD(TD_CTL_ALT), KC_LSFT, KC_BSPC, KC_ENT,  KC_SPC, MO(_MOD), KC_UP,   KC_DOWN,
                                       KC_BTN1,        KC_BTN2, KC_BTN3, KC_NO,   KC_NO,  KC_NO

),    

/* MOD
 *                 ,----------------------------------.                    ,----------------------------------.
 *                 |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |
 *          ,------+------+------+------+------+------|                    |------+------+------+------+------+------.
 *          | TAB  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |   \  |
 *          |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 *          | ESC  |   A  |   S  |   D  |   F  |   G  |                    |   H  |   J  |   K  |   L  |   ;  |   '  |
 *          |------+------+------+------+------+------|------.      ,------|------+------+------+------+------+------|
 *          | LWR  |   Z  |   X  |   C  |   V  |   B  |  F3  |      | MPLY |   N  |   M  |   [  |   ]  |   /  |   -  |
 *          `-----------------------------------------'---------.,---------'-----------------------------------------'
 *                           | HOME | END  | LALT | LSFT | DEL  || ENT  | SPC  | TRNS | PGUP | PGDN |
 *                           `----------------------------------'`----------------------------------'
 *                       Trackball Buttons | BTN1 | BTN2 | BTN3 ||      |      |      |  
 *                                         `--------------------'`--------------------'
 */
  [_MOD] = LAYOUT(
              KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,   KC_7,    KC_8,    KC_9,    KC_0, 
     KC_GRV,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
     KC_ESC,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
     KC_LWR,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_F3,   KC_MPLY, KC_N,   KC_M,    KC_LBRC, KC_RBRC, KC_SLSH, KC_MINS,
                      KC_HOME, KC_END,  KC_LALT, KC_LSFT, KC_DEL,  KC_ENT,  KC_SPC, KC_TRNS, KC_PGUP, KC_PGDN,
                                        KC_BTN1, KC_BTN2, KC_BTN3, KC_NO,   KC_NO,  KC_NO

),

/* LOWER
 *                 ,----------------------------------.                    ,----------------------------------.
 *                 |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F0  |
 *          ,------+------+------+------+------+------|                    |------+------+------+------+------+------.
 *          |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |  10  | F11  |
 *          |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 *          | ESC  | LCTL | LGUI | LALT | TOGG | NEXT |                    |      |      | PSCR | SCRL | PAUS | F12  |
 *          |------+------+------+------+------+------|-------.     ,------|------+------+------+------+------+------|
 *          | RSE  | LGUI | HOME | END  |      | INS  |   F3  |     | MPLY |      |      | PGUP | PGDN | RGUI |      |
 *          `-----------------------------------------'---------.,---------'-----------------------------------------'
 *                           | LEFT | RGHT | BKSP | LSFT | DEL  || ENT  | SPC  | RSE  | HUI  | VAI  |
 *                           `----------------------------------'`----------------------------------'
 *                     Trackball Buttons   | BTN1 | BTN2 | BTN3 ||      |      |      |  
 *                                         `--------------------'`--------------------'
 */        
[_LOWER] = LAYOUT(
            KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, 
    KC_GRV, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F11,
    KC_ESC, KC_LCTL, KC_LGUI, KC_LALT, UG_TOGG, UG_NEXT,                   KC_NO,   KC_NO,   KC_PSCR, KC_SCRL, KC_PAUS, KC_F12,
    KC_RSE, KC_LGUI, KC_HOME, KC_END,  KC_NO,   KC_INS,  KC_F3,   KC_MPLY, KC_NO,   KC_NO,   KC_PGUP, KC_PGDN, KC_RGUI, KC_NO,
                     KC_LEFT, KC_RGHT, KC_BSPC, KC_LSFT, KC_DEL,  KC_ENT,  KC_SPC,  KC_RSE,  RGB_HUI, RGB_VAI,
                                       KC_BTN1, KC_BTN2, KC_BTN3, KC_NO,   KC_NO,   KC_NO
)
};
    
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LWR:
            if (record->event.pressed) {
                layer_move(_LOWER);
            } 
            return false;
        case KC_RSE:
            if (record->event.pressed) {
                layer_move(_QWERTY);
            } 
            return false;
    }
    return true;
}

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_CTL_ALT] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_LALT),
};

#ifdef ENCODER_ENABLE

bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) {
        return false;
    }
    if (index == 0) {
        if (clockwise) {
            tap_code(MS_WHLU);
        } else {
            tap_code(MS_WHLD);
        }
    } else if (index == 1) {
        // RH knob is inverted
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    }
    return true;
}

#endif
