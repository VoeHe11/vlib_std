// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    unit_tolower_explicit.c
// Project: vlib_std
//
// Module:  UNIT TEST
//
// Created:  10.04.2026 – henri
// Modified: 10.04.2026
//
//

#include <stddef.h>
#include <vlib_std.h>

#include "../helpers/test_assert.h"

typedef struct vlib_tolower_case
{
    int input;
    int expected;
} vlib_tolower_case;

int main(void)
{
    static const vlib_tolower_case cases[] = {
        /* Großbuchstaben -> Kleinbuchstaben */
        { 'A', 'a' },
        { 'B', 'b' },
        { 'M', 'm' },
        { 'Y', 'y' },
        { 'Z', 'z' },

        /* Kleinbuchstaben bleiben unverändert */
        { 'a', 'a' },
        { 'b', 'b' },
        { 'm', 'm' },
        { 'y', 'y' },
        { 'z', 'z' },

        /* Direkt vor/nach dem Großbuchstabenbereich */
        { '@', '@' },
        { '[', '[' },

        /* Ziffern */
        { '0', '0' },
        { '5', '5' },
        { '9', '9' },

        /* Leerraum / Steuerzeichen */
        {' ', ' '},
        {'\t', '\t'},
        {'\n', '\n'},
        {'\r', '\r'},
        {'\0', '\0'},

        /* Satzzeichen */
        {'!', '!'},
        {'?', '?'},
        {'-', '-'},
        {'_', '_'},

        /* sonstige Werte */
        {-1, -1},
        {128, 128},
        {255, 255},
        {256, 256},
        {1024, 1024}
    };

    size_t i;

    for (i = 0; i < sizeof(cases) / sizeof(cases[0]); ++i)
    {
        VLIB_TEST_ASSERT_EQ_INT(vlib_tolower(cases[i].input), cases[i].expected);
    }

    return 0;
}
