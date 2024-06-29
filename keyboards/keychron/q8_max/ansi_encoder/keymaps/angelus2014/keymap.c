#include QMK_KEYBOARD_H
#include "keychron_common.h"

enum layers {
    MAC_BASE,
    WIN_BASE,
    MAC_FN1,
    WIN_FN1,
    FN2,
};

// Tap Dance declarations
enum {
    TD_ESC_CAPS,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_69(
        TD(TD_ESC_CAPS), KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_MUTE,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
        HYPR_T(KC_CAPS), MT(MOD_LSFT,KC_A), MT(MOD_LCTL, KC_S), MT(MOD_LALT, KC_D), MT(MOD_LGUI, KC_F), KC_G, KC_H, MT(MOD_RGUI, KC_J), MT(MOD_RALT, KC_K), MT(MOD_RCTL, KC_L), MT(MOD_RSFT,KC_SCLN), KC_QUOT, KC_ENT, KC_HOME,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, MT(MOD_LCTL | MOD_LALT | MOD_LGUI,KC_B), MT(MOD_LCTL | MOD_LALT | MOD_LGUI,KC_B), KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP,
        KC_LCTL, KC_LOPTN, KC_LCMMD, LT(MAC_FN1,KC_BSPC), TG(MAC_FN1), TG(FN2), LT(FN2,KC_SPC), KC_RCMMD, KC_LEFT, KC_DOWN, KC_RGHT),

    [WIN_BASE] = LAYOUT_ansi_69(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_INS,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
        KC_CAPS, MT(MOD_LSFT,KC_A), MT(MOD_LCTL, KC_S), MT(MOD_LGUI, KC_D), MT(MOD_LALT, KC_F), KC_G, KC_H, MT(MOD_RALT, KC_J), MT(MOD_RGUI, KC_K), MT(MOD_RCTL, KC_L), MT(MOD_RSFT,KC_SCLN), KC_QUOT, KC_ENT, KC_HOME,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP,
        KC_LCTL, KC_LWIN, KC_LALT, KC_BSPC, MO(WIN_FN1), MO(FN2), KC_SPC, KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT),

    [MAC_FN1] = LAYOUT_ansi_69(
        KC_GRV, KC_BRID, KC_BRIU, KC_NO, KC_NO, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS, QK_BOOT,
        RGB_TOG, BT_HST1, BT_HST2, BT_HST3, P2P4G, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_PGDN, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MAGIC_TOGGLE_NKRO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    [WIN_FN1] = LAYOUT_ansi_69(
        KC_GRV, KC_BRID, KC_BRIU, KC_TASK, KC_FILE, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS,
        RGB_TOG, BT_HST1, BT_HST2, BT_HST3, P2P4G, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_PGDN, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MAGIC_TOGGLE_NKRO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    [FN2] = LAYOUT_ansi_69(
        S(KC_GRV), KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_TRNS,
        KC_TRNS, BT_HST1, BT_HST2, BT_HST3, P2P4G, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_LCTL, KC_LALT, KC_LGUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, LCA(KC_C), KC_TRNS, BAT_LVL, BAT_LVL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [MAC_FN1]  = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [WIN_FN1]  = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [FN2]      = {ENCODER_CCW_CW(KC_RIGHT, KC_LEFT)},
};
#endif // ENCODER_MAP_ENABLE

// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }
    return true;
}
