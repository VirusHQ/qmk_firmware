#include QMK_KEYBOARD_H

enum layers {
    BASE,  // default layer
    ARROW, // arrows
    MOUSE, // mouse keys
};

#include "joystick.h"

#ifndef ADC_PIN_1
#    define ADC_PIN_1 A0
#endif
#ifndef ADC_PIN_2
#    define ADC_PIN_2 A2
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
                    
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  ESC   |   1  |   2  |   3  |   4  |   5  |  ENC |           |  ENC |   6  |   7  |   8  |   9  |   0  |  DEL   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  TAB   |   Q  |   W  |   E  |   R  |   T  |   ~  |           |  EQL |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |  LCTL  |   A  |   S  |   D  |   F  |   G  | LCTL |           |  EQL |   H  |   J  |   K  |   L  |  ;   |   '    |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | LSFT |           |  MIN |   N  |   M  |   ,  |   .  |  /   | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | MUTE |TG(2) | LSFT | LCTL | LALT |                                       |  EQL | MIN  |   [  |   ]  | TG(1)  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                 ,--------------------.       ,--------------------.
 *                                 | VOLD | VOL_U| LCTL |       | F11 | F10   |  F12 |
 *                                 ,------|------|------|       |------+--------+----.
 *                                 | Space| LGUI | LSFT |       | ESC | MO(1) | Enter|
 *                                 `--------------------'       `--------------------'
 */
[BASE] = LAYOUT_ergodox(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_GRV,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LCTL,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LSFT,
    KC_MUTE, TG(2),   KC_LSFT, KC_LCTL, KC_LALT,
                                                 KC_VOLD, KC_VOLU, KC_LCTL,
                                                 KC_SPC,  KC_LGUI, KC_LSFT,

                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
             KC_EQL,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
             KC_EQL,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
             KC_MINS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                               KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, TG(1),
    KC_F11, KC_F10,  KC_F12,
    KC_ESC,  MO(1),   KC_ENT),

/* Keymap 1: Arrow layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      | PgDn | PgUp |      |  [   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |  ~   |      |------|           |------| LEFT | DOWN |  UP  |RIGHT |Backsp|   ]    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[ARROW] = LAYOUT_ergodox(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TILD, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                 KC_TRNS, KC_TRNS, KC_TRNS,                  
                                                 KC_TRNS, KC_TRNS, KC_TRNS,

                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
             KC_TRNS, KC_TRNS, KC_PGDN, KC_PGUP, KC_TRNS, KC_LBRC, KC_TRNS,
             KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSPC, KC_RBRC,
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS),

/* Keymap 2: Mouse layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | WH_U |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       | WH_L | WH_D | WH_R |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 | BTN1 |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[MOUSE] = LAYOUT_ergodox(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                 KC_TRNS, KC_TRNS, KC_TRNS,                  
                                                 KC_BTN1, KC_TRNS, KC_TRNS,

                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
                               KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS),
};

void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom_cyan();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_KNIGHT);
}

void matrix_scan_user() {
    int16_t val = (((uint32_t)timer_read() % 5000 - 2500) * 255) / 5000;

    if (val != joystick_status.axes[1]) {
        joystick_status.axes[1] = val;
        joystick_status.status |= JS_UPDATED;
    }
}

// Joystick config
joystick_config_t joystick_axes[JOYSTICK_AXES_COUNT] = {
    [0] = JOYSTICK_AXIS_IN(ADC_PIN_1, 0, 1024, 2046),
    [1] = JOYSTICK_AXIS_IN(ADC_PIN_2, 0, 1024, 2046)
};