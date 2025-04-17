
#line 1 "hb-buffer-deserialize-json.rl"
/*
 * Copyright © 2013  Google, Inc.
 *
 *  This is part of HarfBuzz, a text shaping library.
 *
 * Permission is hereby granted, without written agreement and without
 * license or royalty fees, to use, copy, modify, and distribute this
 * software and its documentation for any purpose, provided that the
 * above copyright notice and the following two paragraphs appear in
 * all copies of this software.
 *
 * IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE TO ANY PARTY FOR
 * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES
 * ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN
 * IF THE COPYRIGHT HOLDER HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 *
 * THE COPYRIGHT HOLDER SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING,
 * BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS
 * ON AN "AS IS" BASIS, AND THE COPYRIGHT HOLDER HAS NO OBLIGATION TO
 * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
 *
 * Google Author(s): Behdad Esfahbod
 */

#ifndef HB_BUFFER_DESERIALIZE_JSON_HH
#define HB_BUFFER_DESERIALIZE_JSON_HH

#include "hb.hh"


#line 33 "hb-buffer-deserialize-json.hh"
static const unsigned char _deserialize_json_trans_keys[] = {
	0u, 0u, 9u, 34u, 97u, 121u, 120u, 121u, 34u, 34u, 9u, 58u, 9u, 57u, 48u, 57u, 
	9u, 125u, 9u, 125u, 9u, 93u, 9u, 125u, 34u, 34u, 9u, 58u, 9u, 57u, 48u, 57u, 
	9u, 125u, 9u, 125u, 108u, 108u, 34u, 34u, 9u, 58u, 9u, 57u, 9u, 125u, 9u, 125u, 
	120u, 121u, 34u, 34u, 9u, 58u, 9u, 57u, 48u, 57u, 9u, 125u, 9u, 125u, 34u, 34u, 
	9u, 58u, 9u, 57u, 48u, 57u, 9u, 125u, 9u, 125u, 108u, 108u, 34u, 34u, 9u, 58u, 
	9u, 57u, 9u, 125u, 9u, 125u, 34u, 34u, 9u, 58u, 9u, 57u, 34u, 92u, 9u, 125u, 
	34u, 92u, 9u, 125u, 9u, 125u, 34u, 34u, 9u, 58u, 9u, 57u, 48u, 57u, 9u, 125u, 
	34u, 34u, 9u, 58u, 9u, 57u, 9u, 125u, 98u, 98u, 9u, 123u, 9u, 123u, 9u, 123u, 
	0
};

static const char _deserialize_json_key_spans[] = {
	0, 26, 25, 2, 1, 50, 49, 10, 
	117, 117, 85, 117, 1, 50, 49, 10, 
	117, 117, 1, 1, 50, 49, 117, 117, 
	2, 1, 50, 49, 10, 117, 117, 1, 
	50, 49, 10, 117, 117, 1, 1, 50, 
	49, 117, 117, 1, 50, 49, 59, 117, 
	59, 117, 117, 1, 50, 49, 10, 117, 
	1, 50, 49, 117, 1, 115, 115, 115
};

static const short _deserialize_json_index_offsets[] = {
	0, 0, 27, 53, 56, 58, 109, 159, 
	170, 288, 406, 492, 610, 612, 663, 713, 
	724, 842, 960, 962, 964, 1015, 1065, 1183, 
	1301, 1304, 1306, 1357, 1407, 1418, 1536, 1654, 
	1656, 1707, 1757, 1768, 1886, 2004, 2006, 2008, 
	2059, 2109, 2227, 2345, 2347, 2398, 2448, 2508, 
	2626, 2686, 2804, 2922, 2924, 2975, 3025, 3036, 
	3154, 3156, 3207, 3257, 3375, 3377, 3493, 3609
};

static const char _deserialize_json_indicies[] = {
	0, 0, 0, 0, 0, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	0, 1, 2, 1, 3, 1, 4, 5, 
	1, 6, 7, 8, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	9, 1, 8, 10, 10, 1, 11, 12, 
	1, 13, 1, 13, 13, 13, 13, 13, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 13, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 14, 1, 14, 14, 
	14, 14, 14, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 14, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 15, 1, 1, 16, 17, 17, 
	17, 17, 17, 17, 17, 17, 17, 1, 
	18, 19, 19, 19, 19, 19, 19, 19, 
	19, 19, 1, 20, 20, 20, 20, 20, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 20, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 21, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 22, 
	1, 23, 23, 23, 23, 23, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	23, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 0, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 24, 1, 24, 
	24, 24, 24, 24, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 24, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 25, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 25, 1, 20, 20, 20, 
	20, 20, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 20, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	21, 1, 1, 1, 19, 19, 19, 19, 
	19, 19, 19, 19, 19, 19, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 22, 1, 26, 1, 26, 26, 26, 
	26, 26, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 26, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 27, 1, 
	27, 27, 27, 27, 27, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 27, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 28, 1, 1, 29, 
	30, 30, 30, 30, 30, 30, 30, 30, 
	30, 1, 31, 32, 32, 32, 32, 32, 
	32, 32, 32, 32, 1, 33, 33, 33, 
	33, 33, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 33, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	34, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 35, 1, 33, 33, 33, 33, 33, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 33, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 34, 1, 
	1, 1, 32, 32, 32, 32, 32, 32, 
	32, 32, 32, 32, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 35, 
	1, 36, 1, 37, 1, 37, 37, 37, 
	37, 37, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 37, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 38, 1, 
	38, 38, 38, 38, 38, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 38, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 39, 
	40, 40, 40, 40, 40, 40, 40, 40, 
	40, 1, 41, 41, 41, 41, 41, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 41, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 42, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 43, 1, 
	41, 41, 41, 41, 41, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 41, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 42, 1, 1, 1, 44, 
	44, 44, 44, 44, 44, 44, 44, 44, 
	44, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 43, 1, 45, 46, 
	1, 47, 1, 47, 47, 47, 47, 47, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 47, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 48, 1, 48, 48, 
	48, 48, 48, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 48, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 49, 1, 1, 50, 51, 51, 
	51, 51, 51, 51, 51, 51, 51, 1, 
	52, 53, 53, 53, 53, 53, 53, 53, 
	53, 53, 1, 54, 54, 54, 54, 54, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 54, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 55, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 56, 
	1, 54, 54, 54, 54, 54, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	54, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 55, 1, 1, 1, 
	53, 53, 53, 53, 53, 53, 53, 53, 
	53, 53, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 56, 1, 57, 
	1, 57, 57, 57, 57, 57, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	57, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 58, 1, 58, 58, 58, 58, 
	58, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 58, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	59, 1, 1, 60, 61, 61, 61, 61, 
	61, 61, 61, 61, 61, 1, 62, 63, 
	63, 63, 63, 63, 63, 63, 63, 63, 
	1, 64, 64, 64, 64, 64, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	64, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 65, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 66, 1, 64, 
	64, 64, 64, 64, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 64, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 65, 1, 1, 1, 63, 63, 
	63, 63, 63, 63, 63, 63, 63, 63, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 66, 1, 67, 1, 68, 
	1, 68, 68, 68, 68, 68, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	68, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 69, 1, 69, 69, 69, 69, 
	69, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 69, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 70, 71, 71, 71, 71, 
	71, 71, 71, 71, 71, 1, 72, 72, 
	72, 72, 72, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 72, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 73, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 74, 1, 72, 72, 72, 72, 
	72, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 72, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 73, 
	1, 1, 1, 75, 75, 75, 75, 75, 
	75, 75, 75, 75, 75, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	74, 1, 76, 1, 76, 76, 76, 76, 
	76, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 76, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 77, 1, 77, 
	77, 77, 77, 77, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 77, 1, 
	78, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 79, 80, 
	80, 80, 80, 80, 80, 80, 80, 80, 
	1, 82, 81, 81, 81, 81, 81, 81, 
	81, 81, 81, 81, 81, 81, 81, 81, 
	81, 81, 81, 81, 81, 81, 81, 81, 
	81, 81, 81, 81, 81, 81, 81, 81, 
	81, 81, 81, 81, 81, 81, 81, 81, 
	81, 81, 81, 81, 81, 81, 81, 81, 
	81, 81, 81, 81, 81, 81, 81, 81, 
	81, 81, 81, 83, 81, 84, 84, 84, 
	84, 84, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 84, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	85, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 86, 1, 81, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 81, 1, 87, 
	87, 87, 87, 87, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 87, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 88, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 89, 1, 87, 87, 87, 
	87, 87, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 87, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	88, 1, 1, 1, 90, 90, 90, 90, 
	90, 90, 90, 90, 90, 90, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 89, 1, 91, 1, 91, 91, 91, 
	91, 91, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 91, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 92, 1, 
	92, 92, 92, 92, 92, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 92, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 93, 1, 1, 94, 
	95, 95, 95, 95, 95, 95, 95, 95, 
	95, 1, 23, 96, 96, 96, 96, 96, 
	96, 96, 96, 96, 1, 23, 23, 23, 
	23, 23, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 23, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	0, 1, 1, 1, 96, 96, 96, 96, 
	96, 96, 96, 96, 96, 96, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 24, 1, 97, 1, 97, 97, 97, 
	97, 97, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 97, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 98, 1, 
	98, 98, 98, 98, 98, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 98, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 99, 
	100, 100, 100, 100, 100, 100, 100, 100, 
	100, 1, 87, 87, 87, 87, 87, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 87, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 88, 1, 1, 
	1, 101, 101, 101, 101, 101, 101, 101, 
	101, 101, 101, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 89, 1, 
	8, 1, 102, 102, 102, 102, 102, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 102, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 103, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 104, 1, 103, 103, 
	103, 103, 103, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 103, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	104, 1, 25, 25, 25, 25, 25, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 25, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 104, 1, 0
};

static const char _deserialize_json_trans_targs[] = {
	1, 0, 2, 3, 18, 24, 37, 43, 
	51, 56, 60, 4, 12, 5, 6, 7, 
	8, 11, 8, 11, 9, 1, 10, 9, 
	10, 63, 13, 14, 15, 16, 17, 16, 
	17, 9, 1, 10, 19, 20, 21, 22, 
	23, 9, 1, 10, 23, 25, 31, 26, 
	27, 28, 29, 30, 29, 30, 9, 1, 
	10, 32, 33, 34, 35, 36, 35, 36, 
	9, 1, 10, 38, 39, 40, 41, 42, 
	9, 1, 10, 42, 44, 45, 46, 49, 
	50, 46, 47, 48, 9, 1, 10, 9, 
	1, 10, 50, 52, 53, 54, 9, 55, 
	55, 57, 58, 49, 59, 59, 61, 62, 
	1
};

static const char _deserialize_json_trans_actions[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 1, 
	1, 1, 0, 0, 2, 2, 2, 0, 
	0, 3, 0, 0, 1, 1, 1, 0, 
	0, 4, 4, 4, 0, 0, 0, 1, 
	1, 5, 5, 5, 0, 0, 0, 0, 
	0, 1, 1, 1, 0, 0, 6, 6, 
	6, 0, 0, 1, 1, 1, 0, 0, 
	7, 7, 7, 0, 0, 0, 1, 1, 
	8, 8, 8, 0, 0, 0, 1, 9, 
	9, 0, 10, 0, 11, 11, 11, 12, 
	12, 12, 10, 0, 0, 1, 1, 1, 
	0, 0, 0, 13, 13, 14, 0, 0, 
	15
};

static const int deserialize_json_start = 61;
static const int deserialize_json_first_final = 61;
static const int deserialize_json_error = 0;

static const int deserialize_json_en_main = 61;


#line 115 "hb-buffer-deserialize-json.rl"


static hb_bool_t
_hb_buffer_deserialize_json (hb_buffer_t *buffer,
				    const char *buf,
				    unsigned int buf_len,
				    const char **end_ptr,
				    hb_font_t *font)
{
  const char *p = buf, *pe = buf + buf_len;

  /* Ensure we have positions. */
  (void) hb_buffer_get_glyph_positions (buffer, nullptr);

  const char *tok = nullptr;
  int cs;
  hb_glyph_info_t info = {0};
  hb_glyph_position_t pos = {0};
  
#line 594 "hb-buffer-deserialize-json.hh"
	{
	cs = deserialize_json_start;
	}

#line 597 "hb-buffer-deserialize-json.hh"
	{
	int _slen;
	int _trans;
	const unsigned char *_keys;
	const char *_inds;
	if ( p == pe )
		goto _test_eof;
	if ( cs == 0 )
		goto _out;
_resume:
	_keys = _deserialize_json_trans_keys + (cs<<1);
	_inds = _deserialize_json_indicies + _deserialize_json_index_offsets[cs];

	_slen = _deserialize_json_key_spans[cs];
	_trans = _inds[ _slen > 0 && _keys[0] <=(*p) &&
		(*p) <= _keys[1] ?
		(*p) - _keys[0] : _slen ];

	cs = _deserialize_json_trans_targs[_trans];

	if ( _deserialize_json_trans_actions[_trans] == 0 )
		goto _again;

	switch ( _deserialize_json_trans_actions[_trans] ) {
	case 15:
#line 38 "hb-buffer-deserialize-json.rl"
	{
	hb_memset (&info, 0, sizeof (info));
	hb_memset (&pos , 0, sizeof (pos ));
}
	break;
	case 3:
#line 43 "hb-buffer-deserialize-json.rl"
	{
	buffer->add_info (info);
	if (unlikely (!buffer->successful))
	  return false;
	buffer->pos[buffer->len - 1] = pos;
	*end_ptr = p;
}
	break;
	case 1:
#line 51 "hb-buffer-deserialize-json.rl"
	{
	tok = p;
}
	break;
	case 10:
#line 55 "hb-buffer-deserialize-json.rl"
	{ if (unlikely (!buffer->ensure_glyphs ())) return false; }
	break;
	case 14:
#line 56 "hb-buffer-deserialize-json.rl"
	{ if (unlikely (!buffer->ensure_unicode ())) return false; }
	break;
	case 11:
#line 58 "hb-buffer-deserialize-json.rl"
	{
	/* TODO Unescape \" and \\ if found. */
	if (!hb_font_glyph_from_string (font,
					tok+1, p - tok - 2, /* Skip "" */
					&info.codepoint))
	  return false;
}
	break;
	case 12:
#line 66 "hb-buffer-deserialize-json.rl"
	{ if (!parse_uint (tok, p, &info.codepoint)) return false; }
	break;
	case 5:
#line 67 "hb-buffer-deserialize-json.rl"
	{ if (!parse_uint (tok, p, &info.cluster )) return false; }
	break;
	case 6:
#line 68 "hb-buffer-deserialize-json.rl"
	{ if (!parse_int  (tok, p, &pos.x_offset )) return false; }
	break;
	case 7:
#line 69 "hb-buffer-deserialize-json.rl"
	{ if (!parse_int  (tok, p, &pos.y_offset )) return false; }
	break;
	case 2:
#line 70 "hb-buffer-deserialize-json.rl"
	{ if (!parse_int  (tok, p, &pos.x_advance)) return false; }
	break;
	case 4:
#line 71 "hb-buffer-deserialize-json.rl"
	{ if (!parse_int  (tok, p, &pos.y_advance)) return false; }
	break;
	case 8:
#line 72 "hb-buffer-deserialize-json.rl"
	{ if (!parse_uint (tok, p, &info.mask    )) return false; }
	break;
	case 9:
#line 51 "hb-buffer-deserialize-json.rl"
	{
	tok = p;
}
#line 55 "hb-buffer-deserialize-json.rl"
	{ if (unlikely (!buffer->ensure_glyphs ())) return false; }
	break;
	case 13:
#line 51 "hb-buffer-deserialize-json.rl"
	{
	tok = p;
}
#line 56 "hb-buffer-deserialize-json.rl"
	{ if (unlikely (!buffer->ensure_unicode ())) return false; }
	break;
#line 689 "hb-buffer-deserialize-json.hh"
	}

_again:
	if ( cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	_out: {}
	}

#line 136 "hb-buffer-deserialize-json.rl"


  *end_ptr = p;

  return p == pe;
}

#endif /* HB_BUFFER_DESERIALIZE_JSON_HH */
