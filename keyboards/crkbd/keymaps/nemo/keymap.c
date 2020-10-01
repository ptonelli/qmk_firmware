#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _AZERTY 0
#define _ANDROID 1
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 4
#define _WITCHER 5
#define _FROSTPUNK 6
#define _GAME 7
#define _GAME_RAISE 8
#define _MIDI 9

enum custom_keycodes {
  AZERTY = SAFE_RANGE,
  ANDROID,
  LOWER,
  RAISE,
  ADJUST,
  WITCHER,
  FROSTPUNK,
  GAME,
  GRAISE,
  MIDI,
  RAZERTY,
  BACKLIT,
  RGBRST,
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

#define KC_LCNT MT(MOD_LCTL, KC_SPC)
#define KC_WINT MT(MOD_LGUI, KC_ENT)
#define KC_LANT MT(MOD_LALT, KC_ENT)
#define KC_LSPD MT(MOD_LSFT, KC_5)
#define KC_RSPF MT(MOD_RSFT, KC_MINS)
#define KC_LBRD MT(MOD_LSFT, KC_4)
#define KC_RBRF MT(MOD_RSFT, KC_EQL)
#define KC_WITB MT(MOD_RGUI, KC_TAB)
#define KC_LATB MT(MOD_LALT, KC_TAB)
#define KC_CTEL MT(MOD_RCTL, KC_DEL)
#define KC_RF12 MT(MOD_RALT, KC_F12)

// tapdance keycodes
enum td_keycodes {
  SHIFT_LB // Our example key: `SHIFT` when held, `[` when tapped. Add additional keycodes for each tapdance.
 ,SHIFT_RB // Our example key: `SHIFT` when held, `]` when tapped. Add additional keycodes for each tapdance.
 ,SHIFT_LC // Our example key: `SHIFT` when held, `{` when tapped. Add additional keycodes for each tapdance.
 ,SHIFT_RC // Our example key: `SHIFT` when held, `}` when tapped. Add additional keycodes for each tapdance.
 ,SHIFT_LA // Our example key: `SHIFT` when held, `<` when tapped. Add additional keycodes for each tapdance.
 ,SHIFT_RA // Our example key: `SHIFT` when held, `>` when tapped. Add additional keycodes for each tapdance.
 ,LOWER_TD // Our example key: `LOWER` when held, LGUI + `LOWER` when double held.
};

// define a type containing as many tapdance states as you need
typedef enum {
  SINGLE_TAP,
  SINGLE_HOLD,
  DOUBLE_HOLD,
} td_state_t;

// create a global instance of the tapdance state type
static td_state_t td_state;

// declare your tapdance functions:

// function to determine the current tapdance state
int cur_dance_layer (qk_tap_dance_state_t *state);
int cur_dance_shift (qk_tap_dance_state_t *state);

// `finished` and `reset` functions for each tapdance keycode
void shiftlb_finished (qk_tap_dance_state_t *state, void *user_data);
void shiftlb_reset (qk_tap_dance_state_t *state, void *user_data);

// `finished` and `reset` functions for each tapdance keycode
void shiftrb_finished (qk_tap_dance_state_t *state, void *user_data);
void shiftrb_reset (qk_tap_dance_state_t *state, void *user_data);

// `finished` and `reset` functions for each tapdance keycode
void shiftlc_finished (qk_tap_dance_state_t *state, void *user_data);
void shiftlc_reset (qk_tap_dance_state_t *state, void *user_data);

// `finished` and `reset` functions for each tapdance keycode
void shiftrc_finished (qk_tap_dance_state_t *state, void *user_data);
void shiftrc_reset (qk_tap_dance_state_t *state, void *user_data);

// `finished` and `reset` functions for each tapdance keycode
void shiftla_finished (qk_tap_dance_state_t *state, void *user_data);
void shiftla_reset (qk_tap_dance_state_t *state, void *user_data);

// `finished` and `reset` functions for each tapdance keycode
void shiftra_finished (qk_tap_dance_state_t *state, void *user_data);
void shiftra_reset (qk_tap_dance_state_t *state, void *user_data);

// `finished` and `reset` functions for each tapdance keycode
void lowertd_finished (qk_tap_dance_state_t *state, void *user_data);
void lowertd_reset (qk_tap_dance_state_t *state, void *user_data);



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_AZERTY] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
     KC_ESC,  KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,                   KC_Y,  KC_U,  KC_I,  KC_O,  KC_P,KC_BSPC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     KC_WITB,  KC_A,  KC_S,  KC_D,  KC_F,  KC_G,                   KC_H,  KC_J,  KC_K,  KC_L,KC_SCLN,KC_CTEL,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    KC_LSPD,  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,                   KC_N,  KC_M,KC_COMM,KC_DOT,KC_SLSH,KC_RSPF,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                KC_LALT,TD(LOWER_TD),KC_WINT,   KC_SPC, RAISE,KC_RALT \
                              //`--------------------'  `--------------------'
  ),

  [_ANDROID] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
    _______,_______,_______,_______,_______,_______,           _______,_______,_______,_______,_______,_______,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    KC_LATB,_______,_______,_______,_______,_______,           _______,_______,_______,_______,_______,_______,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    KC_LSFT,_______,_______,_______,_______,_______,           _______,_______,_______,_______,_______,KC_RSFT,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                RAZERTY,_______,KC_LANT,   _______,_______,_______ \
                              //`--------------------'  `--------------------'
  ),


  [_LOWER] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
    _______,KC_1,  KC_2,  KC_3,  KC_4,  KC_5,                  KC_6,  KC_7,  KC_8,  KC_9,  KC_0,_______,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    _______,RSFT(KC_1),RSFT(KC_2),RSFT(KC_3),RSFT(KC_4),RSFT(KC_5),RSFT(KC_6),RSFT(KC_7),RSFT(KC_8),RSFT(KC_9),RSFT(KC_0) ,_______,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
 TD(SHIFT_LC),RALT(KC_1),RALT(KC_2),RALT(KC_3),RALT(KC_4),RALT(KC_5),RALT(KC_6),RALT(KC_7),RALT(KC_8),RALT(KC_9),RALT(KC_0),TD(SHIFT_RC),\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                               _______,_______,_______, _______,_______,_______ \
                              //`--------------------'  `--------------------'
  ),

  [_RAISE] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
  _______,KC_1,  KC_2,  KC_3,  KC_4,  KC_5,                    KC_HOME,KC_PGUP, KC_UP,KC_PGDN,KC_END,_______,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
  _______,_______, _______, _______, _______,_______,          KC_INS,KC_LEFT,KC_DOWN,KC_RIGHT,_______,_______,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
 TD(SHIFT_LB),KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,TD(SHIFT_RB),\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                KC_F11,_______,_______,   _______, RAISE,KC_RF12 \
                              //`--------------------'  `--------------------'
  ),

  [_ADJUST] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
    C(A(KC_DEL)), KC_NLCK,KC_MUTE,KC_VOLD,KC_VOLU,KC_F20,     WITCHER,FROSTPUNK,KC_BRIU, KC_MINS,KC_EQL,_______,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
RGB_TOG,KC_PSCR,LGUI(KC_MUTE),LGUI(KC_VOLD),LGUI(KC_VOLU),MIDI,   GAME,ANDROID,KC_BRID,KC_LBRC,KC_RBRC,_______,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
 TD(SHIFT_LA),RGB_MOD,RGB_HUI,RGB_SAD,RGB_SAI,RGBRST,            RGB_VAD,RGB_VAI,RGB_SPD,KC_QUOT,KC_NUHS,TD(SHIFT_RA),\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                KC_LALT,_______,_______,_______,_______,KC_RALT \
                              //`--------------------'  `--------------------'
  ),

  [_WITCHER] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
     KC_ESC,  KC_1,  KC_2,  KC_3,  KC_4,  KC_I,                 KC_2,  KC_Q,  KC_W,  KC_E,  KC_R,  KC_Y,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      KC_NO, KC_NO, KC_UP, KC_F5, KC_S,KC_SCLN,                   KC_1, KC_A,   KC_S,  KC_D,  KC_F,KC_TAB,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     KC_NO,KC_LEFT,KC_DOWN,KC_RGHT,KC_V, KC_J,                  KC_X,  KC_C,KC_PGUP,KC_PGDN,KC_T,KC_LSFT,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                RAZERTY,_______,KC_ENT,   KC_SPC,KC_LALT,KC_M \
                              //`--------------------'  `--------------------'
  ),
  [_FROSTPUNK] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
     KC_ESC,  KC_1,  KC_2,  KC_3,  KC_4,  KC_I,                   KC_R, KC_Q,  KC_W,  KC_E, KC_T,  KC_Y,\
  //|------+------+------+------+------+------|                |------+----+------+------+-------+------|
     KC_NO, KC_NO, KC_UP, KC_F5, KC_S,   KC_M,                    KC_F, KC_A,  KC_S,  KC_D, KC_G,  KC_TAB,\
  //|------+------+------+------+------+------|                |------+----+------+------+-------+------|
     KC_NO,KC_LEFT,KC_DOWN,KC_RGHT,KC_V, KC_J,                    KC_V, KC_Z,  KC_X,  KC_C, KC_B,KC_LSFT,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                RAZERTY,_______,KC_ENT,   KC_SPC,RAISE,KC_M \
                              //`--------------------'  `--------------------'
  ),
  [_GAME] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
    _______,_______,_______,_______,_______,_______,           _______,_______,KC_UP,_______,_______,KC_INS,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    KC_TAB,_______,_______,_______,_______,_______,           _______,KC_LEFT,KC_DOWN,KC_RIGHT,KC_L,KC_DEL,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    KC_LSFT,_______,_______,_______,_______,_______,           KC_B,KC_N,_______,_______,_______,KC_RSFT,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                KC_LALT,KC_RALT,KC_ENT,   _______,KC_RCTL,GRAISE \
                              //`--------------------'  `--------------------'
  ),
  [_GAME_RAISE] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
    RAZERTY,  KC_1,  KC_2,  KC_3,  KC_4,  KC_5,                   KC_1,  KC_2,  KC_I,  KC_4,  KC_5,KC_INS,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    _______,  KC_6,  KC_7,  KC_8,  KC_9,  KC_0,                   KC_6,  KC_J,  KC_K,  KC_L,  KC_0,KC_DEL,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                  KC_F6, KC_F7, KC_F8, KC_F9,KC_F10,KC_RSFT,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                _______,_______,_______,   _______,KC_RCTL,_______ \
                              //`--------------------'  `--------------------'
  ),


  [_MIDI] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
     MI_CHU, KC_NO, MI_Cs, MI_Ds, KC_NO, MI_Fs,                  MI_Gs, MI_As,KC_NO,MI_Cs_1,MI_Ds_1,KC_NO,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     MI_MOD,  MI_C,  MI_D,  MI_E,  MI_F,  MI_G,                   MI_A,  MI_B,MI_C_1,MI_D_1,MI_E_1,MI_F_1,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    MI_SUS,MI_OCTD,MI_OCTU,MI_MODSD,MI_MODSU,KC_NO,            KC_NO,KC_NO,MI_TRNSD,MI_TRNSU,MI_TRNS_0,MI_SUS,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                RAZERTY, MI_OCTD,MI_ALLOFF,   MI_SUS, MI_OCTU,KC_NO \
                              //`--------------------'  `--------------------'
  ),

};

// determine the tapdance state to return for layer keys
int cur_dance_layer (qk_tap_dance_state_t *state) {
  if (state->count == 1)
    { return SINGLE_HOLD; }
  if (state->count >= 2)
    { return DOUBLE_HOLD; }
  else { return 3; } // any number higher than the maximum state value you return above
}

// determine the tapdance state to return for shift keys
int cur_dance_shift (qk_tap_dance_state_t *state) {
  if (state->count >= 1) {
    if (state->interrupted || !state->pressed) { return SINGLE_TAP; }
    else { return SINGLE_HOLD; }
  }
  else { return 3; } // any number higher than the maximum state value you return above
}

// handle the possible states for each tapdance keycode you define:

void shiftlb_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance_shift(state);
  switch (td_state) {
    case SINGLE_TAP:
      register_mods(MOD_BIT(KC_RALT)); 
      register_code16(KC_5);
      break;
    case SINGLE_HOLD:
      register_mods(MOD_BIT(KC_LSFT)); // for a layer-tap key, use `layer_on(_MY_LAYER)` here
      break;
    default:
      break;
  }
}

void shiftrb_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance_shift(state);
  switch (td_state) {
    case SINGLE_TAP:
      register_mods(MOD_BIT(KC_RALT)); 
      register_code16(KC_MINS);
      break;
    case SINGLE_HOLD:
      register_mods(MOD_BIT(KC_RSFT)); // for a layer-tap key, use `layer_on(_MY_LAYER)` here
      break;
    default:
      break;
  }
}

void shiftlb_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td_state) {
    case SINGLE_TAP:
      unregister_code16(KC_5);
      unregister_mods(MOD_BIT(KC_RALT)); 
      break;
    case SINGLE_HOLD:
      unregister_mods(MOD_BIT(KC_LSFT)); // for a layer-tap key, use `layer_off(_MY_LAYER)` here
      break;
    default:
      break;
  }
}

void shiftrb_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td_state) {
    case SINGLE_TAP:
      unregister_code16(KC_MINS);
      unregister_mods(MOD_BIT(KC_RALT)); 
      break;
    case SINGLE_HOLD:
      unregister_mods(MOD_BIT(KC_RSFT)); // for a layer-tap key, use `layer_off(_MY_LAYER)` here
      break;
    default:
      break;
  }
}

void shiftlc_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance_shift(state);
  switch (td_state) {
    case SINGLE_TAP:
      register_mods(MOD_BIT(KC_RALT)); 
      register_code16(KC_4);
      break;
    case SINGLE_HOLD:
      register_mods(MOD_BIT(KC_LSFT)); // for a layer-tap key, use `layer_on(_MY_LAYER)` here
      break;
    default:
      break;
  }
}

void shiftrc_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance_shift(state);
  switch (td_state) {
    case SINGLE_TAP:
      register_mods(MOD_BIT(KC_RALT)); 
      register_code16(KC_EQL);
      break;
    case SINGLE_HOLD:
      register_mods(MOD_BIT(KC_RSFT)); // for a layer-tap key, use `layer_on(_MY_LAYER)` here
      break;
    default:
      break;
  }
}

void shiftlc_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td_state) {
    case SINGLE_TAP:
      unregister_code16(KC_4);
      unregister_mods(MOD_BIT(KC_RALT));
      break;
    case SINGLE_HOLD:
      unregister_mods(MOD_BIT(KC_LSFT)); // for a layer-tap key, use `layer_off(_MY_LAYER)` here
      break;
    default:
      break;
  }
}

void shiftrc_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td_state) {
    case SINGLE_TAP:
      unregister_code16(KC_EQL);
      unregister_mods(MOD_BIT(KC_RALT));
      break;
    case SINGLE_HOLD:
      unregister_mods(MOD_BIT(KC_RSFT)); // for a layer-tap key, use `layer_off(_MY_LAYER)` here
      break;
    default:
      break;
  }
}

void shiftla_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance_shift(state);
  switch (td_state) {
    case SINGLE_TAP:
      register_code16(KC_NUBS);
      break;
    case SINGLE_HOLD:
      register_mods(MOD_BIT(KC_LSFT)); // for a layer-tap key, use `layer_on(_MY_LAYER)` here
      break;
    default:
      break;
  }
}

void shiftra_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance_shift(state);
  switch (td_state) {
    case SINGLE_TAP:
      register_mods(MOD_BIT(KC_RSFT));
      register_code16(KC_NUBS);
      break;
    case SINGLE_HOLD:
      register_mods(MOD_BIT(KC_RSFT)); // for a layer-tap key, use `layer_on(_MY_LAYER)` here
      break;
    default:
      break;
  }
}

void shiftla_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td_state) {
    case SINGLE_TAP:
      unregister_code16(KC_NUBS);
      break;
    case SINGLE_HOLD:
      unregister_mods(MOD_BIT(KC_LSFT)); // for a layer-tap key, use `layer_off(_MY_LAYER)` here
      break;
    default:
      break;
  }
}

void shiftra_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td_state) {
    case SINGLE_TAP:
      unregister_code16(KC_NUBS);
      unregister_mods(MOD_BIT(KC_RSFT));
      break;
    case SINGLE_HOLD:
      unregister_mods(MOD_BIT(KC_RSFT)); // for a layer-tap key, use `layer_off(_MY_LAYER)` here
      break;
    default:
      break;
  }
}



int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    //matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void lowertd_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance_layer(state);
  switch (td_state) {
    case SINGLE_HOLD:
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      break;
    case DOUBLE_HOLD:
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
        register_mods(MOD_BIT(KC_LGUI));
      break;
    default:
      break;
  }
}

void lowertd_reset (qk_tap_dance_state_t *state, void *user_data) {
        unregister_mods(MOD_BIT(KC_LGUI));
        layer_off(_LOWER);
        layer_off(_ADJUST);
}


// define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions
qk_tap_dance_action_t tap_dance_actions[] = {
  [SHIFT_LB] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, shiftlb_finished, shiftlb_reset, 90)
 ,[SHIFT_RB] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, shiftrb_finished, shiftrb_reset, 90)
 ,[SHIFT_LC] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, shiftlc_finished, shiftlc_reset, 90)
 ,[SHIFT_RC] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, shiftrc_finished, shiftrc_reset, 90)
 ,[SHIFT_LA] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, shiftla_finished, shiftla_reset, 90)
 ,[SHIFT_RA] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, shiftra_finished, shiftra_reset, 90)
 ,[LOWER_TD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lowertd_finished, lowertd_reset)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case AZERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_AZERTY);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case ANDROID:
        if (record->event.pressed) {
          layer_on(_ANDROID);
	}
        return false;

    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
    case WITCHER:
        if (record->event.pressed) {
          layer_on(_WITCHER);
	}
        return false;
    case FROSTPUNK:
        if (record->event.pressed) {
          layer_on(_FROSTPUNK);
	}
        return false;
    case GAME:
        if (record->event.pressed) {
          layer_on(_GAME);
	}
        return false;
    case GRAISE:
      if (record->event.pressed) {
        layer_on(_GAME_RAISE);
      } else {
        layer_off(_GAME_RAISE);
      }
      return false;
    case MIDI:
        if (record->event.pressed) {
          layer_on(_MIDI);
	}
        return false;
    case RAZERTY:
        if (record->event.pressed) {
          layer_off(_ANDROID);
          layer_off(_WITCHER);
          layer_off(_FROSTPUNK);
          layer_off(_GAME);
          layer_off(_MIDI);
	}
        return false;
      #ifdef RGBLIGHT_ENABLE
    case RGB_MOD:
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      return false;
    case RGBRST:
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      break;
      #endif
  }
  return true;
}
