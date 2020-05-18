/* * Copyright (c) 2020-present Samsung Electronics Co., Ltd
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301
 *  USA
 */


/* This file is automatically generated by the gen_unicode.py script
* from https://www.unicode.org/Public/13.0.0/ucd/DerivedCoreProperties.txt
* DO NOT EDIT!
*/

#include "UnicodeIdentifierTables.h"

namespace Escargot {
namespace EscargotLexer {

/* Starting codepoints of identifier ranges. */
const uint16_t identRangeStart[532] = {
    170, 181, 186, 192, 216, 248, 444, 661, 710, 736, 748, 768, 890, 891, 895, 902, 903, 904, 908, 931, 1015, 1155, 1162, 1329, 1369, 1376, 1425, 1471, 1476, 1479, 1488, 1519, 1552, 1568, 1601, 1646, 1649, 1749, 1750, 1759, 1770, 1791, 1808, 1809, 1810, 1869, 1984, 2042, 2045, 2048, 2075, 2085, 2089, 2112, 2144, 2208, 2230, 2259, 2275, 2308, 2363, 2364, 2365, 2366, 2382, 2385, 2406, 2417, 2418, 2434, 2437, 2447, 2451, 2474, 2482, 2486, 2492, 2493, 2494, 2503, 2507, 2510, 2519, 2524, 2527, 2534, 2556, 2561, 2575, 2579, 2602, 2610, 2613, 2616, 2620, 2631, 2635, 2641, 2649, 2654, 2662, 2689, 2703, 2707, 2730, 2738, 2741, 2748, 2749, 2750, 2759, 2768, 2784, 2790, 2809, 2810, 2817, 2818, 2821, 2831, 2835, 2858, 2866, 2869, 2876, 2877, 2878, 2879, 2880, 2881, 2887, 2891, 2901, 2908, 2911, 2918, 2929, 2946, 2947, 2958, 2962, 2969, 2972, 2979, 2984, 2990, 3006, 3009, 3014, 3018, 3024, 3031, 3046, 3072, 3073, 3077, 3086, 3090, 3114, 3133, 3134, 3142, 3146, 3157, 3160, 3168, 3174, 3200, 3201, 3202, 3205, 3214, 3218, 3242, 3253, 3260, 3261, 3262, 3263, 3264, 3270, 3271, 3274, 3285, 3294, 3302, 3313, 3328, 3342, 3346, 3390, 3398, 3402, 3406, 3412, 3423, 3430, 3450, 3457, 3458, 3461, 3482, 3507, 3517, 3520, 3530, 3535, 3542, 3558, 3570, 3585, 3634, 3648, 3655, 3664, 3713, 3716, 3724, 3749, 3762, 3776, 3782, 3792, 3804, 3840, 3864, 3872, 3893, 3902, 3913, 3953, 3968, 3974, 3993, 4038, 4096, 4146, 4153, 4160, 4176, 4194, 4227, 4238, 4239, 4240, 4256, 4295, 4301, 4304, 4348, 4349, 4682, 4688, 4696, 4704, 4746, 4752, 4786, 4792, 4800, 4808, 4824, 4882, 4888, 4957, 4969, 4992, 5024, 5112, 5121, 5743, 5761, 5792, 5870, 5888, 5902, 5920, 5952, 5984, 5998, 6002, 6016, 6071, 6087, 6103, 6108, 6109, 6112, 6155, 6160, 6176, 6212, 6272, 6314, 6320, 6400, 6432, 6448, 6451, 6470, 6512, 6528, 6576, 6608, 6656, 6688, 6742, 6743, 6744, 6752, 6753, 6754, 6755, 6783, 6784, 6800, 6823, 6832, 6847, 6912, 6917, 6965, 6966, 6972, 6973, 6979, 6992, 7019, 7040, 7043, 7074, 7083, 7143, 7144, 7150, 7151, 7168, 7232, 7245, 7296, 7312, 7357, 7376, 7380, 7394, 7406, 7413, 7416, 7424, 7545, 7675, 7960, 7968, 8008, 8016, 8025, 8064, 8118, 8126, 8130, 8134, 8144, 8150, 8160, 8178, 8182, 8204, 8205, 8255, 8276, 8305, 8319, 8336, 8400, 8417, 8421, 8450, 8455, 8458, 8469, 8472, 8473, 8484, 8495, 8508, 8517, 8526, 8544, 11264, 11312, 11360, 11499, 11520, 11559, 11565, 11568, 11631, 11647, 11648, 11680, 11688, 11696, 11704, 11712, 11720, 11728, 11736, 11744, 12293, 12294, 12295, 12321, 12337, 12344, 12348, 12353, 12441, 12540, 12549, 12593, 12704, 12784, 13312, 19968, 40960, 40982, 42192, 42240, 42512, 42560, 42607, 42612, 42623, 42624, 42775, 42786, 42865, 42891, 42896, 42946, 42997, 43000, 43003, 43011, 43015, 43020, 43052, 43072, 43136, 43216, 43232, 43259, 43264, 43312, 43360, 43392, 43396, 43444, 43471, 43472, 43488, 43494, 43495, 43520, 43584, 43588, 43597, 43600, 43616, 43633, 43642, 43643, 43644, 43645, 43646, 43697, 43698, 43713, 43714, 43739, 43744, 43756, 43762, 43763, 43766, 43777, 43785, 43793, 43808, 43816, 43824, 43868, 43888, 44006, 44009, 44012, 44013, 44016, 44032, 55216, 55243, 63744, 64112, 64256, 64275, 64285, 64286, 64287, 64298, 64312, 64318, 64323, 64326, 64467, 64848, 64914, 65008, 65024, 65056, 65075, 65101, 65136, 65142, 65296, 65313, 65343, 65382, 65393, 65474, 65482, 65490, 65498
};

/* Lengths of identifier ranges. */
const uint16_t identRangeLength[532] = {
    1, 3, 1, 22, 30, 196, 204, 44, 11, 4, 3, 119, 1, 2, 1, 1, 1, 2, 21, 82, 138, 4, 165, 37, 1, 40, 44, 3, 1, 1, 26, 3, 10, 33, 40, 3, 98, 1, 6, 9, 18, 1, 1, 1, 56, 101, 53, 1, 1, 27, 10, 4, 4, 27, 10, 20, 17, 14, 33, 55, 1, 1, 1, 16, 3, 18, 9, 1, 16, 1, 7, 1, 21, 6, 1, 3, 1, 1, 6, 1, 3, 1, 1, 1, 4, 11, 3, 9, 1, 21, 6, 1, 1, 1, 6, 1, 2, 1, 3, 1, 16, 12, 2, 21, 6, 1, 4, 1, 1, 7, 7, 1, 3, 9, 1, 5, 1, 1, 7, 1, 21, 6, 1, 4, 1, 1, 1, 1, 1, 3, 1, 3, 3, 1, 4, 9, 1, 1, 7, 2, 3, 1, 3, 1, 2, 11, 3, 1, 2, 4, 1, 1, 9, 1, 4, 7, 2, 22, 15, 1, 6, 2, 3, 1, 2, 3, 9, 1, 1, 1, 7, 2, 22, 9, 4, 1, 1, 1, 1, 4, 1, 1, 3, 1, 5, 9, 1, 12, 2, 44, 6, 2, 4, 1, 4, 4, 9, 5, 1, 1, 17, 23, 8, 1, 6, 1, 5, 9, 9, 1, 49, 8, 7, 7, 9, 1, 6, 23, 13, 12, 4, 7, 9, 3, 1, 1, 9, 5, 9, 35, 15, 4, 17, 35, 1, 50, 7, 7, 9, 18, 33, 11, 1, 1, 14, 37, 1, 1, 42, 1, 202, 3, 6, 5, 40, 3, 32, 3, 6, 5, 14, 56, 3, 66, 2, 8, 15, 85, 5, 201, 16, 25, 74, 10, 12, 6, 20, 19, 12, 2, 1, 55, 16, 12, 1, 1, 1, 9, 2, 9, 36, 52, 42, 1, 69, 30, 11, 3, 8, 39, 4, 43, 25, 11, 28, 54, 1, 1, 6, 1, 1, 1, 25, 1, 9, 9, 1, 13, 1, 5, 48, 1, 6, 1, 6, 8, 9, 8, 3, 31, 9, 60, 1, 6, 1, 4, 55, 9, 48, 8, 42, 2, 2, 14, 12, 7, 3, 3, 121, 128, 206, 5, 37, 5, 7, 36, 52, 6, 1, 2, 6, 3, 5, 12, 2, 6, 1, 1, 1, 1, 1, 1, 12, 12, 1, 11, 1, 1, 9, 1, 1, 4, 11, 11, 3, 4, 1, 40, 46, 46, 132, 8, 37, 1, 1, 55, 1, 1, 22, 6, 6, 6, 6, 6, 6, 6, 6, 31, 1, 1, 1, 14, 4, 4, 1, 85, 97, 4, 42, 93, 31, 15, 203, 210, 22, 200, 45, 207, 27, 47, 1, 9, 1, 113, 8, 79, 24, 5, 47, 8, 3, 3, 8, 4, 5, 28, 1, 51, 69, 9, 23, 5, 45, 35, 28, 4, 48, 12, 1, 9, 6, 1, 23, 54, 4, 9, 1, 9, 17, 5, 1, 1, 1, 1, 51, 1, 15, 1, 1, 3, 12, 3, 1, 3, 1, 5, 5, 5, 6, 6, 42, 14, 118, 3, 1, 1, 1, 9, 208, 22, 48, 209, 105, 6, 4, 1, 1, 9, 12, 4, 3, 1, 107, 205, 63, 53, 11, 15, 15, 1, 2, 4, 134, 9, 25, 27, 11, 77, 5, 5, 5, 2
};

/* Lengths of identifier ranges greater than LEXER IDENT_RANGE_LONG. */
const uint16_t identRangeLongLength[11] = {
    1142, 619, 331, 6591, 217, 362, 282, 269, 11171, 365, 20988
};

/* Identifier starting codepoints for the supplementary plane */
const uint32_t identRangeStartSupplementaryPlane[341] = {
    65536, 65549, 65576, 65596, 65599, 65616, 65664, 65856, 66045, 66176, 66208, 66272, 66304, 66349, 66370, 66384, 66432, 66464, 66504, 66513, 66560, 66720, 66736, 66776, 66816, 66864, 67072, 67392, 67424, 67584, 67592, 67639, 67644, 67647, 67680, 67712, 67808, 67828, 67840, 67872, 67968, 68030, 68096, 68097, 68101, 68108, 68117, 68121, 68152, 68159, 68192, 68224, 68288, 68297, 68352, 68416, 68448, 68480, 68608, 68736, 68800, 68864, 68912, 69248, 69291, 69296, 69376, 69415, 69424, 69552, 69600, 69632, 69633, 69634, 69635, 69734, 69759, 69763, 69840, 69872, 69888, 69933, 69942, 69956, 69957, 69968, 70006, 70016, 70019, 70089, 70094, 70095, 70096, 70144, 70163, 70197, 70198, 70206, 70272, 70280, 70287, 70303, 70320, 70368, 70384, 70400, 70405, 70415, 70419, 70442, 70450, 70453, 70459, 70462, 70465, 70471, 70475, 70480, 70487, 70493, 70502, 70512, 70656, 70726, 70727, 70736, 70750, 70751, 70784, 70842, 70843, 70850, 70855, 70864, 71040, 71096, 71103, 71128, 71168, 71230, 71231, 71236, 71248, 71296, 71340, 71341, 71342, 71351, 71352, 71360, 71424, 71453, 71463, 71472, 71680, 71737, 71840, 71935, 71945, 71948, 71957, 71960, 71991, 71995, 71998, 71999, 72000, 72001, 72002, 72003, 72016, 72096, 72106, 72154, 72161, 72164, 72192, 72193, 72250, 72251, 72263, 72272, 72273, 72344, 72349, 72384, 72704, 72714, 72752, 72760, 72767, 72768, 72784, 72818, 72850, 72873, 72874, 72882, 72885, 72960, 72968, 72971, 73018, 73023, 73031, 73040, 73056, 73063, 73066, 73104, 73107, 73110, 73111, 73112, 73120, 73440, 73648, 73728, 74752, 74880, 77824, 82944, 92160, 92736, 92768, 92880, 92912, 92928, 92992, 93008, 93027, 93053, 93760, 93952, 94031, 94032, 94033, 94095, 94176, 94179, 94180, 94192, 94208, 100352, 101632, 110592, 110928, 110948, 110960, 113664, 113776, 113792, 113808, 113821, 119141, 119149, 119163, 119173, 119210, 119362, 119808, 119894, 119966, 119970, 119973, 119977, 119982, 119995, 120005, 120071, 120077, 120086, 120094, 120123, 120128, 120134, 120138, 120146, 120488, 120514, 120540, 120572, 120598, 120630, 120656, 120688, 120714, 120746, 120772, 120782, 121344, 121403, 121461, 121476, 121499, 121505, 122880, 122888, 122907, 122915, 122918, 123136, 123184, 123200, 123214, 123584, 124928, 125136, 125184, 125264, 126464, 126469, 126497, 126500, 126503, 126516, 126521, 126530, 126535, 126545, 126548, 126551, 126564, 126567, 126572, 126580, 126585, 126590, 126603, 126625, 126629, 126635, 130032, 131072, 173824, 177984, 178208, 183984, 194560, 196608, 917760
};

/* Lengths of identifier ranges for the supplementary plane */
const uint16_t identRangeLengthSupplementaryPlane[341] = {
    11, 25, 18, 1, 14, 13, 122, 52, 1, 28, 48, 1, 31, 20, 8, 41, 29, 35, 7, 4, 156, 9, 35, 35, 39, 51, 310, 21, 7, 5, 44, 1, 1, 22, 22, 30, 18, 1, 21, 25, 55, 1, 1, 2, 1, 6, 2, 28, 2, 1, 28, 28, 7, 28, 53, 21, 18, 17, 72, 50, 50, 38, 9, 41, 1, 1, 28, 1, 31, 20, 22, 1, 1, 1, 66, 9, 3, 51, 24, 9, 42, 7, 9, 1, 2, 35, 1, 2, 61, 3, 1, 1, 11, 17, 30, 1, 1, 1, 6, 4, 14, 9, 47, 9, 9, 2, 7, 1, 21, 6, 1, 4, 2, 2, 3, 1, 2, 1, 1, 5, 6, 4, 65, 1, 3, 9, 1, 2, 55, 1, 5, 2, 1, 9, 51, 5, 1, 4, 58, 1, 1, 1, 9, 43, 1, 1, 7, 1, 1, 9, 26, 7, 4, 9, 54, 1, 72, 7, 1, 7, 1, 28, 1, 2, 1, 1, 1, 1, 1, 1, 9, 7, 43, 5, 2, 1, 1, 54, 1, 3, 1, 1, 66, 1, 1, 56, 8, 37, 6, 6, 1, 1, 9, 29, 21, 1, 7, 2, 1, 6, 1, 42, 2, 7, 1, 9, 5, 1, 35, 1, 2, 1, 1, 1, 9, 20, 1, 921, 110, 195, 1070, 582, 568, 30, 9, 29, 4, 53, 3, 9, 20, 18, 63, 74, 1, 1, 54, 15, 1, 1, 1, 1, 6135, 1237, 8, 286, 2, 3, 395, 106, 12, 8, 9, 1, 3, 5, 7, 6, 3, 2, 84, 70, 1, 1, 1, 3, 11, 7, 64, 3, 7, 6, 27, 3, 4, 1, 6, 339, 24, 24, 30, 24, 30, 24, 30, 24, 30, 24, 7, 49, 54, 49, 1, 1, 4, 14, 6, 16, 6, 1, 4, 44, 12, 9, 1, 55, 196, 6, 74, 9, 3, 26, 1, 1, 10, 3, 2, 1, 5, 1, 1, 6, 1, 3, 6, 3, 3, 10, 16, 2, 4, 16, 9, 42717, 4148, 221, 5761, 7472, 541, 4938, 239
};
const uint16_t basic_plane_length = sizeof(identRangeStart);
const uint16_t supplementary_plane_length = sizeof(identRangeStartSupplementaryPlane);
}
}
