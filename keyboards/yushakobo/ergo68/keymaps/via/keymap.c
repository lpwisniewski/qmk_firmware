#include QMK_KEYBOARD_H
#include "version.h"

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  HSV_177_255_84,
  HSV_86_255_128,
  HSV_27_255_255,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox_pretty(
              KC_EQUAL,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                                          KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINU
                  KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_LEFT,                                   KC_RIGHT,        KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,
                      LT(1,KC_ESCAPE),KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           TG(3),                                               KC_INSERT,                KC_H,           KC_J,           KC_K,           KC_L,           LT(2,KC_SCLN),  LT(1,KC_QUOTE),
                          KC_LEFT_SHIFT,  MT(MOD_LCTL, KC_Z),KC_X,           KC_C,           KC_V,           KC_B,           RALT(KC_LEFT_CTRL),                                KC_GRAVE,       KC_N,           KC_Q,           KC_COMMA,       KC_DOT,         MT(MOD_RCTL, KC_SLASH),MT(MOD_RSFT, KC_GRAVE),
                              LT(1,KC_GRAVE), KC_QUOTE,       KC_LEFT_ALT,    KC_LEFT,        KC_RIGHT,       KC_SPACE,       KC_BSPC,      KC_RIGHT_GUI,   KC_ENTER,                KC_UP,          KC_DOWN,        KC_LBRC,        KC_RBRC,        MO(3),

                                ),
  [1] = LAYOUT_ergodox_pretty(
              KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                            KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
                  KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_LCBR,        KC_RCBR,        KC_HOME,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_PAGE_UP,     KC_7,           KC_8,           KC_9,           KC_ASTR,        KC_F12,
                      KC_TRANSPARENT, KC_HASH,        KC_DLR,         KC_LPRN,        KC_RPRN,        KC_END,         KC_TRANSPARENT,                   KC_TRANSPARENT,        KC_PGDN,        KC_4,           KC_5,           KC_6,           KC_PLUS,        KC_TRANSPARENT,
                          KC_TRANSPARENT, KC_PERC,        KC_CIRC,        KC_LBRC,        KC_RBRC,        KC_TILD,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_AMPR,        KC_1,           KC_2,           KC_3,           KC_BSLS,        KC_TRANSPARENT,
                              KC_TRANSPARENT, KC_EQUAL,       KC_TRANSPARENT, KC_TRANSPARENT, RGB_MODE_FORWARD,   RGB_VAD,        RGB_VAI,                       RGB_HUD,        RGB_HUI,   RGB_TOG, KC_DOT,         KC_0,           KC_EQUAL,       KC_TRANSPARENT,

                                ),
  [2] = LAYOUT_ergodox_pretty(
              KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_BOOT,
                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_UP,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,  KC_TRANSPARENT, KC_TRANSPARENT,
                      KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN2,     KC_MS_BTN1,     KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PLAY_PAUSE,
                          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, KC_TRANSPARENT,
                              KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_BTN2,                           KC_TRANSPARENT, KC_TRANSPARENT,                                                                          KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,  KC_TRANSPARENT, KC_TRANSPARENT,

                                ),
  [3] = LAYOUT_ergodox_pretty(
              KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                      KC_ESCAPE,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                             KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                          KC_TRANSPARENT, KC_Z,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                              KC_LEFT_CTRL,   KC_LEFT_ALT,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                     KC_TRANSPARENT, KC_TRANSPARENT,                                                            KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                ),
};




bool suspended = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

      case RGB_SLD:
        if (record->event.pressed) {
                rgblight_mode(1);
              }
        return false;
      case HSV_177_255_84:
        if (record->event.pressed) {
                #ifdef RGBLIGHT_ENABLE
                  rgblight_enable();
                  rgblight_mode(1);
                  rgblight_sethsv(177,255,84);
                #endif
              }
        return false;
      case HSV_86_255_128:
        if (record->event.pressed) {
                #ifdef RGBLIGHT_ENABLE
                  rgblight_enable();
                  rgblight_mode(1);
                  rgblight_sethsv(86,255,128);
                #endif
              }
        return false;
      case HSV_27_255_255:
        if (record->event.pressed) {
                #ifdef RGBLIGHT_ENABLE
                  rgblight_enable();
                  rgblight_mode(1);
                  rgblight_sethsv(27,255,255);
                #endif
              }
        return false;
    }
  return true;
}

uint8_t layer_state_set_user(uint8_t state) {
    uint8_t layer = biton(state);
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
          case 1:
            ergodox_right_led_1_on();
            break;
          case 2:
            ergodox_right_led_2_on();
            break;
          case 3:
            ergodox_right_led_3_on();
            break;
          case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
          case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
          case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
          case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
          default:
            break;
        }
    return state;
};

void keyboard_post_init_user(void) {
  layer_state_set_user(layer_state);
}

