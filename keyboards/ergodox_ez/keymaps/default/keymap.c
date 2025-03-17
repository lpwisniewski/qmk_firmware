#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    BASE,  // default layer
    SYMB,  // symbols
    MDIA,  // media keys
};

enum custom_keycodes {
    VRSN = SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox(

        KC_EQUAL,     KC_1,        KC_2,          KC_3,    KC_4,     KC_5,          KC_LEFT,
        KC_TAB,       KC_Q,        KC_W,          KC_E,    KC_R,     KC_T,          KC_LEFT,
        LT(1,KC_ESCAPE),KC_A,      KC_S,          KC_D,    KC_F,     KC_G,
        KC_LEFT_SHIFT,MT(MOD_LCTL, KC_Z),MT(MOD_LALT, KC_X),KC_C,KC_V,KC_B,         RALT(KC_LEFT_CTRL),
        LT(1,KC_GRAVE),KC_QUOTE,   KC_LEFT_ALT,   KC_LEFT, KC_BSPC,

                                                                     ALT_T(KC_APP), KC_LGUI,
                                                                                    KC_HOME,
                                                           KC_SPC,   KC_BSPC,       KC_END,

        KC_RGHT,       KC_6,     KC_7,     KC_8,     KC_9,     KC_0,               KC_MINUS,
        KC_INSERT,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,               KC_BSLS,
                       KC_H,     KC_J,     KC_K,     KC_L,     LT(2,KC_SCLN),      LT(1,KC_QUOTE),
        KC_GRAVE,      KC_N,     KC_M,     KC_COMMA, MT(MOD_RALT, KC_DOT),MT(MOD_RCTL, KC_SLASH),MT(MOD_RSFT, KC_GRAVE),
                                 KC_RIGHT_GUI,KC_DOWN,KC_LBRC, KC_RBRC,            KC_NO,
        KC_LALT,    CTL_T(KC_ESC),
        KC_PGUP,
        KC_PGDN,    KC_RIGHT_GUI,        KC_ENTER
),


  [1] = LAYOUT_ergodox(
        KC_ESCAPE,    KC_F1,       KC_F2,         KC_F3,   KC_F4,    KC_F5,         KC_LEFT,
        KC_TRANSPARENT,KC_EXLM,    KC_AT,         KC_LCBR, KC_RCBR,  KC_HOME,       KC_TRANSPARENT,
                        KC_TRNS,   KC_HASH,       KC_DLR,  KC_LPRN,  KC_RPRN,       KC_END,
        KC_TRANSPARENT, KC_PERC,   KC_CIRC,       KC_LBRC, KC_RBRC,  KC_TILD,       KC_TRANSPARENT,
        KC_TRANSPARENT, KC_EQUAL,  KC_TRANSPARENT,KC_TRANSPARENT,    KC_NO,

                                                                     ALT_T(KC_APP), KC_LGUI,
                                                                                    KC_HOME,
                                                           KC_SPC,   KC_BSPC,       KC_END,

        KC_RGHT,       KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,             KC_F11,
        KC_TRANSPARENT,KC_PAGE_UP,KC_7,    KC_8,     KC_9,     KC_ASTR,            KC_F12,
                       KC_PGDN,  KC_4,     KC_5,     KC_6,     KC_PLUS,            KC_TRANSPARENT,
        KC_TRANSPARENT,KC_AMPR,  KC_1,     KC_2,     KC_3,     KC_BSLS,            KC_TRANSPARENT,
                                 KC_NO,    KC_DOT,   KC_0,     KC_EQUAL,           KC_TRANSPARENT,

        KC_LALT,    CTL_T(KC_ESC),
        KC_PGUP,
        KC_PGDN,    KC_RIGHT_GUI,        KC_ENTER
    ),

  [2] = LAYOUT_ergodox(
        KC_TRNS,        KC_TRNS,   KC_TRNS,       KC_TRNS, KC_TRNS,  KC_TRNS,       KC_TRNS,
        KC_TRNS,        KC_TRNS,   KC_TRNS,       KC_MS_UP,KC_TRNS,  KC_TRNS,       KC_TRNS,
                        KC_TRNS,   KC_MS_LEFT,    KC_MS_DOWN,KC_MS_RIGHT,KC_TRNS,   KC_TRNS,
        KC_TRNS,        KC_TRNS,   KC_TRNS,       KC_TRNS, KC_TRNS,  KC_TRNS,       KC_TRNS,
        KC_TRNS,        KC_TRNS,   KC_TRNS,       KC_MS_BTN1,KC_MS_BTN2,

                                                                     ALT_T(KC_APP), KC_LGUI,
                                                                                    KC_HOME,
                                                           KC_SPC,   KC_BSPC,       KC_END,


        KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            QK_BOOT,
        KC_TRNS,       KC_TRNS,  KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,KC_TRNS,KC_TRNS,
                       KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, KC_TRNS,            KC_MEDIA_PLAY_PAUSE,
        KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRNS,KC_TRNS,
                                 KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,  KC_TRANSPARENT, KC_TRANSPARENT,

        KC_LALT,    CTL_T(KC_ESC),
        KC_PGUP,
        KC_PGDN,    KC_RIGHT_GUI,        KC_ENTER
    )
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case VRSN:
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
        }
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
            break;
        case 1:
            ergodox_right_led_1_on();
#ifdef RGBLIGHT_COLOR_LAYER_1
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
#endif
            break;
        case 2:
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_2
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
#endif
            break;
        case 3:
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_3
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
#endif
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_4
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
#endif
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_5
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
#endif
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_6
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_7
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
#endif
            break;
        default:
            break;
    }

    return state;
};
