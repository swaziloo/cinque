#include "quantum.h"
#include <stdint.h>
#include QMK_KEYBOARD_H
#include "bitmaps.h"
#include "cinque-oled.h"
#include "common_keymap.h"
#include "kodama.h"

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

static uint8_t current_state;
static uint8_t prior_state_L = _LOWER; // enables initial write
static uint8_t prior_state_R = _LOWER; // enables initial write

static void print_layer_state_left(void) {
    current_state = get_highest_layer(layer_state);
    // Print current layer
    switch (current_state) {
        case _QWERTY:
            if (prior_state_L != _QWERTY) {
                if (prior_state_L != _MOD) {
                    oled_write_raw_P(cinque_logo, cinque_logo_len);
                }
                oled_set_cursor(0, 1); oled_write(PSTR("M"), false);
                oled_set_cursor(0, 2); oled_write(PSTR("A"), false);
                oled_set_cursor(0, 3); oled_write(PSTR("I"), false);
                oled_set_cursor(0, 4); oled_write(PSTR("N"), false);
                oled_set_cursor(0, 5); oled_write(PSTR(" "), false);
                oled_set_cursor(0, 6); oled_write(PSTR(" "), false);
                prior_state_L = _QWERTY;
            }
            break;
        case _MOD:
            if (prior_state_L != _MOD) {
                oled_set_cursor(0, 1); oled_write(PSTR("*"), true);
                oled_set_cursor(0, 2); oled_write(PSTR("M"), true);
                oled_set_cursor(0, 3); oled_write(PSTR("O"), true);
                oled_set_cursor(0, 4); oled_write(PSTR("D"), true);
                oled_set_cursor(0, 5); oled_write(PSTR("*"), true);
                oled_set_cursor(0, 6); oled_write(PSTR(" "), false);
                prior_state_L = _MOD;
            }
            break;
        case _LOWER:
            if (prior_state_L != _LOWER) {
                oled_write_raw_P(cinque_logo_inv, cinque_logo_inv_len);
                oled_set_cursor(0, 1); oled_write(PSTR(" L"), true);
                oled_set_cursor(0, 2); oled_write(PSTR(" O"), true);
                oled_set_cursor(0, 3); oled_write(PSTR(" W"), true);
                oled_set_cursor(0, 4); oled_write(PSTR(" E"), true);
                oled_set_cursor(0, 5); oled_write(PSTR(" R"), true);
                prior_state_L = _LOWER;
            }
            break;
        default:
            oled_write_ln(PSTR("\n U  L\n N  A\n D  Y\n E  E\n F  R"), false);
    }
}

static void print_layer_state_right(void) {
    current_state = get_highest_layer(layer_state);
    // Print current layer
    switch (current_state) {
        case _QWERTY:
            if (prior_state_R != _QWERTY) {
                oled_set_cursor(0, 0);
                oled_write(PSTR(" MAIN"), false);
                prior_state_R = _QWERTY;
            }
            break;
        case _MOD:
            if (prior_state_R != _MOD) {
                oled_set_cursor(0, 0);
                oled_write(PSTR("*MOD*"), true);
                prior_state_R = _MOD;
            }
            break;
        case _LOWER:
            if (prior_state_R != _LOWER) {
                oled_set_cursor(0, 0);
                oled_write(PSTR("LOWER"), true);
                prior_state_R = _LOWER;
            }
            break;
        default:
            oled_write_ln(PSTR("UNDEF\nLAYER"), false);
    }
    if (get_mods() & MOD_MASK_CTRL) {
        oled_set_cursor(0, 2); oled_write(PSTR("C"), true);
    } else {
        oled_set_cursor(0, 2); oled_write(PSTR(" "), false);
    };
    if (get_mods() & MOD_MASK_SHIFT) {
        oled_set_cursor(2, 2); oled_write(PSTR("S"), true);
    } else {
        oled_set_cursor(2, 2); oled_write(PSTR(" "), false);
    };
    if (get_mods() & MOD_MASK_ALT) {
        oled_set_cursor(4, 2); oled_write(PSTR("A"), true);
    } else {
        oled_set_cursor(4, 2); oled_write(PSTR(" "), false);
    };
    if (get_mods() & MOD_MASK_GUI) {
        oled_set_cursor(6, 2); oled_write(PSTR("G"), true);
    } else {
        oled_set_cursor(6, 2); oled_write(PSTR(" "), false);
    };
}

bool needs_init_logo = true;
static uint8_t mtrx_mode = 128;
// ensure you have at least two more of these than configured matrix modes
static const char* mtrx_name[] = {
    "zero","solid", "pinwb", "pinwr","brthg","heatm","rwide","rmnxs","mspsh","river","seven","eight","nine"
};

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        if (is_oled_on()) print_layer_state_left();
    } else {
        if (needs_init_logo) {
            oled_set_cursor(0, 15);
            oled_write_raw_P(cinque_sm_horiz, cinque_sm_horiz_len);
            needs_init_logo = false;
        }
        if (is_oled_on()) {
            print_layer_state_right();
            if (mtrx_mode != rgb_matrix_get_mode()) {
                mtrx_mode = rgb_matrix_get_mode();
                oled_set_cursor(0, 6);
                oled_write(PSTR("MTRX:"), false);
                oled_write(mtrx_name[mtrx_mode], false);
            }
            render_animated_kodama();
        }
    }
    return false;
}

#endif