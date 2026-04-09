// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    unit_isdigit_explicit.c
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

typedef struct vlib_isdigit_case
{
    int input;
    int expected;
} vlib_isdigit_case;

int main(void)
{
    static const vlib_isdigit_case cases[] = {
        {'0', 1}, {'1', 1}, {'5', 1}, {'9', 1},
        {'/', 0}, {':', 0},
        {'a', 0}, {'A', 0}, {'z', 0}, {'Z', 0},
        {' ', 0}, {'\t', 0}, {'\n', 0}, {'\0', 0},
        {'!', 0}, {'?', 0}, {'-', 0}, {'_', 0},
        {-1, 0}, {128, 0}, {255, 0}, {256, 0}
    };

    size_t i;

    for (i = 0; i < sizeof(cases) / sizeof(cases[0]); ++i)
    {
        VLIB_TEST_ASSERT_EQ_INT(vlib_isdigit(cases[i].input), cases[i].expected);
    }

    return 0;
}
