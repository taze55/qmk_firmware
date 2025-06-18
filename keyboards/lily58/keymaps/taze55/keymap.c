#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _LOWER = 1,
  _RAISE = 2,
  _ADJUST = 3,
  _QWERTY2 = 4,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|  F11  |    | RGTab |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | / ESC   /       \Space \  |RAISE | RAlt | CapL |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_QWERTY] = LAYOUT(
  KC_ESC,  KC_1, KC_2, KC_3,    KC_4,    KC_5,                              KC_6,       KC_7,    KC_8,    KC_9,   KC_0,    KC_DEL, 
  KC_TAB,  KC_Q, KC_W, KC_E,    KC_R,    KC_T,                              KC_Y,       KC_U,    KC_I,    KC_O,   KC_P,    KC_BSPC,
  KC_LCTL, KC_A, KC_S, KC_D,    KC_F,    KC_G,                              KC_H,       KC_J,    KC_K,    KC_L,   KC_SCLN, KC_ENT, 
  KC_LSFT, KC_Z, KC_X, KC_C,    KC_V,    KC_B,       KC_F11,  RGUI(KC_TAB), KC_N,       KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                       KC_LALT, KC_LGUI, MO(_LOWER), KC_ESC,  KC_SPC,       MO(_RAISE), KC_RALT, KC_CAPS
),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  | F9   | F10  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Lock |LG(W) |      |LG(@) |CtPgUp|                    | Home |   {  |   }  | AINS | F11  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |SSClip|LShift| LGUI | LAlt |CtPgDn|-------.    ,-------| Left | Down |  UP  |Right | F12  |RG(S) |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |SSFile|LG(X) |LG(C) |SAG(V)|      |-------|    |-------| End  |   [  |   ]  |SAINS | CINS |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |    ※CSINSも兼ねる(VSCodeなどで)
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  _______, KC_F1        , KC_F2     , KC_F3     , KC_F4          , KC_F5        ,                   KC_F6  , KC_F7  , KC_F8  , KC_F9       , KC_F10,       _______   ,
  _______, G(C(KC_Q))   , LGUI(KC_W), _______   , LGUI(KC_AT)    , LCTL(KC_PGUP),                   KC_HOME, KC_LCBR, KC_RCBR, LALT(KC_INS), KC_F11,       _______   ,
  _______, G(C(S(KC_4))), KC_LSFT   , KC_LGUI   , KC_LALT        , LCTL(KC_PGDN),                   KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT    , KC_F12,       RGUI(KC_S),
  _______, G(S(KC_4))   , LGUI(KC_X), LGUI(KC_C), LSA(LGUI(KC_V)), _______      , _______, _______, KC_END , KC_LBRC, KC_RBRC, RSA(KC_INS) , RCTL(KC_INS), _______   ,
                                      _______   , _______        , _______      , _______, _______, _______, _______, _______
),

/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | PSCR |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  |      |
 * |------+------+------+------+------+------.                    ,------+------+------+------+------+------|
 * |AltTab|      |   ~  |   (  |   )  |   `  |                    |      | AF16 |SAF16 |CSF16 |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |   =  |   "  |   '  |-------.    ,-------|      |CtPgDn|CtPgUp| F16  | CTRL |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |   \  |   |  |   +  |   -  |   _  |-------|    |-------|      | CF16 |CAF16 |CSAF16|      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      | ※このF16の入力ソース切り替えはCTRLやALTなどとの組み合わせにすると
 *                   |      |      |      |/       /         \      \ |      |      |      |   なぜかqmk_firmwareが2回反応して戻されることがある？macOS側の仕様？
 *                   `----------------------------'           '------''--------------------'   InsertはKarabinderで予約済み
 */
[_RAISE] = LAYOUT(
  KC_PSCR     , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                   KC_F6  , KC_F7        , KC_F8        , KC_F9      ,  KC_F10              , _______,
  LALT(KC_TAB), _______, KC_TILD, KC_LPRN, KC_RPRN, KC_GRV ,                   _______, LALT(KC_F16) , RSA(KC_F16)  , RCS(KC_F16), _______              , _______,
  _______     , _______, _______, KC_EQL , KC_DQT , KC_QUOT,                   _______, LCTL(KC_PGDN), LCTL(KC_PGUP), KC_F16     , LM(_QWERTY2,MOD_LCTL), _______,
  _______     , KC_BSLS, KC_PIPE, KC_PLUS, KC_MINS, KC_UNDS, _______, _______, _______, LCTL(KC_F16) , LCA(KC_F16)  , MEH(KC_F16), _______              , _______,
                                  _______, _______, _______, _______, _______, _______, _______      , _______
),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
),

/* QWERTY2
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|  F11  |    | RGTab |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | / ESC   /       \Space \  |RAISE | RAlt | CapL |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_QWERTY2] = LAYOUT(
  KC_ESC,  KC_1, KC_2, KC_3,    KC_4,    KC_5,                              KC_6,       KC_7,    KC_8,    KC_9,   KC_0,    KC_DEL, 
  KC_TAB,  KC_Q, KC_W, KC_E,    KC_R,    KC_T,                              KC_Y,       KC_U,    KC_I,    KC_O,   KC_P,    KC_BSPC,
  KC_LCTL, KC_A, KC_S, KC_D,    KC_F,    KC_G,                              KC_H,       KC_J,    KC_K,    KC_L,   KC_SCLN, KC_ENT, 
  KC_LSFT, KC_Z, KC_X, KC_C,    KC_V,    KC_B,       KC_F11,  RGUI(KC_TAB), KC_N,       KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                       KC_LALT, KC_LGUI, MO(_LOWER), KC_ESC,  KC_SPC,       MO(_RAISE), KC_RALT, KC_CAPS
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
