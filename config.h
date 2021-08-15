/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */

// USB cable plugs to the left keyboard
#define MASTER_LEFT

// Uses the serial protocol to connect the two halves
#define USE_SERIAL_PD2

// dunno what this is, but I'm afraid to remove it
#define TAPPING_FORCE_HOLD

// Max delay in ms I have to tap dance a key
#define TAPPING_TERM 200

// Fixes some random alt activation when pressing space
#define IGNORE_MOD_TAP_INTERRUPT