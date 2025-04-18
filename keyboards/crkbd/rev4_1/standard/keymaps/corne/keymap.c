#include QMK_KEYBOARD_H

enum layers {
  _BAS,
  _NUM,
  _SYM
};

#define NO_AE RALT(KC_QUOT)    // æ
#define NO_OE RALT(KC_SCLN)    // ø
#define NO_AA RALT(KC_LBRC)    // å
#define NO_AE_UP RALT(S(KC_QUOT))  // Æ
#define NO_OE_UP RALT(S(KC_SCLN))  // Ø
#define NO_AA_UP RALT(S(KC_LBRC))  // Å

#define HOME_A LCTL_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LGUI_T(KC_F)
#define HOME_J RGUI_T(KC_J)
#define HOME_K RSFT_T(KC_K)
#define HOME_L RALT_T(KC_L)
#define HOME_SCLN RCTL_T(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BAS] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LEFT,    KC_UP,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     KC_ESC,  HOME_A,  HOME_S,  HOME_D,  HOME_F,  KC_G,    KC_RIGHT,   KC_DOWN, KC_H,    HOME_J,  HOME_K,  HOME_L,  HOME_SCLN,KC_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
     KC_GRV,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                         KC_NO,   MO(_NUM),KC_SPC,     KC_SPC,  MO(_SYM), KC_NO
                                      //`--------------------------'  `--------------------------'
  ),

  [_NUM] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
     KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,    KC_TRNS, KC_SLSH, KC_7,    KC_8,    KC_9,    KC_MINS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     KC_TRNS, KC_LCTL, KC_LALT, KC_LSFT, KC_LGUI, KC_NO,   KC_TRNS,    KC_TRNS, KC_ASTR, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
     KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_COMM, KC_1,    KC_2,    KC_3,    KC_DOT,  KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                         KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_0
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYM] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
     KC_TRNS, KC_DEL,  KC_NO,   KC_LPRN, KC_RPRN, KC_BSLS, KC_TRNS,    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     KC_TRNS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_NO,   KC_TRNS,    KC_TRNS, KC_NO,   KC_RGUI, KC_RSFT, KC_RALT, KC_RCTL, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
     KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_SECT,                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                         KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        if ((keycode == KC_B || keycode == KC_N) &&
            (get_mods() & MOD_MASK_CTRL) &&
            (get_mods() & MOD_MASK_SHIFT) &&
            (get_mods() & MOD_MASK_ALT) &&
            (get_mods() & MOD_MASK_GUI)) {
            reset_keyboard();
            return false;
        }

        switch(keycode) {
            case KC_LBRC:
                if (get_mods() & MOD_MASK_ALT) {
                    if (get_mods() & MOD_MASK_SHIFT) {
                        tap_code16(NO_AA_UP);
                    } else {
                        tap_code16(NO_AA);
                    }
                    unregister_mods(MOD_MASK_ALT | MOD_MASK_SHIFT);
                    return false;
                }
                break;
            case KC_SCLN:
                 if (!(get_mods() & MOD_BIT(KC_RCTL)) && (get_mods() & MOD_MASK_ALT)) {
                    if (get_mods() & MOD_MASK_SHIFT) {
                        tap_code16(NO_OE_UP);
                    } else {
                        tap_code16(NO_OE);
                    }
                    unregister_mods(MOD_MASK_ALT | MOD_MASK_SHIFT);
                    return false;
                }
                break;
            case KC_QUOT:
                 if (!(get_mods() & MOD_BIT(KC_RALT)) && (get_mods() & MOD_MASK_ALT)) {
                    if (get_mods() & MOD_MASK_SHIFT) {
                        tap_code16(NO_AE_UP);
                    } else {
                        tap_code16(NO_AE);
                    }
                    unregister_mods(MOD_MASK_ALT | MOD_MASK_SHIFT);
                    return false;
                }
                break;
        }
    }
    return true;
}

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
    rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv(0, 0, 255);
}
