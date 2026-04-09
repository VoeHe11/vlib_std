// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    unit_isprint_explicit.c
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

typedef struct vlib_isprint_case
{
    int input;
    int expected;
} vlib_isprint_case;

int main(void)
{
    static const vlib_isprint_case cases[] = {
        /* Untere Grenze und typische druckbare Zeichen */
        {0x20, 1}, /* space */
        {'!', 1},
        {'0', 1},
        {'9', 1},
        {'A', 1},
        {'Z', 1},
        {'a', 1},
        {'z', 1},
        {'~', 1}, /* 0x7e */

        /* Direkt unterhalb/oberhalb des Bereichs */
        {0x1f, 0},
        {0x7f, 0},

        /* Typische Steuerzeichen */
        {'\0', 0},
        {'\t', 0},
        {'\n', 0},
        {'\r', 0},
        {'\v', 0},
        {'\f', 0},

        /* Nicht-ASCII / sonstige int-Werte */
        {-1, 0},
        {0x80, 0},
        {0xff, 0},
        {0x100, 0},
        {1024, 0}
    };

    size_t i;

    for (i = 0; i < sizeof(cases) / sizeof(cases[0]); ++i)
    {
        VLIB_TEST_ASSERT_EQ_INT(vlib_isprint(cases[i].input), cases[i].expected);
    }

    return 0;
}
