/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#include "../../../inc/MarlinConfigPre.h"

#if HAS_GRAPHICAL_TFT

extern const uint8_t flowrate_64x64x4[2048] = {
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x99, 0x99, 0x99, 0x99, 
    0x77, 0x78, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x89, 0xff, 0xff, 0xff, 0xfe, 0x77, 0x77, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x89, 0xff, 0xff, 0xff, 0xfd, 0x67, 
    0x77, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x89, 0xff, 0xff, 0xff, 0xfd, 0x56, 0x77, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x98, 0x78, 0x88, 0x88, 0x88, 0x88, 0x89, 0xff, 0xff, 0xff, 0xfd, 0x56, 0x77, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0xa9, 0x7a, 0xe9, 0x79, 0xa7, 0x77, 0x88, 0x88, 0x89, 
    0xff, 0xff, 0xff, 0xfd, 0x55, 0x77, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x89, 0xff, 0xce, 0xfe, 
    0xcf, 0xf9, 0x78, 0x87, 0x88, 0x89, 0xff, 0xff, 0xff, 0xfd, 0x55, 0x77, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0xae, 0xcd, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xce, 0xa7, 0x77, 0x89, 0xff, 
    0xff, 0xff, 0xfd, 0x55, 0x77, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xc7, 0x77, 0x79, 0xff, 0xff, 0xff, 0xfd, 0x55, 0x77, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x8a, 0xdd, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xec, 0xc9, 0x79, 0xff, 0xff, 
    0xff, 0xfd, 0x55, 0x77, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x8b, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xfa, 0x78, 0xff, 0xff, 0xff, 0xfd, 0x55, 0x77, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x8b, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfa, 0x68, 0xff, 0xff, 0xff, 
    0xfd, 0x55, 0x77, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x8b, 0xef, 0xff, 0xff, 0xff, 0xff, 0xed, 0xcd, 0xef, 0xff, 0xff, 
    0xff, 0xff, 0xdb, 0xff, 0xff, 0xff, 0xfd, 0x55, 0x77, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x8c, 0xff, 0xff, 0xff, 0xff, 
    0xea, 0x65, 0x45, 0x58, 0xcf, 0xff, 0xff, 0xff, 0xfc, 0xff, 0xff, 0xff, 0xfd, 
    0x55, 0x77, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x8a, 0xff, 0xff, 0xff, 0xfd, 0x64, 0x55, 0x55, 0x55, 0x59, 0xff, 0xff, 
    0xff, 0xf9, 0xff, 0xff, 0xff, 0xfd, 0x55, 0x77, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0xad, 0xff, 0xff, 0xff, 0xd5, 0x45, 
    0x56, 0x66, 0x66, 0x66, 0xaf, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xfd, 0x55, 
    0x77, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x89, 
    0xff, 0xff, 0xff, 0xff, 0x84, 0x55, 0x67, 0x77, 0x77, 0x77, 0x6c, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xfd, 0x55, 0x77, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0xcf, 0xff, 0xff, 0xfc, 0x45, 0x56, 0x77, 
    0x77, 0x88, 0x77, 0x79, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x55, 0x77, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0xaf, 
    0xff, 0xff, 0xf9, 0x45, 0x67, 0x77, 0x88, 0x88, 0x87, 0x78, 0xef, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xfd, 0x55, 0x77, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x8a, 0xef, 0xff, 0xff, 0xf8, 0x55, 0x67, 0x78, 0x88, 
    0x88, 0x88, 0x77, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x55, 0x77, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x8c, 0xff, 0xff, 
    0xff, 0xf7, 0x56, 0x77, 0x88, 0x88, 0x88, 0x88, 0x87, 0xdf, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xfd, 0x55, 0x77, 0xac, 0xef, 0xfd, 0xca, 0x87, 0x78, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0xcf, 0xff, 0xff, 0xf9, 0x56, 0x77, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x55, 0x9c, 0xff, 0xff, 
    0xff, 0xff, 0xc9, 0x77, 0x78, 0x88, 0x88, 0x88, 0x88, 0x87, 0xaf, 0xff, 0xff, 
    0xfb, 0x56, 0x77, 0x88, 0x88, 0x88, 0x88, 0x89, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xfd, 0x59, 0xef, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x97, 0x77, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0xef, 0xff, 0xff, 0xfe, 0x66, 0x77, 0x88, 0x88, 0x88, 0x88, 
    0x8b, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x7d, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xd9, 0x77, 0x78, 0x88, 0x88, 0x88, 0x88, 0xdf, 0xff, 0xff, 0xff, 
    0xb6, 0x77, 0x78, 0x88, 0x88, 0x88, 0x9e, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xfd, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x67, 0x77, 0x88, 0x88, 
    0x88, 0x87, 0x7a, 0xff, 0xff, 0xff, 0xfa, 0x67, 0x77, 0x88, 0x88, 0x89, 0xef, 
    0xff, 0xff, 0xfa, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0x96, 0x77, 0x88, 0x88, 0x88, 0x87, 0x7b, 0xff, 0xff, 0xff, 0xff, 
    0xc8, 0x77, 0x78, 0x88, 0xae, 0xff, 0xff, 0xff, 0xfa, 0xff, 0xff, 0xff, 0xfe, 
    0xff, 0xff, 0xfe, 0xa6, 0x6a, 0xef, 0xff, 0xff, 0xb6, 0x77, 0x78, 0x88, 0x88, 
    0x88, 0x7c, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xca, 0xaa, 0xbd, 0xff, 0xff, 0xff, 
    0xff, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfa, 0x44, 0x55, 0xaf, 0xff, 
    0xff, 0xd5, 0x67, 0x78, 0x88, 0x88, 0x88, 0x78, 0x9c, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x77, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xf6, 0x45, 0x66, 0x7f, 0xff, 0xff, 0xe5, 0x67, 0x78, 0x88, 0x88, 0x88, 
    0x87, 0x7a, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 
    0x46, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf6, 0x56, 0x67, 0x8f, 0xff, 0xff, 
    0xe5, 0x67, 0x78, 0x88, 0x88, 0x88, 0x87, 0x7a, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x57, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xfa, 0x56, 0x77, 0xbf, 0xff, 0xff, 0xd5, 0x56, 0x78, 0x88, 0x88, 0x88, 0x87, 
    0x78, 0x87, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xd6, 0x65, 0x57, 
    0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xfe, 0xa7, 0x8b, 0xef, 0xff, 0xff, 0xb5, 
    0x56, 0x78, 0x88, 0x88, 0x88, 0x88, 0x77, 0x76, 0xaf, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0x94, 0x55, 0x68, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0x85, 0x67, 0x78, 0x88, 0x88, 0x88, 0x88, 0x87, 
    0x77, 0x89, 0x79, 0xff, 0xef, 0xff, 0xef, 0xf9, 0x68, 0x65, 0x56, 0x68, 0xff, 
    0xff, 0xff, 0xfd, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0x55, 0x67, 
    0x78, 0x88, 0x88, 0x88, 0x88, 0x87, 0x77, 0x77, 0x66, 0xca, 0x6b, 0xfb, 0x6a, 
    0xc5, 0x45, 0x55, 0x67, 0x79, 0xff, 0xff, 0xff, 0xfd, 0x7d, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xd7, 0x45, 0x67, 0x78, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 
    0x77, 0x76, 0x66, 0x55, 0x85, 0x55, 0x55, 0x56, 0x66, 0x77, 0x79, 0xff, 0xff, 
    0xff, 0xfd, 0x48, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x84, 0x56, 0x77, 0x78, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x77, 0x77, 0x76, 0x66, 0x66, 0x66, 0x66, 
    0x66, 0x77, 0x77, 0x79, 0xff, 0xff, 0xff, 0xfd, 0x45, 0x8c, 0xff, 0xff, 0xff, 
    0xff, 0xb7, 0x45, 0x56, 0x77, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 
    0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x89, 0xff, 0xff, 0xff, 
    0xfd, 0x55, 0x66, 0x9b, 0xde, 0xed, 0xb8, 0x54, 0x55, 0x67, 0x77, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 
    0x78, 0x88, 0x89, 0xff, 0xff, 0xff, 0xfd, 0x55, 0x66, 0x66, 0x55, 0x55, 0x55, 
    0x55, 0x66, 0x77, 0x78, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x87, 0x77, 0x88, 0x88, 0x88, 0x88, 0x89, 0xff, 0xff, 0xff, 0xfd, 
    0x55, 0x67, 0x77, 0x66, 0x65, 0x56, 0x66, 0x77, 0x77, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x89, 0xff, 0xff, 0xff, 0xfd, 0x55, 0x67, 0x77, 0x77, 0x76, 0x67, 0x77, 
    0x77, 0x78, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x89, 0xff, 0xff, 0xff, 0xfd, 0x55, 
    0x77, 0x87, 0x77, 0x77, 0x77, 0x77, 0x78, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x89, 0xff, 0xff, 0xff, 0xfd, 0x55, 0x77, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x89, 0xff, 0xff, 0xff, 0xfd, 0x55, 0x77, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x99, 0x99, 0x99, 0x99, 0x9a, 
    0xff, 0xff, 0xff, 0xfd, 0x77, 0x89, 0x99, 0x99, 0x99, 0x77, 0x78, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xe8, 0x77, 0x77, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x79, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x76, 0x77, 0x77, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x77, 0x8e, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc6, 
    0x56, 0x67, 0x77, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x77, 0x77, 0xdf, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xfb, 0x55, 0x56, 0x77, 0x77, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 
    0x77, 0x6c, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x94, 0x45, 0x66, 
    0x77, 0x78, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x77, 0x76, 0xbf, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xe7, 0x45, 0x56, 0x67, 0x77, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 
    0x77, 0x6a, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x64, 0x55, 0x67, 0x77, 0x78, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x77, 0x76, 0x8f, 0xff, 0xff, 0xff, 0xff, 
    0xd5, 0x45, 0x56, 0x77, 0x77, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 
    0x77, 0x77, 0xef, 0xff, 0xff, 0xfc, 0x54, 0x55, 0x67, 0x77, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x77, 0x77, 0x7d, 0xff, 0xff, 0xa4, 0x45, 
    0x66, 0x77, 0x78, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x77, 0x76, 0xcf, 0xf9, 0x44, 0x56, 0x67, 0x77, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x77, 0x6b, 0x85, 0x55, 0x66, 0x77, 
    0x78, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x77, 0x76, 0x65, 0x56, 0x77, 0x77, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x77, 0x76, 0x67, 0x77, 0x78, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x77, 0x77, 0x77, 0x78, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x77, 0x77, 0x88, 0x88, 0x88, 0x88, 
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88
};

#endif // HAS_GRAPHICAL_TFT