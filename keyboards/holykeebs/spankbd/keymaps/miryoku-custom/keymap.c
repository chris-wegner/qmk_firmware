// layer 0 - qwerty
// layer 1 - navigation
// layer 2 - symbols
// layer 3 - number
// layer 4 - mouse
// layer 5 - media
// layer 6 - adjust

// On Windows run `QMK MSYS` as administrator

// Config is `holykeebs_spankbd_hk_oled_tps43`

// To build the firmware
// make holykeebs/spankbd:miryoku-custom -e TARGET=holykeebs_spankbd_hk_oled_tps43 -e USER_NAME=holykeebs -e OLED_FLIP=yes -e POINTING_DEVICE=tps43 -e POINTING_DEVICE_POSITION=right -j20 -e OLED=yes

// To build and flash the firmware
// make holykeebs/spankbd:miryoku-custom:flash -e TARGET=holykeebs_spankbd_hk_oled_tps43 -e USER_NAME=holykeebs -e OLED_FLIP=yes -e POINTING_DEVICE=tps43 -e POINTING_DEVICE_POSITION=right -j20 -e OLED=yes

// After building, when the build and flash command is `Waiting for drive to deploy...`, double tap the reset button just above the TRRS cable input on the right board to flash the new firmware.

// If keymap is not updating, run `qmk clean --all`
// Can also use https://usevia.app/ to update the keymap.
 
#include QMK_KEYBOARD_H
#include "users/holykeebs/holykeebs.h"

#define QK_C_EEPROM QK_CLEAR_EEPROM

enum {
    _ALPHA,
    _NAVIGATION,
    _SYMBOLS,
    _NUMBER,
    _MOUSE,
    _MEDIA,
    _ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
    /* Keymap 0: Alpha layer
     *
     * ,----------------------------------.      ,----------------------------------.
     * |   Q  |   W  |   E  |   R  |   T  |      |   Y  |   U  |   I  |   O  |   P  |
     * |------+------+------+------+------|      |------+------+------+------+------|
     * | GUI-A| ALT-S|CTRL-D|SHFT-F|   G  |      |   H  |SHFT-J|CTRL-K| ALT-L| GUI-'|
     * |------+------+------+------+------|      |------+------+------+------+------|
     * |   Z  |   X  |   C  |   V  |   B  |      |   N  |   M  |   ,  |   .  |   /  |
     * `----------------------------------'      `----------------------------------'
     *     .------------------------------.      .-----------------------------.
     *     |ADJST-TAB|SYMBL-BSPC|NUMBR-SPC|      |NAVIG-RTN|MOUSE-DEL|MEDIA-ESC|
     *     '------------------------------'      '-----------------------------'
     */
    [_ALPHA] = LAYOUT_split_3x5_3(
          KC_Q,         KC_W,         KC_E,               KC_R,                KC_T,                  KC_Y,                   KC_U,              KC_I,             KC_O,         KC_P,
          LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D),       LSFT_T(KC_F),        KC_G,                  KC_H,                   RSFT_T(KC_J),      RCTL_T(KC_K),     RALT_T(KC_L), RGUI_T(KC_QUOT),
          KC_Z,         KC_X,         KC_C,               KC_V,                KC_B,                  KC_N,                   KC_M,              KC_COMM,          KC_DOT,       KC_SLSH,
                                      LT(_ADJUST,KC_TAB), LT(_SYMBOLS,KC_BSPC), LT(_NUMBER,KC_SPC),   LT(_NAVIGATION,KC_ENT), LT(_MOUSE,KC_DEL), LT(_MEDIA,KC_ESC)
    ),

    /* Keymap 1: Navigation layer
     *
     * ,----------------------------------.      ,---------------------------------.
     * |      |      |      |      |      |      | AGAIN| UNDO |  CUT | COPY |PASTE|
     * |------+------+------+------+------|      |------+------+------+------+-----|
     * | LGUI | LALT | LCTRL| LSHFT|      |      |CW TOG| LEFT |  UP  | DOWN |RIGHT|
     * |------+------+------+------+------|      |------+------+------+------+-----|
     * | RGUI | RALT | RCTRL| RSHFT|      |      |  INS | HOME | PGUP | PGDWN| END |
     * `----------------------------------'      `---------------------------------'
     *               .--------------------.      .--------------------.
     *               |      |      |      |      |      |      |      |
     *               '--------------------'      '--------------------'
     */
    [_NAVIGATION] = LAYOUT_split_3x5_3(
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_AGIN, KC_UNDO, KC_CUT,  KC_COPY, KC_PSTE,
      KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,   CW_TOGG, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT,
      KC_RGUI, KC_RALT, KC_RCTL, KC_RSFT, KC_NO,   KC_INS,  KC_HOME, KC_PGUP, KC_PGDN, KC_END,
                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_UNDO
    ),

    /* Keymap 2: Symbols layer
     *
     * ,----------------------------------.      ,----------------------------------.
     * |   `  |   &  |   *  |   -  |      |      |      |   _  |   <  |   >  |   ~  |
     * |------+------+------+------+------|      |------+------+------+------+------|
     * |   :  |   $  |   %  |   ^  |   =  |      |   +  |   (  |   {  |   [  |   ;  |
     * |------+------+------+------+------|      |------+------+------+------+------|
     * |   |  |   !  |   @  |   #  |      |      |      |   )  |   }  |   ]  |   \  |
     * `----------------------------------'      `----------------------------------'
     *               .--------------------.      .--------------------.
     *               |      |      |      |      |      |      |      |
     *               '--------------------'      '--------------------'
     */
    [_SYMBOLS] = LAYOUT_split_3x5_3(
      KC_GRV,  KC_AMPR, KC_ASTR, KC_MINS, KC_NO,    KC_NO, KC_UNDS, KC_LT,   KC_GT,   KC_TILD, 
      KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_EQL,   KC_NO, KC_LPRN, KC_LCBR, KC_LBRC, KC_SCLN, 
      KC_PIPE, KC_EXLM, KC_AT,   KC_HASH, KC_NO,    KC_NO, KC_RPRN, KC_RCBR, KC_RBRC, KC_BSLS,
                        KC_NO,   KC_NO,   KC_NO,    KC_NO, KC_NO,   KC_NO
    ),

    /* Keymap 3: Number layer
     *
     * ,----------------------------------.      ,-------------------------------------.
     * |   /  |   7  |   8  |   9  |   *  |      |      |DM_REC1|DM_REC2|       |      |
     * |------+------+------+------+------|      |------+-------+-------+-------+------|
     * |   .  |   4  |   5  |   6  |   -  |      |      |DM_PLY1|DM_PLY2|DM_RSTP|      |
     * |------+------+------+------+------|      |------+-------+-------+-------+------|
     * |   0  |   1  |   2  |   3  |   +  |      |      |       |       |       |      |
     * `----------------------------------'      `-------------------------------------'
     *               .--------------------.      .--------------------.
     *               |      |      |      |      |      |      |      |
     *               '--------------------'      '--------------------'
     */
    [_NUMBER] = LAYOUT_split_3x5_3(
      KC_SLSH, KC_7, KC_8,  KC_9,  KC_ASTR,   KC_NO, DM_REC1, DM_REC2, KC_NO,   KC_NO, 
      KC_DOT,  KC_4, KC_5,  KC_6,  KC_PMNS,   KC_NO, DM_PLY1, DM_PLY2, DM_RSTP, KC_NO, 
      KC_0,    KC_1, KC_2,  KC_3,  KC_PPLS,   KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO, 
                     KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO,   KC_NO
    ),

    /* Keymap 4: Mouse layer
     *
     * ,----------------------------------.      ,----------------------------------.
     * |      |      |      |      |      |      | ACL0 |MSBTN1|MSBTN2|MSBTN3|MSBTN4|
     * |------+------+------+------+------|      |------+------+------+------+------|
     * |      |      |      |      |      |      | ACL1 | MSLFT| MSUP | MSDWN|MSRGHT|
     * |------+------+------+------+------|      |------+------+------+------+------|
     * |      |      |      |      |      |      | ACL2 |MSWHLL|MSWHLU|MSWHLD|MSWHLR|
     * `----------------------------------'      `----------------------------------'
     *               .--------------------.      .--------------------.
     *               |      |      |      |      |      |      |      |
     *               '--------------------'      '--------------------'
     */
    [_MOUSE] = LAYOUT_split_3x5_3(
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   MS_ACL0, MS_BTN1, MS_BTN2, MS_BTN3, MS_BTN4,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   MS_ACL1, MS_LEFT, MS_UP,   MS_DOWN, MS_RGHT, 
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   MS_ACL2, MS_WHLL, MS_WHLU, MS_WHLD, MS_WHLR,
                    KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO
    ),
    
    /* Keymap 5: Media layer
     *
     * ,----------------------------------.      ,----------------------------------.
     * |      |      |      |      |      |      | STOP | PLAY |      |      |      |
     * |------+------+------+------+------|      |------+------+------+------+------|
     * |      |      |      |      |      |      | PREV | NEXT | VOL+ | VOL- | MUTE |
     * |------+------+------+------+------|      |------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |
     * `----------------------------------'      `----------------------------------'
     *               .--------------------.      .--------------------.
     *               |      |      |      |      |      |      |      |
     *               '--------------------'      '--------------------'
     */
    [_MEDIA] = LAYOUT_split_3x5_3(
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_MSTP, KC_MPLY, KC_NO,   KC_NO,   KC_NO, 
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_MPRV, KC_MNXT, KC_VOLU, KC_VOLD, KC_MUTE,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                    KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO
    ),

    /* Keymap 6: Adjust layer
     *
     * ,----------------------------------.      ,-----------------------------------.
     * |  F12 |  F7  |  F8  |  F9  | PSCRN|      |      |      |      |      |       |
     * |------+------+------+------+------|      |------+------+------+------+-------|
     * |  F11 |  F4  |  F5  |  F6  | SCRLK|      |      |      |      |      |       |
     * |------+------+------+------+------|      |------+------+------+------+-------|
     * |  F10 |  F1  |  F2  |  F3  | PAUSE|      |      |      |      |      |       |
     * `----------------------------------'      `-----------------------------------'
     *               .--------------------.      .--------------------.
     *               |      |      |      |      |      |      |      |
     *               '--------------------'      '--------------------'
     */
    [_ADJUST] = LAYOUT_split_3x5_3(
      KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
      KC_F11, KC_F4, KC_F5, KC_F6, KC_SCRL,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
      KC_F10, KC_F1, KC_F2, KC_F3, KC_PAUS,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
                     KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO
    )
};
