/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MOVE 2 // numbers/motion

/* Combomap
 *
 * ,---------------------------------------.  ,---------------------------------------.
 * |       |      TAB      |       |       |  |       |       |      ESC      BSLH    |
 * |-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------|
 * |       |      BSPC    DEL      |       |  |       |       |      ENT      |       |
 * |-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------|
 * |       |      MINS     |       |       |  |      QUO     UNDR     |       |       |
 * `-------+-------+-------+-------+-------'  `---------------------------------------'
 *           .---------+---------+---------.  .---------+---------+---------.
 *           |         |         |         |  |         |         |         |    
 *           '---------+---------+---------'  '---------+---------+---------' 
 */

// Blank template at the bottom
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,---------------------------------------.  ,---------------------------------------.
 * |   Q   |   W   |   E   |   R   |   T   |  |   Y   |   U   |   I   |   O   |   P   |
 * |-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------|
 * |CTRL/A |   S   |   D   |   F   |   G   |  |   H   |   J   |   K   |   L   |CTRL/; | 
 * |-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------|
 * |SHFT/Z |   X   |   C   |   V   |   B   |  |   N   |   M   |   ,<  |  .>   |SHFT//?;|
 * `-------+-------+-------+-------+-------'  `---------------------------------------'
 *           .---------+---------+---------.  .---------+---------+---------.   
 *           |         |   META  |SPC(SYM) |  |  (NUM)  |   ALT   |         |
 *           '---------+---------+---------'  '---------+---------+---------' 
 */
[BASE] = LAYOUT_gergoplex(
    KC_Q,  			    KC_W, KC_E, KC_R, KC_T,  	KC_Y, KC_U, KC_I,    KC_O, 	 KC_P, 
    MT(MOD_LCTL, KC_A), KC_S, KC_D, KC_F, KC_G,  	KC_H, KC_J, KC_K,    KC_L, 	 MT(MOD_RCTL, KC_SCLN),
    MT(MOD_LSFT, KC_Z), KC_X, KC_C, KC_V, KC_B,  	KC_N, KC_M, KC_COMM, KC_DOT, MT(MOD_RSFT, KC_SLSH),

 		KC_NO,      KC_LGUI, LT(SYMB,KC_SPC),	    // Left
		MO(MOVE)           , KC_LALT, KC_NO 		// Right
    ),
/* Keymap 1: Symbols layer
 * ,---------------------------------------.  ,---------------------------------------.
 * |   !   |   @   |   {   |   }   |   ~   |  |   *   |   7   |   8   |   9   |   \   |
 * |-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------|
 * |CTRL/^ |   $   |   (   |   )   |   |   |  |   +   |   4   |   5   |   6   | CTRL/'| 
 * |-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------|
 * |SHFT/% |   #   |   [   |   ]   |   &   |  |   -   |   1   |   2   |   3   | SHFT/=|
 * `-------+-------+-------+-------+-------'  `---------------------------------------'
 *           .---------+---------+---------.  .---------+---------+---------.   
 *  	     |         |         | PRESSED |  |         |    0    |         |
 *           '---------+---------+---------'  '---------+---------+---------'
 */
[SYMB] = LAYOUT_gergoplex(
    KC_EXLM,               KC_AT,   KC_LCBR, KC_RCBR, KC_TILD,   KC_ASTR, KC_7, KC_8, KC_9, KC_BSLS,
    MT(MOD_LCTL, KC_CIRC),  KC_DLR,  KC_LPRN, KC_RPRN, KC_PIPE,   KC_PLUS, KC_4, KC_5, KC_6, MT(MOD_RCTL,KC_QUOT),
    MT(MOD_LSFT, KC_PERC), KC_HASH, KC_LBRC, KC_RBRC, KC_AMPR,   KC_MINS, KC_1, KC_2, KC_3, MT(MOD_RSFT,KC_EQL),
                                      KC_NO, KC_LGUI, KC_TRNS,   KC_NO,   KC_0, KC_NO
    ),
/* Keymap 2: Pad/Function layer
 * ,---------------------------------------.  ,---------------------------------------.
 * |  F1   |  F2   |  F3   |  F4   |  F5   |  |  HOME | PGDWN |  PGUP |  END  |       |
 * |-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------|
 * |CTRL/F6|  F7   |  F8   |  F9   |  F10  |  |  LFT  |  DWN  |   UP  |  RGT  | VOLUP | 
 * |-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------|
 * |SFT/F11| F12   |       |       |       |  |  MLFT | MDWN  |  MUP  |  MRGT | VOLDN |
 * `-------+-------+-------+-------+-------'  `---------------------------------------'
 *           .---------+---------+---------.  .---------+---------+---------.   
 *  	     |         |         |	       |  | PRESSED |   ALT   |         |
 *           '---------+---------+---------'  '---------+---------+---------' 
 */
[MOVE] = LAYOUT_gergoplex(
    KC_F1,               KC_F2,  KC_F3, KC_F4, KC_F5,		KC_HOME, KC_PGDN, KC_PGUP, KC_END, 	KC_NO,
    MT(MOD_LCTL,KC_F6),  KC_F7,  KC_F8, KC_F9, KC_F10,   	KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_VOLU,
    MT(MOD_LSFT,KC_F11), KC_F12, KC_NO, KC_NO, KC_NO,  		KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_VOLD,
            					 KC_NO, KC_NO, KC_NO,    	KC_TRNS, KC_LALT, KC_NO
    )
};
