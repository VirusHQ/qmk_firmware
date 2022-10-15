/* Copyright 2019
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "quantum.h"

inline void led_pin_on(uint8_t pin) { palSetPad(GPIOB, pin); };
inline void led_pin_off(uint8_t pin) { palClearPad(GPIOB, pin); };

inline void led1_on(void) { led_pin_on(8); };
inline void led2_on(void) { led_pin_on(5); };
inline void led3_on(void) { led_pin_on(6); };

inline void led1_off(void) { led_pin_off(8); };
inline void led2_off(void) { led_pin_off(5); };
inline void led3_off(void) { led_pin_off(6); };

#define LAYOUT_ergodox(                                         \
    L00,    L01,    L02,    L03,    L04,    L05,                \
    L10,    L11,    L12,    L13,    L14,    L15,    L16,        \
    L20,    L21,    L22,    L23,    L24,    L25,    L26,        \
    L30,    L31,    L32,    L33,    L34,    L35,    L36,        \
    L40,    L41,    L42,    L43,    L44,                        \
                                    L56,    L55,    L54,        \
                                    L52,    L51,    L50,        \
                                                                \
            R05,    R04,    R03,    R02,    R01,    R00,        \
    R16,    R15,    R14,    R13,    R12,    R11,    R10,        \
    R26,    R25,    R24,    R23,    R22,    R21,    R20,        \
    R36,    R35,    R34,    R33,    R32,    R31,    R30,        \
                    R44,    R43,    R42,    R41,    R40,        \
    R54,    R55,    R56,                                        \
    R50,    R51,    R52                                         \
    )                                                           \
    /* matrix positions */                                      \
    {                                                           \
    {   L00,    L01,    L02,    L03,    L04,    L05 },          \
    {   L10,    L11,    L12,    L13,    L14,    L15,    L16 },  \
    {   L20,    L21,    L22,    L23,    L24,    L25,    L26 },  \
    {   L30,    L31,    L32,    L33,    L34,    L35,    L36},   \
    {   L40,    L41,    L42,    L43,    L44     },              \
    {   L50,    L51,    L52,    KC_NO,  L54,    L55,    L56 },  \
                                                                \
    {   R00,    R01,    R02,    R03,    R04,    R05 },          \
    {   R10,    R11,    R12,    R13,    R14,    R15,    R16 },  \
    {   R20,    R21,    R22,    R23,    R24,    R25,    R26 },  \
    {   R30,    R31,    R32,    R33,    R34,    R35,    R36},   \
    {   R40,    R41,    R42,    R43,    R44     },              \
    {   R50,    R51,    R52,    KC_NO,  R54,    R55,    R56 },  \
    }
