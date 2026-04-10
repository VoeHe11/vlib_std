// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    unit_isspace_reference_equivalence.c
// Project: vlib_std
//
// Module:  UNIT TEST
//
// Created:  10.04.2026 – henri
// Modified: 10.04.2026
//
//

#include <limits.h>
#include <vlib_std.h>

#include "../helpers/test_assert.h"

static int reference_isspace(int c)
{
    switch (c)
    {
        case ' ':
        case '\t':
        case '\n':
        case '\v':
        case '\f':
        case '\r':
            return 1;
        default:
            return 0;
    }
}

int main(void)
{
    static const int values[] = {
        INT_MIN, INT_MIN + 1,
        -1024, -256, -128, -64, -32, -13, -12, -11, -10, -9, -8, -1,
        0, 1, 8, 9, 10, 11, 12, 13,
        31, 32, 33, 47, 48, 57,
        63, 64, 65,
        'A', 'Z', 'a', 'z',
        127, 128, 255, 256, 1024,
        INT_MAX - 1, INT_MAX
    };

    size_t i;

    for (i = 0; i < sizeof(values) / sizeof(values[0]); ++i)
    {
        const int c = values[i];
        const int expected = reference_isspace(c);

        VLIB_TEST_ASSERT_EQ_INT(vlib_isspace(c), expected);
    }

    return 0;
}
