// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    unit_tolower_idempotence.c
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

int main(void)
{
    static const int values[] = {
        INT_MIN, INT_MIN + 1,
        -1024, -255, -128, -1,
        0, 1, 31, 32, 47,
        '0', '9',
        '@', 'A', 'M', 'Z', '[',
        '`', 'a', 'm', 'z', '{',
        127, 128, 255, 256, 1024,
        INT_MAX - 1, INT_MAX
    };

    size_t i;

    for (i = 0; i < sizeof(values) / sizeof(values[0]); ++i)
    {
        const int c = values[i];
        const int once = vlib_tolower(c);
        const int twice = vlib_tolower(once);

        VLIB_TEST_ASSERT_EQ_INT(twice, once);
    }

    return 0;
}
