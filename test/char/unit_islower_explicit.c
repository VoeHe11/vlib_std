// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    unit_islower_explicit.c
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

typedef struct vlib_islower_case
{
    int input;
    int expected;
} vlib_islower_case;

int main(void)
{
    static const vlib_islower_case cases[] = {
        /* gültige Kleinbuchstaben */
        { 'a', 1 }, { 'b', 1 }, { 'm', 1 }, { 'y', 1 }, { 'z', 1 },

        /* direkt vor/nach dem Bereich */
        { '`', 0 }, /* vor 'a' */
        { '{', 0 }, /* nach 'z' */

        /* Großbuchstaben */
        { 'A', 0 }, { 'M', 0 }, { 'Z', 0 },

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
        { -1, 0 },
        { 128, 0 },
        { 255, 0 },
        {256, 0},
        {1024, 0}
    };

    size_t i;

    for (i = 0; i < sizeof(cases) / sizeof(cases[0]); ++i)
    {
        VLIB_TEST_ASSERT_EQ_INT(vlib_islower(cases[i].input), cases[i].expected);
    }

    return 0;
}
