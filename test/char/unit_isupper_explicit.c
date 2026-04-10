// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    unit_isupper_explicit.c
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

typedef struct vlib_isupper_case
{
    int input;
    int expected;
} vlib_isupper_case;

int main(void)
{
    static const vlib_isupper_case cases[] = {
        /* gültige Großbuchstaben */
        { 'A', 1 }, { 'B', 1 }, { 'M', 1 }, { 'Y', 1 }, { 'Z', 1 },

        /* direkt vor/nach dem Bereich */
        { '@', 0 }, /* vor 'A' */
        { '[', 0 }, /* nach 'Z' */

        /* Kleinbuchstaben */
        { 'a', 0 }, { 'm', 0 }, { 'z', 0 },

        /* Ziffern */
        { '0', 0 }, { '5', 0 }, { '9', 0 },

        /* Leerraum / Steuerzeichen */
        { ' ', 0 },
        { '\t', 0 },
        { '\n', 0 },
        { '\r', 0 },
        { '\0', 0 },

        /* Satzzeichen */
        { '!', 0 },
        { '?', 0 },
        { '-', 0 },
        { '_', 0 },

        /* sonstige Werte */
        {-1, 0},
        {128, 0},
        {255, 0},
        {256, 0},
        {1024, 0}
    };

    size_t i;

    for (i = 0; i < sizeof(cases) / sizeof(cases[0]); ++i)
    {
        VLIB_TEST_ASSERT_EQ_INT(vlib_isupper(cases[i].input), cases[i].expected);
    }

    return 0;
}
