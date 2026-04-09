// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    unit_isascii_explicit.c
// Project: vlib_std
//
// Module:  UNIT TEST
//
// Created:  09.04.2026 – henri
// Modified: 09.04.2026
//
//

#include <stddef.h>
#include <vlib_std.h>

#include "../helpers/test_assert.h"

typedef struct vlib_isascii_case
{
    int input;
    int expected;
} vlib_isascii_case;

int main(void)
{
    static const vlib_isascii_case cases[] = {
        /* Untere ASCII-Grenze */
        {0, 1},
        {1, 1},
        {2, 1},

        /* Typische ASCII-Zeichen */
        {'A', 1},
        {'Z', 1},
        {'a', 1},
        {'z', 1},
        {'0', 1},
        {'9', 1},
        {' ', 1},
        {'\t', 1},
        {'\n', 1},
        {'\r', 1},
        {'\0', 1},

        /* Obere ASCII-Grenze */
        {126, 1},
        {127, 1},

        /* Direkt außerhalb */
        {-1, 0},
        {128, 0},
        {129, 0},

        /* Größere Werte */
        {255, 0},
        {256, 0},
        {1024, 0}
    };

    size_t i;

    for (i = 0; i < sizeof(cases) / sizeof(cases[0]); ++i)
    {
        VLIB_TEST_ASSERT_EQ_INT(vlib_isascii(cases[i].input), cases[i].expected);
    }

    return 0;
}
