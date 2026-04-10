// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    unit_isspace_non_whitespace_below_64.c
// Project: vlib_std
//
// Module:  UNIT TEST
//
// Created:  10.04.2026 – henri
// Modified: 10.04.2026
//
//

#include <vlib_std.h>

#include "../helpers/test_assert.h"

static int reference_isspace_below_64(int c)
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
    int c;

    for (c = 0; c < 64; ++c)
    {
        const int expected = reference_isspace_below_64(c);
        VLIB_TEST_ASSERT_EQ_INT(vlib_isspace(c), expected);
    }

    return 0;
}
