// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    unit_isprint_reference_equivalence.c
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

static int reference_isprint(int c)
{
    return (c >= 0x20 && c <= 0x7e) ? 1 : 0;
}

int main(void)
{
    static const int values[] = {
        INT_MIN, INT_MIN + 1,
        -1024, -255, -128, -1,
        0x00, 0x01, 0x09, 0x0a, 0x1f,
        0x20, 0x21, 0x30, 0x39, 0x41, 0x5a, 0x61, 0x7a, 0x7e,
        0x7f, 0x80, 0xff, 0x100, 1024,
        INT_MAX - 1, INT_MAX
    };

    size_t i;

    for (i = 0; i < sizeof(values) / sizeof(values[0]); ++i)
    {
        const int c = values[i];
        const int expected = reference_isprint(c);

        VLIB_TEST_ASSERT_EQ_INT(vlib_isprint(c), expected);
    }

    return 0;
}
