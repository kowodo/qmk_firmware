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
#define MOUSE 3 // experimental mouse 

// This function fixes the % vs 5 problem.
// When KC_PERC is used with some of the modifiers like 
// LSFT_T(kc), LALT_T(kc) or MT(mod, kc) it produces 5 instead of %.
// FYI: The ^ has simillar problem. I do not know how to solve that one yet.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
      case LALT_T(KC_F23):
        if (record->tap.count > 0) {
          if (record->event.pressed) {
            register_code16(KC_PERC);
          } else {
            unregister_code16(KC_PERC);
          }
          return false;
        }
        break;
  }
  return true;
};

/* Combomap
 *
 * ,---------------------------------------.  ,---------------------------------------.
 * |       |      TAB      |       |       |  |       |       |      ESC      BSLH    |
 * |-------+-------+-BSPC--+--DEL--+-------|  |-------+-------+-------+-------+-------|
 * |       |      BSPC    DEL      |       |  |       |       |      ENT      |       |
 * |-------+-------+-------+-------+-------|  |-------+--GRV--+-QUOTE-+-------+-------|
 * |       |      UNDR    MINS     |       |  |      QUO      |       |       |       |
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
 * |ALT/Z  |   X   |   C   |   V   |   B   |  |   N   |   M   |   ,<  |  .>   |ALT//?;|
 * `-------+-------+-------+-------+-------'  `---------------------------------------'
 *           .---------+---------+---------.  .---------+---------+---------.   
 *           |         |   META  |SPC(SYM) |  |  (NUM)  |   ALT   |         |
 *           '---------+---------+---------'  '---------+---------+---------' 
 */
[BASE] = LAYOUT_gergoplex(
    KC_Q,  			    KC_W, KC_E, KC_R, KC_T,     	KC_Y, KC_U, KC_I,    KC_O, 	 KC_P, 
    MT(MOD_LCTL, KC_A), KC_S, KC_D, KC_F, KC_G,  	KC_H, KC_J, KC_K,    KC_L, 	 MT(MOD_RCTL, KC_SCLN),
    LALT_T(KC_Z),       KC_X, KC_C, KC_V, KC_B,  	KC_N, KC_M, KC_COMM, KC_DOT, LALT_T(KC_SLSH),

 		KC_NO,      KC_LGUI, LT(SYMB,KC_SPC),	    // Left
		MO(MOVE),   KC_LSFT, KC_NO 		            // Right
    ),
    
/* Keymap 1: Symbols layer
 * ,---------------------------------------.  ,---------------------------------------.
 * |   &   |   |   |   {   |   }   |   ~   |  |   *   |   7   |   8   |   9   |   \   |
 * |-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------|
 * |CTRL/^ |   $   |   (   |   )   |   !   |  |   +   |   4   |   5   |   6   | CTRL/=|
 * |-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------|
 * | ALT/% |   #   |   [   |   ]   |   @   |  |   -   |   1   |   2   |   3   | ALT/0 |
 * `-------+-------+-------+-------+-------'  `---------------------------------------'
 *           .---------+---------+---------.  .---------+---------+---------.   
 *  	     |         |         | PRESSED |  |         |         |         |
 *           '---------+---------+---------'  '---------+---------+---------'
 */
[SYMB] = LAYOUT_gergoplex(
    KC_AMPR,               KC_PIPE, KC_LCBR, KC_RCBR, KC_TILD,   KC_ASTR, KC_7, KC_8, KC_9, KC_BSLS,
    MT(MOD_LCTL, KC_CIRC), KC_DLR,  KC_LPRN, KC_RPRN, KC_EXLM,   KC_PLUS, KC_4, KC_5, KC_6, MT(MOD_RCTL,KC_EQL),
    LALT_T(KC_F23),        KC_HASH, KC_LBRC, KC_RBRC, KC_AT,     KC_MINS, KC_1, KC_2, KC_3, LALT_T(KC_0),
                                      KC_NO, KC_LGUI, KC_TRNS,   MO(MOUSE),   KC_TRNS, KC_NO
    ),

/* Keymap 2: Pad/Function layer
 * ,---------------------------------------.  ,---------------------------------------.
 * |  F1   |  F2   |  F3   |  F4   |  F5   |  |  HOME | PGDWN |  PGUP |  END  | PGUP  |
 * |-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------|
 * |CTRL/F6|  F7   |  F8   |  F9   |  F10  |  |  LFT  |  DWN  |   UP  |  RGT  |  INS  | 
 * |-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------|
 * |ALT/F11| F12   |       |       |       |  |  MLFT | MDWN  |  MUP  |  MRGT | PGDWN |
 * `-------+-------+-------+-------+-------'  `---------------------------------------'
 *           .---------+---------+---------.  .---------+---------+---------.   
 *    	     |         |         |	       |  | PRESSED |   ALT   |         |
 *           '---------+---------+---------'  '---------+---------+---------' 
 */
[MOVE] = LAYOUT_gergoplex(
    KC_F1,               KC_F2,  KC_F3, KC_F4, KC_F5,		  KC_HOME, KC_PGDN, KC_PGUP, KC_END, 	KC_PGUP,
    MT(MOD_LCTL,KC_F6),  KC_F7,  KC_F8, KC_F9, KC_F10,   	KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, MT(MOD_RCTL,KC_INS),
    LALT_T(KC_F11),      KC_F12, KC_NO, KC_NO, KC_NO,  		KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, LALT_T(KC_PGDN),
            				KC_NO, KC_TRNS, MO(MOUSE),    	KC_TRNS, KC_TRNS, KC_NO
    ),

/* Keymap 2: Pad/Function layer
 * ,---------------------------------------.  ,---------------------------------------.
 * |       |       |       |       |       |  |       |       |       |       |       |
 * |-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------|
 * |       |       |       |       |       |  |       |       |       |       |       | 
 * |-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------|
 * |       |       |       |       |       |  |       |       |       |       |       |
 * `-------+-------+-------+-------+-------'  `---------------------------------------'
 *           .---------+---------+---------.  .---------+---------+---------.   
 *    	     |         |         |	       |  | PRESSED |   ALT   |         |
 *           '---------+---------+---------'  '---------+---------+---------' 
 */
[MOUSE] = LAYOUT_gergoplex(
    KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO,		        KC_NO,   KC_NO,   KC_NO,   KC_NO, 	KC_NO,
    KC_NO,  KC_ACL0, KC_ACL1, KC_ACL2, KC_NO,   	KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO,  	        KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_VOLD,
            				   KC_NO, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_NO
    )
};
