#include QMK_KEYBOARD_H
#include "muse.h"


//mod tap keys
#define SHFZ MT(MOD_LSFT, KC_Z)
#define SHFS MT(MOD_RSFT, KC_SLASH)

//workspace shifting keys
#define WK1 LALT(KC_1)
#define WK2 LALT(KC_2)
#define WK3 LALT(KC_3)
#define WK4 LALT(KC_4)
#define WK5 LALT(KC_5)
#define WK6 LALT(KC_6)
#define WK7 LALT(KC_7)
#define WK8 LALT(KC_8)
#define WK9 LALT(KC_9)
#define WK0 LALT(KC_0)

//other i3 keys
#define i3TERM  A(KC_ENTER)
#define i3LEFT  A(KC_H)
#define i3DOWN  A(KC_J)
#define i3UP    A(KC_K)
#define i3RGHT  A(KC_L)
#define i3DMENU A(KC_D)
#define i3QUIT  A(S(KC_Q))

//windows keys
#define WINLEFT G(C(KC_LEFT))
#define WINRGHT G(C(KC_RIGHT))
#define WINVNEW G(C(KC_D))
#define WINCLOS G(C(KC_F4))

#define WMLEFT SWIN(KC_LEFT)
#define WMRGHT SWIN(KC_RIGHT)

#define ALTTAB A(KC_TAB)
#define WINTAB G(KC_TAB)
#define WINDIS C(A(KC_TAB))
#define WINLOC G(KC_L)
#define WINRUN G(KC_R)
#define WINFIL G(KC_E)
#define CLOSE  A(KC_F4)
#define SCREEN G(KC_PSCREEN)

#define MOVEWL G(KC_LEFT)
#define MOVEWR G(KC_RIGHT)
#define MOVEWD G(KC_DOWN)
#define MOVEWU G(KC_UP)

enum preonic_layers {
  _QWERTY,
  _SYMBOLS,
  _NAVIG,
  _GAME,
  _ADJUST_LIN,
  _ADJUST_WIN
};

enum preonic_keycodes {
  //layer keycodes
  QWERTY = SAFE_RANGE,
  SYMBOLS,
  NAVIG,
  GAME,
  ADJUST_LIN,
  ADJUST_WIN
};

int _ADJUST = _ADJUST_WIN;


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |Delete|Delete|   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |* Q   |   W  |   E  |   R  |   T  |   [  |   ]  |   Y  |   U  |   I  |   O  |  P   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  A   |   S  |   D  |   F  |   G  |   (  |   )  |   H  |   J  |   K  |   L  |* ;   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Z   |   X  |   C  |   V  |   B  |   {  |   }  |   N  |   M  |   ,  |   .  |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |NAVIG |   Backspace |    Space    |SYMBL |VOL-  |  Up  | Esc  |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_2x2u( \
  KC_1   , KC_2   , KC_3   , KC_4 , KC_5   , KC_DEL ,  KC_DEL ,  KC_6  , KC_7   , KC_8,    KC_9   , KC_0   , \
  KC_Q   , KC_W   , KC_E   , KC_R , KC_T   , KC_LBRC,  KC_RBRC,  KC_Y  , KC_U   , KC_I,    KC_O   , KC_P   , \
  KC_A   , KC_S   , KC_D   , KC_F , KC_G   , KC_LPRN,  KC_RPRN,  KC_H  , KC_J   , KC_K,    KC_L   , KC_SCLN, \
  SHFZ   , KC_X   , KC_C   , KC_V , KC_B   , KC_LCBR,  KC_RCBR,  KC_N  , KC_M   , KC_COMM, KC_DOT , SHFS   , \
  KC_LCTL, KC_LGUI, KC_LALT, NAVIG,      KC_BSPC    ,       KC_SPC     , SYMBOLS, KC_VOLD, KC_VOLU, KC_ESC   \
),

/* Symbols
 * ,-----------------------------------------------------------------------------------.
 * |  `   |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  ~   |   @  |   #  |   *  |   %  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  !   |      |   -  |   =  |   +  |   ^  |   $  |   |  |   &  |   `  |   '  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  \   |      |      |   _  |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |   Enter     |             |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMBOLS] = LAYOUT_preonic_2x2u( \
  KC_GRV , KC_EXLM, KC_AT,   KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
  KC_TILD, KC_AT  , KC_HASH, KC_ASTR, KC_PERC, _______, _______, _______, _______, _______, _______, _______, \
  KC_EXLM, _______, KC_MINS, KC_EQL , KC_PLUS, KC_CIRC, KC_DLR , KC_PIPE, KC_AMPR, KC_GRV , KC_QUOT, KC_DQUO, \
  KC_BSLS, _______, _______, KC_UNDS, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, KC_ENT          , _______         , _______, _______, _______, _______  \
),

/* Navigation
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | PGdn | PGup |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Left | Down |  Up  | Right|Caps  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |             |     Tab     |      |      |      |enter |
 * `-----------------------------------------------------------------------------------'
 */
[_NAVIG] = LAYOUT_preonic_2x2u( \
  KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9,   KC_F10 , KC_F11 , KC_F12 , \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_PGDN, KC_PGUP, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_CAPS, \
  KC_LALT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______         , KC_TAB          , _______, _______, _______, KC_ENT   \
),

/* Adjust (Lower + Raise) and i3
 * ,-----------------------------------------------------------------------------------.
 * | work1|work2 | work3| work4|work5 |AudOn |AudOff|work6 |work7 |work8 |work9 |work0 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |Qwerty|Game  |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | dmenu|      |      |LINUX |WINDOW|i3 lef|i3 dwn|i3 up |i3 rgt|term  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | shift|      |      |      |      |      |      |      |      |      |      |shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Reset|Debug |MusMod|      |MusOn        |MusOff       |      |Voice-|Voice+|quit  |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST_LIN] = LAYOUT_preonic_2x2u( \
  WK1    , WK2    , WK3    , WK4    , WK5    , AU_ON     , AU_OFF         , WK6    , WK7    , WK8    , WK9    , WK0    , \
  A(KC_Q), A(KC_W), A(KC_E), A(KC_R), A(KC_T), QWERTY    , GAME           , A(KC_Y), A(KC_U), A(KC_I), A(KC_O), A(KC_P), \
  A(KC_A), A(KC_S), i3DMENU, A(KC_F), A(KC_G), _______   , _______        , i3LEFT , i3DOWN , i3UP   , i3RGHT , i3TERM , \
  KC_LSFT, A(KC_X), A(KC_C), A(KC_V), A(KC_B), _______   , _______        , A(KC_N), A(KC_M), _______, _______, KC_RSFT, \
  RESET  , DEBUG  , MU_MOD , _______, MU_ON              , MU_OFF         , _______, MUV_DE , MUV_IN , i3QUIT   \
),

/* Adjust (Lower + Raise) and i3
 * ,-----------------------------------------------------------------------------------.
 * | NEWVD|      |      |      |      |AudOn |AudOff|      |      |      |      |CLOSEV|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |CLOSE |      |      |RUN   |      |Qwerty|Game  |LEFT  |DOWN  |UP    |RIGHT |SCREEN|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |VLEFT |      |GUI   |FILE  |      |      |      |WLEFT |DISPLA|TAB   |WRIGHT|VRGHT |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |XMENU |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Reset|Debug |MusMod|      |MusOn        |MusOff       |      |Voice-|Voice+|      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST_WIN] = LAYOUT_preonic_2x2u( \
  WINVNEW, XXXXXXX, XXXXXXX, XXXXXXX , XXXXXXX , AU_ON         , AU_OFF    , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, WINCLOS, \
  CLOSE  , XXXXXXX, XXXXXXX, WINRUN  , XXXXXXX , QWERTY        , GAME      , MOVEWL , MOVEWD , MOVEWU , MOVEWR , SCREEN , \
  WINLEFT, XXXXXXX, KC_LGUI, WINFIL  , XXXXXXX, _______        , _______   , WMLEFT , WINDIS , WINTAB , WMRGHT , WINRGHT, \
  XXXXXXX, G(KC_X), XXXXXXX, XXXXXXX , XXXXXXX , _______       , _______   , WINLOC , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  RESET  , DEBUG  , MU_MOD , _______ , MU_ON                   , MU_OFF    , _______, MUV_DE , MUV_IN , _______\
),

/* Gaming
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  0   |Back  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  Q   |  W   |  E   |  R   |  T   |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |  A   |  S   |  D   |  F   |  G   |      |      |      |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Shift |  Z   |  X   |  C   |  V   |  B   |      |      |      |      |  up  |shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ctrl |      | alt  |      |     Space   |             |      | left | down |right |
 * `-----------------------------------------------------------------------------------'
 */
[_GAME] = LAYOUT_preonic_2x2u( \
  KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC, \
  XXXXXXX, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  KC_TAB , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT , \
  KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UP  , KC_RSFT, \
  KC_RCTL, XXXXXXX, KC_RALT, NAVIG  , KC_SPC          , XXXXXXX         , SYMBOLS, KC_LEFT, KC_DOWN, KC_RGHT  \
),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode)
    {
        case QWERTY:
            if (record->event.pressed)
            {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case GAME:
            if (record-> event.pressed)
            {
                set_single_persistent_default_layer(_GAME);
            }
            return false;
            break;
        case SYMBOLS:
            if (record->event.pressed)
            {
                layer_on(_SYMBOLS);
                update_tri_layer(_SYMBOLS, _NAVIG, _ADJUST);
            }
            else
            {
                layer_off(_SYMBOLS);
                update_tri_layer(_SYMBOLS, _NAVIG, _ADJUST);
            }
            return false;
            break;
        case NAVIG:
            if (record->event.pressed)
            {
                layer_on(_NAVIG);
                update_tri_layer(_SYMBOLS, _NAVIG, _ADJUST);
            } else {
                layer_off(_NAVIG);
                update_tri_layer(_SYMBOLS, _NAVIG, _ADJUST);
            }
            return false;
            break;
    }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise)
{
    if (muse_mode)
    {
        if (IS_LAYER_ON(_NAVIG))
        {
            if (clockwise)
            {
                muse_offset++;
            }
            else
            {
                muse_offset--;
            }
        }
        else
        {
            if (clockwise)
            {
                muse_tempo+=1;
            }
            else
            {
                muse_tempo-=1;
            }
        }
    }
    else
    {
        if (clockwise)
        {
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        }
        else
        {
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        }
    }
}

void dip_update(uint8_t index, bool active)
{
    switch (index)
    {
        case 0:
            if (active)
            {
                layer_on(_ADJUST);
            }
            else
            {
                layer_off(_ADJUST);
            }
            break;

        case 1:
            if (active)
            {
                muse_mode = true;
            }
            else
            {
                muse_mode = false;
                #ifdef AUDIO_ENABLE
                    stop_all_notes();
                #endif
            }
    }
}

void matrix_scan_user(void)
{
    #ifdef AUDIO_ENABLE
        if (muse_mode)
        {
            if (muse_counter == 0)
            {
                uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
                if (muse_note != last_muse_note)
                {
                    stop_note(compute_freq_for_midi_note(last_muse_note));
                    play_note(compute_freq_for_midi_note(muse_note), 0xF);
                    last_muse_note = muse_note;
                }
            }
            muse_counter = (muse_counter + 1) % muse_tempo;
        }
    #endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode)
    {
        case NAVIG:
        case SYMBOLS:
            return false;
        default:
            return true;
    }
}
