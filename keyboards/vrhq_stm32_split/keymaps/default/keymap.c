#include QMK_KEYBOARD_H

enum layers {
    BASE,
    ARROW,
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
 *   | MUTE |TG(2) | LSFT | LGUI | LALT |                                       |  EQL | MIN  |   [  |   ]  | TG(1)  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                 ,--------------------.       ,--------------------.
 *                                 | VOLD | VOL_U| LCTL |       | F11 | F10   |  F12 |
 *                                 ,------|------|------|       |------+--------+----.
 *                                 | Space| LGUI | LSFT |       | ESC | MO(1) | Enter|
 *                                 `--------------------'       `--------------------'
 */
[BASE] = LAYOUT_ergodox(
    KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,
    KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       RGB_MOD,
    KC_CAPS,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       RGB_RMOD,
    KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_HOME,
    KC_LCTL,    KC_APP,     KC_LALT,    KC_LGUI,    MO(1),
                                                    KC_VOLD,    KC_VOLU,    KC_MUTE,
                                                    KC_SPC,     KC_LGUI,    KC_ESC,

                KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_DEL,
    RGB_HUI,    KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSLS,
    RGB_HUD,    KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,
    KC_END,     KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_MINS,  
                            MO(1),      KC_INS,     KC_LBRC,    KC_RBRC,    KC_EQL,
    RGB_VAI,    RGB_VAD,    RGB_TOG,
    KC_BSPC,    DF(0),      KC_ENT
    ),

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
    KC_TRNS,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,
    KC_TRNS,    KC_NO,      KC_PGUP,    KC_UP,      KC_PGDN,    KC_NO,      RGB_SPI,
    KC_TRNS,    KC_NO,      KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_NO,      RGB_SPD,
    KC_TRNS,    KC_PAUS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                                    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                                    KC_TRNS,    KC_TRNS,    KC_TRNS,

                KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_TRNS,
    RGB_SAI,    KC_NO,      KC_PGUP,    KC_UP,      KC_PGDN,    KC_NO,      KC_TRNS,
    RGB_SAD,    KC_NO,      KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_NO,      KC_TRNS,
    KC_TRNS,    KC_PAUS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_TRNS,
                            KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS
    ),
};

void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom_cyan();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
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