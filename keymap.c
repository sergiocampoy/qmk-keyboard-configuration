/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>

// Tap Dance declarations
enum {
  TD_CAPS_LOCK
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Shift, tap twice for Capslock
    [TD_CAPS_LOCK] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS)
};

// Layer declaration
enum layers{
  _QWERTY = 0,  // default layer
  _COLEMAK_DH,  // layer with colemak-dh layout
  _LOL,         // layer for playing League of Legends
  _FACTORIO,    // layer for playing factorio, minecraft...
  _SYMBOL,      // symbol layer (press middle thumb key in the left)
  _FUNCTION,    // function layer (press middle thumb key in the right)
  _SWITCH       // layer-switching layer (press both middle thumb keys at once)
};

// Keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty layer
 * ,-----------------------------------.   ,-----------------------------------.
 * | tab |  q  |  w  |  e  |  r  |  t  |   |  y  |  u  |  i  |  o  |  p  | del |
 * |-----+-----+-----+-----+-----+-----|   |-----+-----+-----+-----+-----+-----|
 * | ctl |  a  |  s  |  d  |  f  |  g  |   |  h  |  j  |  k  |  l  |  ñ  |  ´  |
 * |-----+-----+-----+-----+-----+-----|   |-----+-----+-----+-----+-----+-----|
 * | sft |  z  |  x  |  c  |  v  |  b  |   |  n  |  m  |  ,  |  .  |  -  | esc |
 * `-----------------+-----+-----+-----|   |-----+-----+-----+-----------------'
 *                   | gui | fn1 | spc |   | ent | fn2 | alt |
 *                   `-----+-----+-----'   `-----+-----+-----'
 */
[_QWERTY] = LAYOUT_split_3x6_3(
  KC_TAB,           KC_Q, KC_W, KC_E, KC_R, KC_T,   KC_Y, KC_U, KC_I,    KC_O,   KC_P,     KC_BSPC,
  KC_LCTL,          KC_A, KC_S, KC_D, KC_F, KC_G,   KC_H, KC_J, KC_K,    KC_L,   KC_SCLN,  KC_QUOT,
  TD(TD_CAPS_LOCK), KC_Z, KC_X, KC_C, KC_V, KC_B,   KC_N, KC_M, KC_COMM, KC_DOT, KC_SLASH, KC_ESC,

  KC_LGUI, MO(_SYMBOL),   LALT_T(KC_SPC),
  KC_ENT,  MO(_FUNCTION), KC_RALT
),

/* Colemak Mod-DH layer
 * ,-----------------------------------.   ,-----------------------------------.
 * | tab |  q  |  w  |  f  |  p  |  b  |   |  j  |  l  |  u  |  y  |  ñ  | del |
 * |-----+-----+-----+-----+-----+-----|   |-----+-----+-----+-----+-----+-----|
 * | ctl |  a  |  r  |  s  |  t  |  g  |   |  m  |  n  |  e  |  i  |  o  |  ´  |
 * |-----+-----+-----+-----+-----+-----|   |-----+-----+-----+-----+-----+-----|
 * | sft |  z  |  x  |  c  |  d  |  v  |   |  k  |  h  |  ,  |  .  |  -  | esc |
 * `-----------------+-----+-----+-----|   |-----+-----+-----+-----------------'
 *                   | gui | fn1 | spc |   | ent | fn2 | alt |
 *                   `-----+-----+-----'   `-----+-----+-----'
 */
[_COLEMAK_DH] = LAYOUT_split_3x6_3(
  KC_TAB,           KC_Q, KC_W, KC_F, KC_P, KC_B,   KC_J, KC_L, KC_U,    KC_Y,   KC_SCLN,  KC_BSPC,
  KC_LCTL,          KC_A, KC_R, KC_S, KC_T, KC_G,   KC_M, KC_N, KC_E,    KC_I,   KC_O,     KC_QUOT,
  TD(TD_CAPS_LOCK), KC_Z, KC_X, KC_C, KC_D, KC_V,   KC_K, KC_H, KC_COMM, KC_DOT, KC_SLASH, KC_ESC,

  KC_LGUI, MO(_SYMBOL),  LALT_T(KC_SPC),
  KC_ENT, MO(_FUNCTION), KC_RALT
),


/* Symbol layer
 * ,-----------------------------------.   ,-----------------------------------.
 * | tab |  1  |  2  |  3  |  4  |  5  |   |  6  |  7  |  8  |  9  |  0  | del |
 * |-----+-----+-----+-----+-----+-----|   |-----+-----+-----+-----+-----+-----|
 * | ctl |  $  |  +  |  (  |  )  |  /  |   |  |  |  {  |  }  |  =  |  *  |  '  |
 * |-----+-----+-----+-----+-----+-----|   |-----+-----+-----+-----+-----+-----|
 * | sft |  !  |  #  |  ¿  |  ?  |  @  |   |  &  |  [  |  ]  |  %  |  ^  | esc |
 * `-----------------+-----+-----+-----|   |-----+-----+-----+-----------------'
 *                   | gui | fn1 | spc |   | ent | fn2 | alt |
 *                   `-----+-----+-----'   `-----+-----+-----'
 */
// WARNING! This layer only works when a spanish keyboard is set in software
// With any other setting the symbols will be different
[_SYMBOL] = LAYOUT_split_3x6_3(
  KC_TAB,           KC_1,    KC_2,       KC_3,      KC_4,       KC_5,         KC_6,       KC_7,          KC_8,          KC_9,    KC_0,       KC_BSPC,
  KC_LCTL,          KC_DLR,  KC_RBRC,    S(KC_8),   S(KC_9),    S(KC_7),      RALT(KC_1), RALT(KC_QUOT), RALT(KC_BSLS), S(KC_0), S(KC_RBRC), KC_MINS,
  TD(TD_CAPS_LOCK), S(KC_1), RALT(KC_3), S(KC_EQL), S(KC_MINS), RALT(KC_2),   S(KC_6),    RALT(KC_LBRC), RALT(KC_RBRC), S(KC_5), S(KC_LBRC), KC_ESC,

  KC_LGUI, KC_TRNS,    LALT_T(KC_SPC),
  KC_ENT, MO(_SWITCH), KC_RALT
),

/* Function layer
 * ,-----------------------------------.   ,-----------------------------------.
 * | tab | F1  | F2  | F3  | F4  | F5  |   | F6  | F7  | F8  | F9  | F10 | del |
 * |-----+-----+-----+-----+-----+-----|   |-----+-----+-----+-----+-----+-----|
 * | cap |  x  |  x  |  <  |  >  |  x  |   |  ←  |  ↓  |  ↑  |  →  |  x  | F11 |
 * |-----+-----+-----+-----+-----+-----|   |-----+-----+-----+-----+-----+-----|
 * | ctr |  x  |  ⏮︎  |  ⏯︎  |  ⏭︎  |  x  |   |  x  | mut | vo↓ | vo↑ |  x  | esc |
 * `-----------------+-----+-----+-----|   |-----+-----+-----+-----------------'
 *                   | gui | fn1 | spc |   | ent | fn2 | alt |
 *                   `-----+-----+-----'   `-----+-----+-----'
 */
[_FUNCTION] = LAYOUT_split_3x6_3(
  KC_TAB,  KC_F1, KC_F2,   KC_F3,   KC_F4,      KC_F5,   KC_F6,   KC_F7,   KC_F8,      KC_F9,    KC_F10, KC_DEL,
  KC_LCTL, KC_NO, KC_NO,   KC_NUBS, S(KC_NUBS), KC_NO,   KC_LEFT, KC_DOWN, KC_UP,      KC_RGHT,  KC_NO,  KC_F11,
  KC_LSFT, KC_NO, KC_MPRV, KC_MPLY, KC_MNXT,    KC_NO,   KC_NO,   KC_MUTE, KC_VOLD, KC_VOLU, KC_NO,  KC_ESC,

  KC_LGUI, MO(_SWITCH), LALT_T(KC_SPC),
  KC_ENT,  KC_TRNS, KC_RALT
),

/* Layer-switching layer
 * ,-----------------------------------.   ,-----------------------------------.
 * | tab |  x  |  x  |  x  |  x  |  x  |   |  x  |  x  |  x  |  x  |  x  | del |
 * |-----+-----+-----+-----+-----+-----|   |-----+-----+-----+-----+-----+-----|
 * | ctl |  x  |  x  | fac | lol |  x  |   |  x  | qwe | col |  x  |  x  |  x  |
 * |-----+-----+-----+-----+-----+-----|   |-----+-----+-----+-----+-----+-----|
 * | sft |  x  |  x  |  x  |  x  |  x  |   |  x  |  x  |  x  |  x  |  x  | esc |
 * `-----------------+-----+-----+-----|   |-----+-----+-----+-----------------'
 *                   | sup | fn1 | spc |   | ent | fn2 | alt |
 *                   `-----+-----+-----'   `-----+-----+-----'
 */
[_SWITCH] = LAYOUT_split_3x6_3(
  KC_TAB,  KC_NO, KC_NO, KC_NO,         KC_NO,    KC_NO,   KC_NO, KC_NO,       KC_NO,           KC_NO, KC_NO, KC_BSPC,
  KC_LCTL, KC_NO, KC_NO, DF(_FACTORIO), DF(_LOL), KC_NO,   KC_NO, DF(_QWERTY), DF(_COLEMAK_DH), KC_NO, KC_NO, KC_NO,
  KC_LSFT, KC_NO, KC_NO, KC_NO,         KC_NO,    KC_NO,   KC_NO, KC_NO,       KC_NO,           KC_NO, KC_NO, KC_ESC,

  KC_LGUI, KC_TRNS, LALT_T(KC_SPC),
  KC_ENT, KC_TRNS, KC_RALT
),

/* League of Legends layer
 * ,-----------------------------------.   ,-----------------------------------.
 * |  c  |  1  |  2  |  3  |  4  |  5  |   |  y  |  u  |  i  |  o  |  p  | del |
 * |-----+-----+-----+-----+-----+-----|   |-----+-----+-----+-----+-----+-----|
 * | tab |  q  |  w  |  e  |  r  |  t  |   |  h  |  j  |  k  |  l  |  ñ  |  ´  |
 * |-----+-----+-----+-----+-----+-----|   |-----+-----+-----+-----+-----+-----|
 * | sft |  a  |  s  |  d  |  f  |  g  |   |  n  |  m  |  ,  |  .  |  -  | esc |
 * `-----------------+-----+-----+-----|   |-----+-----+-----+-----------------'
 *                   | ctl | fn1 | spc |   | ent | fn2 | alt |
 *                   `-----+-----+-----'   `-----+-----+-----'
 */
[_LOL] = LAYOUT_split_3x6_3(
  KC_C,    KC_1, KC_2, KC_3, KC_4, KC_5,   KC_Y, KC_U, KC_I,    KC_O,   KC_P,     KC_BSPC,
  KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T,   KC_H, KC_J, KC_K,    KC_L,   KC_SCLN,  KC_QUOT,
  KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G,   KC_N, KC_M, KC_COMM, KC_DOT, KC_SLASH, KC_ESC,

  KC_LCTL, MO(_SYMBOL), KC_SPC,
  KC_ENT,  MO(_FUNCTION), KC_RALT
),

/* Factorio layer
 * ,-----------------------------------.   ,-----------------------------------.
 * | tab |  q  |  w  |  e  |  r  |  t  |   |  y  |  u  |  i  |  o  |  p  | del |
 * |-----+-----+-----+-----+-----+-----|   |-----+-----+-----+-----+-----+-----|
 * | ctl |  a  |  s  |  d  |  f  |  g  |   |  h  |  j  |  k  |  l  |  ñ  |  ´  |
 * |-----+-----+-----+-----+-----+-----|   |-----+-----+-----+-----+-----+-----|
 * | sft |  z  |  x  |  c  |  v  |  b  |   |  n  |  m  |  ,  |  .  |  -  | esc |
 * `-----------------+-----+-----+-----|   |-----+-----+-----+-----------------'
 *                   | alt | fn1 | spa |   | ent | fn2 | alt |
 *                   `-----+-----+-----'   `-----+-----+-----'
 */
[_FACTORIO] = LAYOUT_split_3x6_3(
  KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T,   KC_Y, KC_U, KC_I,    KC_O,   KC_P,     KC_BSPC,
  KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G,   KC_H, KC_J, KC_K,    KC_L,   KC_SCLN,  KC_QUOT,
  KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,   KC_N, KC_M, KC_COMM, KC_DOT, KC_SLASH, KC_ESC,

  KC_LALT, MO(_SYMBOL),   KC_SPC,
  KC_ENT,  MO(_FUNCTION), KC_RALT
),
};
