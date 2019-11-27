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
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
#define _WITCHER 4
#define _FROSTPUNK 5

enum custom_keycodes {
  AZERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  WITCHER,
  FROSTPUNK,
  RAZERTY,
  BACKLIT,
  RGBRST,
//  KC_LSCO
//  KC_LSCF
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

#define KC_LCNT MT(MOD_LCTL, KC_SPC)
#define KC_WINT MT(MOD_LGUI, KC_ENT)
#define KC_LSPD MT(MOD_LSFT, KC_5)
#define KC_RSPF MT(MOD_RSFT, KC_MINS)
#define KC_LBRD MT(MOD_LSFT, KC_4)
#define KC_RBRF MT(MOD_RSFT, KC_EQL)
#define KC_WITB MT(MOD_RGUI, KC_TAB)
#define KC_CTEL MT(MOD_RCTL, KC_DEL)
#define KC_RABS MT(MOD_RALT, KC_NUBS)

// tapdance keycodes
enum td_keycodes {
  SHIFT_LB // Our example key: `SHIFT` when held, `[` when tapped. Add additional keycodes for each tapdance.
 ,SHIFT_RB // Our example key: `SHIFT` when held, `]` when tapped. Add additional keycodes for each tapdance.
 ,SHIFT_LC // Our example key: `SHIFT` when held, `}` when tapped. Add additional keycodes for each tapdance.
 ,SHIFT_RC // Our example key: `SHIFT` when held, `}` when tapped. Add additional keycodes for each tapdance.

};

// define a type containing as many tapdance states as you need
typedef enum {
  SINGLE_TAP,
  SINGLE_HOLD,
} td_state_t;

// create a global instance of the tapdance state type
static td_state_t td_state;

// declare your tapdance functions:

// function to determine the current tapdance state
int cur_dance (qk_tap_dance_state_t *state);

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


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_AZERTY] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
     KC_ESC,  KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,                   KC_Y,  KC_U,  KC_I,  KC_O,  KC_P,KC_BSPC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     KC_WITB,  KC_A,  KC_S,  KC_D,  KC_F,  KC_G,                   KC_H,  KC_J,  KC_K,  KC_L,KC_SCLN,KC_CTEL,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    KC_LSPD,  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,                   KC_N,  KC_M,KC_COMM,KC_DOT,KC_SLSH,KC_RSPF,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                KC_LALT, LOWER,KC_WINT,   KC_LCNT, RAISE,KC_RABS \
                              //`--------------------'  `--------------------'
  ),

  [_LOWER] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
     KC_ESC,KC_PSLS, KC_P7, KC_P8, KC_P9,KC_PMNS,               KC_6,  KC_7,  KC_8,  KC_9,  KC_0,KC_BSPC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     KC_WITB,KC_PDOT,KC_P4, KC_P5, KC_P6,KC_PPLS,            RALT(KC_6),RALT(KC_7),RALT(KC_8),RALT(KC_9),RALT(KC_0),KC_CTEL,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
 TD(SHIFT_LB),KC_P0, KC_P1, KC_P2, KC_P3,KC_PAST,           KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,TD(SHIFT_RB),\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                 KC_EQL, LOWER,KC_WINT,   KC_LCNT, RAISE,KC_RABS \
                              //`--------------------'  `--------------------'
  ),

  [_RAISE] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
     KC_ESC,  KC_1,  KC_2,  KC_3,  KC_4,  KC_5,                 KC_HOME,KC_PGUP, KC_UP,KC_PGDN,KC_END,KC_BSPC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
KC_WITB,RALT(KC_1),RALT(KC_2),RALT(KC_3),RALT(KC_4),RALT(KC_5), KC_INS,KC_LEFT,KC_DOWN,KC_RIGHT,KC_RBRC,KC_CTEL,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
 TD(SHIFT_LC),KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                KC_F11,KC_F12,KC_QUOT,KC_NUHS,KC_LBRC,TD(SHIFT_RC),\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                KC_LALT, LOWER,KC_WINT,   KC_LCNT, RAISE,KC_RABS \
                              //`--------------------'  `--------------------'
  ),

  [_ADJUST] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
    RESET, KC_NLCK,KC_MUTE,KC_VOLD,KC_VOLU,KC_F20,             WITCHER,FROSTPUNK,KC_BRID, KC_BRIU,KC_PSCR,KC_PAUS,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
RGB_TOG,KC_INS,LGUI(KC_MUTE),LGUI(KC_VOLD),LGUI(KC_VOLU),KC_NO, KC_NO,KC_NO,LGUI(KC_BRID),LGUI(KC_BRIU),KC_NO,KC_SLCK,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    RGB_MOD,RGB_HUD,RGB_HUI,RGB_SAD,RGB_SAI,RGBRST,            RGB_VAD,RGB_VAI,KC_NO, KC_NO, KC_NO, KC_NO,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                KC_LGUI, LOWER,KC_WINT,   KC_LCNT, RAISE,KC_RABS \
                              //`--------------------'  `--------------------'
  ),

  [_WITCHER] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
     KC_ESC,  KC_1,  KC_2,  KC_3,  KC_4,  KC_I,                 KC_2,  KC_Q,  KC_W,  KC_E,  KC_R,  KC_Y,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     KC_NO, KC_NO, KC_UP, KC_F5, KC_S,   KC_M,                  KC_1,  KC_A,  KC_S,  KC_D,  KC_F,  KC_TAB,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
     KC_NO,KC_LEFT,KC_DOWN,KC_RGHT,KC_V, KC_J,                  KC_X,  KC_C,KC_PGUP,KC_PGDN,KC_T,KC_LSFT,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                RAZERTY, KC_NO,KC_ENT,   KC_SPC,KC_LALT,KC_M \
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
                                RAZERTY, KC_NO,KC_ENT,   KC_SPC,KC_LALT,KC_M \
                              //`--------------------'  `--------------------'
  )
};

// determine the tapdance state to return
int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed) { return SINGLE_TAP; }
    else { return SINGLE_HOLD; }
  }
  else { return 2; } // any number higher than the maximum state value you return above
}
 
// handle the possible states for each tapdance keycode you define:

void shiftlb_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance(state);
  switch (td_state) {
    case SINGLE_TAP:
      register_mods(MOD_BIT(KC_RALT)); 
      register_code16(KC_5);
      break;
    case SINGLE_HOLD:
      register_mods(MOD_BIT(KC_LSFT)); // for a layer-tap key, use `layer_on(_MY_LAYER)` here
      break;
  }
}

void shiftrb_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance(state);
  switch (td_state) {
    case SINGLE_TAP:
      register_mods(MOD_BIT(KC_RALT)); 
      register_code16(KC_MINS);
      break;
    case SINGLE_HOLD:
      register_mods(MOD_BIT(KC_RSFT)); // for a layer-tap key, use `layer_on(_MY_LAYER)` here
      break;
  }
}

void shiftlb_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td_state) {
    case SINGLE_TAP:
      unregister_code16(RALT(KC_5));
      unregister_mods(MOD_BIT(KC_RALT)); 
      break;
    case SINGLE_HOLD:
      unregister_mods(MOD_BIT(KC_LSFT)); // for a layer-tap key, use `layer_off(_MY_LAYER)` here
      break;
  }
}

void shiftrb_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td_state) {
    case SINGLE_TAP:
      unregister_code16(RALT(KC_MINS));
      unregister_mods(MOD_BIT(KC_RALT)); 
      break;
    case SINGLE_HOLD:
      unregister_mods(MOD_BIT(KC_RSFT)); // for a layer-tap key, use `layer_off(_MY_LAYER)` here
      break;
  }
}

void shiftlc_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance(state);
  switch (td_state) {
    case SINGLE_TAP:
      register_mods(MOD_BIT(KC_RALT)); 
      register_code16(KC_4);
      break;
    case SINGLE_HOLD:
      register_mods(MOD_BIT(KC_LSFT)); // for a layer-tap key, use `layer_on(_MY_LAYER)` here
      break;
  }
}

void shiftrc_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance(state);
  switch (td_state) {
    case SINGLE_TAP:
      register_mods(MOD_BIT(KC_RALT)); 
      register_code16(KC_EQL);
      break;
    case SINGLE_HOLD:
      register_mods(MOD_BIT(KC_RSFT)); // for a layer-tap key, use `layer_on(_MY_LAYER)` here
      break;
  }
}

void shiftlc_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td_state) {
    case SINGLE_TAP:
      unregister_code16(RALT(KC_4));
      unregister_mods(MOD_BIT(KC_RALT)); 
      break;
    case SINGLE_HOLD:
      unregister_mods(MOD_BIT(KC_LSFT)); // for a layer-tap key, use `layer_off(_MY_LAYER)` here
      break;
  }
}

void shiftrc_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td_state) {
    case SINGLE_TAP:
      unregister_code16(RALT(KC_EQL));
      unregister_mods(MOD_BIT(KC_RALT)); 
      break;
    case SINGLE_HOLD:
      unregister_mods(MOD_BIT(KC_RSFT)); // for a layer-tap key, use `layer_off(_MY_LAYER)` here
      break;
  }
}

// define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions
qk_tap_dance_action_t tap_dance_actions[] = {
  [SHIFT_LB] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, shiftlb_finished, shiftlb_reset, 120)
 ,[SHIFT_RB] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, shiftrb_finished, shiftrb_reset, 120)
 ,[SHIFT_LC] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, shiftlc_finished, shiftlc_reset, 120)
 ,[SHIFT_RC] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, shiftrc_finished, shiftrc_reset, 120)
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
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
    case RAZERTY:
        if (record->event.pressed) {
          layer_off(_WITCHER);
          layer_off(_FROSTPUNK);
	}
        return false;
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
  }
  return true;
}
