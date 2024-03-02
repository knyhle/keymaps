
#include QMK_KEYBOARD_H

enum planck_layers {
  _DVORAK,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  DVORAK = SAFE_RANGE,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   ;  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   '  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
    [_DVORAK] = LAYOUT_planck_grid(
        KC_ESC,  KC_SCLN,     KC_COMM, KC_DOT,  KC_P,   KC_Y,   KC_F,   KC_G,   KC_C,    KC_R,    KC_L,   KC_BSPC,
        LCTL_T(KC_TAB),  KC_A,        KC_O,    KC_E,    KC_U,   KC_I,   KC_D,   KC_H,   KC_T,    KC_N,    KC_S,   RCTL_T(KC_ENT),
        SC_LSPO, KC_QUOT,     KC_Q,    KC_J,    KC_K,   KC_X,   KC_B,   KC_M,   KC_W,    KC_V,    KC_Z,   SC_RSPC,
        KC_LCTL, MO(_ADJUST), KC_LGUI, KC_LALT, LT(_LOWER, KC_LBRC), KC_SPC, KC_SPC,  LT(_RAISE, KC_RBRC), KC_RALT,  _______, MO(_ADJUST), KC_RCTL
    ),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   /  |   \  |   `  |   |  | Esc  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |   +  |   [  |  {   |   (  |   &  |  =   |   )  |  }   |   ]  |   *  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |      |      |  F5  |  F6  |  F7  | F8   |  F9  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_SLSH, KC_BSLS, KC_GRV,  KC_PIPE, KC_BSPC,
    KC_DEL,  KC_PLUS, KC_LBRC, KC_LCBR, KC_LPRN, KC_AMPR, KC_EQL,  KC_RPRN, KC_RCBR, KC_RBRC, KC_ASTR, KC_MINS,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_UNDS,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |             |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_SLSH, KC_BSLS, KC_GRV,  KC_PIPE, KC_BSPC,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,     KC_9,    KC_0,    KC_MINS,
    _______, _______, _______, KC_DOWN, KC_UP,   _______, _______, KC_LEFT, KC_RIGHT, _______, _______, KC_UNDS,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |Reset | Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|      |      |Qwerty|      |Dvorak|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    QK_BOOT, DB_TOGG, _______, _______, DVORAK,  _______, _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, _______,
    _______, _______, _______, AU_ON,   AU_OFF,  _______, _______, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  /* return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); */
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DVORAK:
      if (record->event.pressed) {
        /* set_single_persistent_default_layer(_DVORAK); */
        layer_clear();
      }
      return false;
      break;
  }
  return true;
}


