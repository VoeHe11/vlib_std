// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    unit_toupper_reference_equivalence.c
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

static int reference_toupper(int c)
{
    if (c >= 'a' && c <= 'z')
    {
        return c - ('a' - 'A');
    }

    return c;
}

int main(void)
{
    static const int values[] = {
        INT_MIN, INT_MIN + 1,
        -1024, -255, -128, -1,
        0, 1, 8, 9, 10, 11, 12, 13,
        31, 32, 33, 47, 48, 57,
        '@', 'A', 'M', 'Z', '[',
        '`', 'a', 'm', 'z', '{',
        127, 128, 255, 256, 1024,
        INT_MAX - 1, INT_MAX
    };

    size_t i;

    for (i = 0; i < sizeof(values) / sizeof(values[0]); ++i)
    {
        const int c = values[i];
        const int expected = reference_toupper(c);

        VLIB_TEST_ASSERT_EQ_INT(vlib_toupper(c), expected);
    }

    return 0;
}
