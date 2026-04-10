// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    unit_isupper_reference_equivalence.c
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

static int reference_isupper(int c)
{
    return (c >= 'A' && c <= 'Z') ? 1 : 0;
}

int main(void)
{
    static const int values[] = {
        INT_MIN, INT_MIN + 1,
        -1024, -255, -128, -1,
        0, 1, 31, 32, 47,
        '0', '9',
        '@', 'A', 'M', 'Z', '[',
        'a', 'm', 'z',
        127, 128, 255, 256, 1024,
        INT_MAX - 1, INT_MAX
    };

    size_t i;

    for (i = 0; i < sizeof(values) / sizeof(values[0]); ++i)
    {
        const int c = values[i];
        const int expected = reference_isupper(c);

        VLIB_TEST_ASSERT_EQ_INT(vlib_isupper(c), expected);
    }

    return 0;
}
