#include QMK_KEYBOARD_H
#include "action_layer.h"

/**
 * Every key has 7 characters and 1 comma, easier to find and replace.
 * Note to self: KC_CAPS mapped to KC_ENT in /usr/share/X11/xkb/symbols/pc
 */

// SFT_MODS cannot be a subset of GRV_MODS
#define SFT_MODS (MOD_BIT(KC_LSFT)|MOD_BIT(KC_RSFT))
#define GRV_MODS (MOD_BIT(KC_LGUI)|MOD_BIT(KC_RGUI))

#define _QW 0
#define _DP 1
#define _QF 2
#define _DF 3

/* QWERTY numpad for software-dvp */
#define KC_Q0 LSFT(KC_7)
#define KC_Q1 LSFT(KC_5)
#define KC_Q2 LSFT(KC_8)
#define KC_Q3 LSFT(KC_4)
#define KC_Q4 LSFT(KC_9)
#define KC_Q5 LSFT(KC_3)
#define KC_Q6 LSFT(KC_0)
#define KC_Q7 LSFT(KC_2)
#define KC_Q8 LSFT(KC_MINS)
#define KC_Q9 LSFT(KC_6)

enum dvp_keycodes {
    KC_DGRV = SAFE_RANGE,
    KC_D1,
    KC_D2,
    KC_D3,
    KC_D4,
    KC_D5,
    KC_D6,
    KC_D7,
    KC_D8,
    KC_D9,
    KC_D0,
    KC_DMIN,
    KC_DEQL,
    KC_DAT,
    NEW_SAFE_RANGE // define a new safe range
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /*
     ~!@#$%^&*()_+
     QWERTYUIOP{}|
     ASDFGHJKL:"
     ZXCVBNM<>?
      1234567890-=
     qwertyuiop[]\
     asdfghjkl;'
     zxcvbnm,./
  */
  [_QW] = LAYOUT_all(
      KC_GESC,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_MINS,KC_EQL ,KC_BSPC,XXXXXXX,\
      KC_TAB ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_LBRC,KC_RBRC,        KC_BSLS,\
      KC_ENT ,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,KC_QUOT,XXXXXXX,        KC_ENT ,\
      KC_LSFT,XXXXXXX,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,KC_N   ,KC_M   ,KC_COMM,KC_DOT ,XXXXXXX,KC_SLSH,KC_UP  ,KC_DEL ,\
      KC_LCTL,KC_LGUI,KC_LALT,                        KC_SPC ,                        TO(_DP),MO(_QF),KC_LEFT,KC_DOWN,KC_RGHT),

  /*
    TODO
        moving unregister SFT_MODS to !record->event.pressed makes these outputs
        ~%7531902468`
        $%7531902468`
        Also, SFT_MODS is constantly registered

    ~%7531902468`
    :<>PYFGCRL?^|
    AOEUIDHTNS_
    "QJKXBMWVZ
    $&[{}(=*)+]!#
    ;,.pyfgcrl/@\
    aoeuidhtns-
    'qjkxbmwvz
    TODO
        holding down KC_D* keys accumulates actions
        e.g. holding down } in vim does not immediately move to next paragraph
    TODO
        in i3, $mod+Shift+3 to move windows
        however, $mod+Shift+} is sent in this layout
  */
  [_DP] = LAYOUT_all(
      KC_DGRV,KC_D1  ,KC_D2  ,KC_D3  ,KC_D4  ,KC_D5  ,KC_D6  ,KC_D7  ,KC_D8  ,KC_D9  ,KC_D0  ,KC_DMIN,KC_DEQL,KC_BSPC,XXXXXXX,\
      KC_TAB ,KC_SCLN,KC_COMM,KC_DOT ,KC_P   ,KC_Y   ,KC_F   ,KC_G   ,KC_C   ,KC_R   ,KC_L   ,KC_SLSH,KC_DAT ,        KC_BSLS,\
      KC_ENT ,KC_A   ,KC_O   ,KC_E   ,KC_U   ,KC_I   ,KC_D   ,KC_H   ,KC_T   ,KC_N   ,KC_S   ,KC_MINS,XXXXXXX,        KC_ENT ,\
      KC_LSFT,XXXXXXX,KC_QUOT,KC_Q   ,KC_J   ,KC_K   ,KC_X   ,KC_B   ,KC_M   ,KC_W   ,KC_V   ,XXXXXXX,KC_Z   ,KC_UP  ,KC_DEL ,\
      KC_LCTL,KC_LGUI,KC_LALT,                        KC_SPC ,                        TO(_QW),MO(_DF),KC_LEFT,KC_DOWN,KC_RGHT),

  /* | pasting | numpad | media & clicking & movement
   * numpad slants to right (since more ergonomic for left hand to press)
   * TODO test if KC_UNDO,KC_CUT,KC_COPY,KC_PSTE work
   */

  [_QF] = LAYOUT_all(
      KC_GESC,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_PSCR,XXXXXXX,\
      KC_TAB ,RGB_TOG,RGB_MOD,RGB_HUI,RGB_HUD,XXXXXXX,XXXXXXX,KC_Q7  ,KC_Q8  ,KC_Q9  ,KC_BTN1,KC_MS_U,KC_BTN2,        KC_BTN3,\
      KC_CAPS,RGB_SAI,RGB_SAD,RGB_VAI,RGB_VAD,XXXXXXX,KC_Q4  ,KC_Q5  ,KC_Q6  ,XXXXXXX,KC_MS_L,KC_MS_D,XXXXXXX,        KC_MS_R,\
      KC_LSFT,XXXXXXX,KC_UNDO,KC_CUT ,KC_COPY,KC_PSTE,KC_Q1  ,KC_Q2  ,KC_Q3  ,KC_VOLD,KC_MUTE,XXXXXXX,KC_VOLU,KC_PGUP,KC_INS ,\
      KC_LCTL,KC_LGUI,KC_LALT,                        KC_0   ,                        KC_RALT,XXXXXXX,KC_HOME,KC_PGDN,KC_END ),

  [_DF] = LAYOUT_all(
      KC_GESC,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_PSCR,XXXXXXX,\
      KC_TAB ,RGB_TOG,RGB_MOD,RGB_HUI,RGB_HUD,XXXXXXX,XXXXXXX,KC_7   ,KC_8   ,KC_9   ,KC_BTN1,KC_MS_U,KC_BTN2,        KC_BTN3,\
      KC_CAPS,RGB_SAI,RGB_SAD,RGB_VAI,RGB_VAD,XXXXXXX,KC_4   ,KC_5   ,KC_6   ,XXXXXXX,KC_MS_L,KC_MS_D,XXXXXXX,        KC_MS_R,\
      KC_LSFT,XXXXXXX,KC_UNDO,KC_CUT ,KC_COPY,KC_PSTE,KC_1   ,KC_2   ,KC_3   ,KC_VOLD,KC_MUTE,XXXXXXX,KC_VOLU,KC_PGUP,KC_INS ,\
      KC_LCTL,KC_LGUI,KC_LALT,                        KC_0   ,                        KC_RALT,XXXXXXX,KC_HOME,KC_PGDN,KC_END ),

};

void process_record_dvorak(uint16_t kc_sft, uint16_t kc_nsft, keyrecord_t* record,
        const uint8_t shifted, uint8_t shift_flags) {
    /*
     * kc_sft: when mods include shift, register this keycode
     * kc_nsft: when mods do not include shift, register this keycode
     * shifted: if 0, then no shift mods
     * shift_flags: if set for a keycode, register shift for that keycode
     *   where flags:registers are
     *       00: unregister(kc_sft)
     *       01: unregister(kc_sft) register(kc_nsft)
     *       10:
     *       11:                    register(kc_nsft)
     *   if set for kc_sft, do nothing
     *   if not set for kc_sft, unregister mods
     *   if set for kc_nsft, register shift mods
     *   if not set for kc_nsft, do nothing
     */

    if (record->event.pressed) {
        if (shifted) {
            if (shift_flags & 2) {
                register_code(kc_sft);
            } else {
                unregister_mods(shifted);
                register_code(kc_sft);
                register_mods(shifted);
            }

        } else {
            if (shift_flags & 1) {
                register_mods(SFT_MODS);
                register_code(kc_nsft);
                unregister_mods(SFT_MODS);
            } else {
                register_code(kc_nsft);
            }

        }

    } else {
        if (shifted) {
            unregister_code(kc_sft);
        } else {
            unregister_code(kc_nsft);
        }
    }

}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {

    /* Process dvorak keycodes
     * Cannot directly register_code(SFT(KC_4))
     * Because shifted keycode may require absence of SFT_MODS
     * Hence, need unregister SFT_MODS
     */

    // The following codes work with or without SFT_MODS.
    // Do not short circuit on no mods, always process.
    const uint8_t mods = get_mods();
    const uint8_t shifted = mods & SFT_MODS;

    switch (keycode) {

        case KC_DGRV:
            // Special handling, just like KC_GESC
            // SFT(KC_DGRV): ~
            // GUI(KC_DGRV): $
            // KC_DGRV: KC_ESC
            // from https://github.com/qmk/qmk_firmware/issues/3769

            if (record -> event.pressed) {

                // Any mod that has shift triggers KC_GRV
                if (shifted) {
                    register_code(KC_GRV);

                // Only grv mod without shift triggers KC_DOLLAR
                // Else trigger KC_ESC
                } else {
                    const uint8_t grv = mods & GRV_MODS;
                    if (!grv) {
                        register_code(KC_ESC);
                    } else {
                        unregister_mods(grv);
                        register_mods(SFT_MODS);
                        register_code(KC_4);
                        unregister_mods(SFT_MODS);
                        register_mods(grv);
                    }

                }

            } else {
                if (shifted) {
                    unregister_code(KC_GRV);

                } else {
                    register_mods(SFT_MODS);
                    unregister_code(KC_4);
                    unregister_mods(SFT_MODS);

                }

                unregister_code(KC_ESC);

            }

            break;

        case KC_D1:
            // SFT(KC_D1): %
            // KC_D1: &
            process_record_dvorak(KC_5, KC_7, record, shifted, 3);
            break;

        case KC_D2:
            // SFT(KC_D2): 7
            // KC_D2: [
            process_record_dvorak(KC_7, KC_LBRC, record, shifted, 0);
            break;

        case KC_D3:
            // SFT(KC_D3): 5
            // KC_D3: {
            process_record_dvorak(KC_5, KC_LBRC, record, shifted, 1);
            break;

        case KC_D4:
            // SFT(KC_D4): 3
            // KC_D4: }
            process_record_dvorak(KC_3, KC_RBRC, record, shifted, 1);
            break;

        case KC_D5:
            // SFT(KC_D5): 1
            // KC_D5: (
            process_record_dvorak(KC_1, KC_9, record, shifted, 1);
            break;

        case KC_D6:
            // SFT(KC_D6): 9
            // KC_D6: =
            process_record_dvorak(KC_9, KC_EQL, record, shifted, 0);
            break;

        case KC_D7:
            // SFT(KC_D7): 0
            // KC_D7: *
            process_record_dvorak(KC_0, KC_8, record, shifted, 1);
            break;

        case KC_D8:
            // SFT(KC_D8): 2
            // KC_D8: )
            process_record_dvorak(KC_2, KC_0, record, shifted, 1);
            break;

        case KC_D9:
            // SFT(KC_D9): 4
            // KC_D9: +
            process_record_dvorak(KC_4, KC_EQL, record, shifted, 1);
            break;

        case KC_D0:
            // SFT(KC_D0): 6
            // KC_D0: ]
            process_record_dvorak(KC_6, KC_RBRC, record, shifted, 0);
            break;

        case KC_DMIN:
            // SFT(KC_DMIN): 8
            // KC_DMIN: !
            process_record_dvorak(KC_8, KC_1, record, shifted, 1);
            break;

        case KC_DEQL:
            // SFT(KC_DEQL): `
            // KC_DEQL: #
            process_record_dvorak(KC_GRV, KC_3, record, shifted, 1);
            break;

        case KC_DAT:
            // SFT(KC_DAT): ^
            // KC_DAT: @
            process_record_dvorak(KC_6, KC_2, record, shifted, 3);
            break;

        default:
            return true; // process all other keycodes

    }
    return false; // skip further processing of this keycode
}

// Loop
void matrix_scan_user(void) {
};
