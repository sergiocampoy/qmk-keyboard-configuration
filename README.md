# My custom keymap for the corne keyboard

Welcome to my config files for my hand-wired corne keyboard!

Most of the information will be here in this README. If you just want to flash my configuration and test it, you can download the .hex file and feed it to QMK toolbox. Be aware that his might not work depending on how the keys are wired to the arduino or how both halves are connected, so proceed with caution.

If you want to peek the code or tinker with it: go ahead! I tried my best to document it both in the files and here in the README.

## Layers

Warning! For the layers to work as shown, you have to tell the OS that the
keyboard is spanish. Otherwise, the letter ñ and most of the symbols won't work properly. 

There are two kinds of layers: the base layers (qwerty, colemak-dh and game layers) and held layers (the rest). You change base layers by pressing fn1 + fn2 + the layer you want to switch to. That change is permanent until you switch back or unplug the keyboard. The other layers are activated by holding fn1 or fn2 from any base layer.

```
Base layer 
 + fn1       -> Symbol layer
 + fn2       -> Function layer
 + fn1 + fn2 -> Layer-switching layer
```


```
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
 
/* League of Legends layer
 * ,-----------------------------------.   ,-----------------------------------.
 * | esc |  1  |  2  |  3  |  4  |  5  |   |  y  |  u  |  i  |  o  |  p  | del |
 * |-----+-----+-----+-----+-----+-----|   |-----+-----+-----+-----+-----+-----|
 * | tab |  q  |  w  |  e  |  r  |  t  |   |  h  |  j  |  k  |  l  |  ñ  |  ´  |
 * |-----+-----+-----+-----+-----+-----|   |-----+-----+-----+-----+-----+-----|
 * | sft |  a  |  s  |  d  |  f  |  g  |   |  n  |  m  |  ,  |  .  |  -  | esc |
 * `-----------------+-----+-----+-----|   |-----+-----+-----+-----------------'
 *                   | ctl | fn1 | spc |   | ent | fn2 | alt |
 *                   `-----+-----+-----'   `-----+-----+-----'
 */

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
```

# [Tap dance](https://beta.docs.qmk.fm/using-qmk/software-features/feature_tap_dance)
Hold the Shift key to use it normally or double tap it to trigger Caps-lock
 
# [Tap-hold](https://beta.docs.qmk.fm/using-qmk/software-features/tap_hold)
Tap the Space "bar" to use it normally or hold it for it to work as the Alt key

Both tap dance and tap-hold are disabled in gaming layers because they add a slight
delay when pressing a key.
