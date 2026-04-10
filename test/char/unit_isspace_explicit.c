// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    unit_isspace_explicit.c
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

typedef struct vlib_isspace_case
{
    int input;
    int expected;
} vlib_isspace_case;

int main(void)
{
    static const vlib_isspace_case cases[] = {
        /* exakt erlaubte Whitespaces */
        { ' ',  1 },
        { '\t', 1 },
        { '\n', 1 },
        { '\v', 1 },
        { '\f', 1 },
        { '\r', 1 },

        /* typische Nicht-Whitespace-Zeichen */
        { '\0', 0 },
        { 'a',  0 },
        { 'A',  0 },
        { '0',  0 },
        { '!',  0 },
        { '_',  0 },

        /* Grenzfälle um den 64er Cutoff */
        { 63, 0 },
        { 64, 0 },
        { 65, 0 },

        /* negative / große Werte */
        { -1,   0 },
        { -128, 0 },
        {127, 0},
        {255, 0},
        {256, 0},
        {1024, 0}
    };

    size_t i;

    for (i = 0; i < sizeof(cases) / sizeof(cases[0]); ++i)
    {
        VLIB_TEST_ASSERT_EQ_INT(vlib_isspace(cases[i].input), cases[i].expected);
    }

    return 0;
}