// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    unit_isascii_reference_equivalence.c
// Project: vlib_std
//
// Module:  UNIT TEST
//
// Created:  09.04.2026 – henri
// Modified: 09.04.2026
//
//

#include <limits.h>
#include <vlib_std.h>

#include "../helpers/test_assert.h"

static int reference_isascii(int c)
{
    return (c >= 0 && c <= 127) ? 1 : 0;
}

int main(void)
{
    static const int values[] = {
        INT_MIN, INT_MIN + 1,
        -4096, -1024, -256, -255, -129, -128, -127, -1,
        0, 1, 2, 9, 10, 31, 32, 64, 65, 90, 97, 122, 126, 127,
        128, 129, 255, 256, 1024, 4096,
        INT_MAX - 1, INT_MAX
    };

    size_t i;

    for (i = 0; i < sizeof(values) / sizeof(values[0]); ++i)
    {
        const int c = values[i];
        const int expected = reference_isascii(c);

        VLIB_TEST_ASSERT_EQ_INT(vlib_isascii(c), expected);
    }

    return 0;
}
