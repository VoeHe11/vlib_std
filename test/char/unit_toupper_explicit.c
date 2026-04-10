// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    unit_toupper_explicit.c
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

typedef struct vlib_toupper_case
{
    int input;
    int expected;
} vlib_toupper_case;

int main(void)
{
    static const vlib_toupper_case cases[] = {
        /* Kleinbuchstaben -> Großbuchstaben */
        {'a', 'A'},
        {'b', 'B'},
        {'m', 'M'},
        {'y', 'Y'},
        {'z', 'Z'},

        /* Großbuchstaben bleiben unverändert */
        {'A', 'A'},
        {'B', 'B'},
        {'M', 'M'},
        {'Y', 'Y'},
        {'Z', 'Z'},

        /* Direkt vor/nach dem Kleinbuchstabenbereich */
        {'`', '`'},
        {'{', '{'},

        /* Ziffern */
        {'0', '0'},
        {'5', '5'},
        {'9', '9'},

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
        VLIB_TEST_ASSERT_EQ_INT(vlib_toupper(cases[i].input), cases[i].expected);
    }

    return 0;
}
