#include QMK_KEYBOARD_H

enum layers {
  _BAS,
  _NUM,
  _SPE,
  _GAM,
  _GNM
};

#define NO_AE UC(0x00E6)  // æ
#define NO_OE UC(0x00F8)  // ø
#define NO_AA UC(0x00E5)  // å
#define NO_AE_UP UC(0x00C6)  // Æ
#define NO_OE_UP UC(0x00D8)  // Ø
#define NO_AA_UP UC(0x00C5)  // Å

#define HOME_A LCTL_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LGUI_T(KC_F)
#define HOME_J RGUI_T(KC_J)
#define HOME_K RSFT_T(KC_K)
#define HOME_L RALT_T(KC_L)
#define HOME_SCLN RCTL_T(KC_SCLN)

#define RS_EXLM RSFT(KC_1)
#define RS_AT RSFT(KC_2)
#define RS_HASH RSFT(KC_3)
#define RS_DLR RSFT(KC_4)
#define RS_PERC RSFT(KC_5)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BAS] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_NO,      TG(_GAM),KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     KC_ESC,  HOME_A,  HOME_S,  HOME_D,  HOME_F,  KC_G,    KC_NO,      KC_NO,   KC_H,    HOME_J,  HOME_K,  HOME_L, HOME_SCLN,KC_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
     KC_GRV,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                         MO(_SPE),MO(_NUM),KC_SPC,     KC_SPC,  MO(_NUM), MO(_SPE)
                                      //`--------------------------'  `--------------------------'
  ),

  [_NUM] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
     KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS,    KC_TRNS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     KC_TRNS, KC_LCTL, KC_LALT, KC_LSFT, KC_LGUI, KC_NO,   KC_TRNS,    KC_TRNS, KC_NO,   KC_RGUI, KC_RSFT, KC_RALT, KC_RCTL, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
     KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                         KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

  [_SPE] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
     KC_TRNS, RS_EXLM, RS_AT,   RS_HASH, RS_DLR,  RS_PERC, KC_TRNS,    KC_TRNS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,    KC_TRNS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
     KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,               KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                         KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

  [_GAM] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_NO,      TG(_GAM),   KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_NO,      KC_NO,   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                         KC_LCTL ,MO(_GNM),KC_SPC,     KC_SPC,  MO(_GNM), KC_RCTL
                                      //`--------------------------'  `--------------------------'
  ),

  [_GNM] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
     KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS,    KC_TRNS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     KC_TRNS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_TRNS,    KC_TRNS, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
     KC_TRNS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_TRNS,
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
            case KC_A:
                if (get_mods() & MOD_MASK_ALT) {
                    if (get_mods() & MOD_MASK_SHIFT) {
                        tap_code16(NO_AE_UP);
                    } else {
                        tap_code16(NO_AE);
                    }
                    return false;
                }
                break;
            case KC_O:
                if (get_mods() & MOD_MASK_ALT) {
                    if (get_mods() & MOD_MASK_SHIFT) {
                        tap_code16(NO_OE_UP);
                    } else {
                        tap_code16(NO_OE);
                    }
                    return false;
                }
                break;
            case KC_P:
                if (get_mods() & MOD_MASK_ALT) {
                    if (get_mods() & MOD_MASK_SHIFT) {
                        tap_code16(NO_AA_UP);
                    } else {
                        tap_code16(NO_AA);
                    }
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
