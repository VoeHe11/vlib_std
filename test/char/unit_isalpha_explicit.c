// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    unit_isalpha_explicit.c
// Project: vlib_std
//
// Module:  UNIT TEST
//
// Created:  08.04.2026 – henri
// Modified: 08.04.2026
//
//

#include <stddef.h>
#include <vlib_std.h>

#include "../helpers/test_assert.h"

typedef struct vlib_isalpha_case
{
    int input;
    int expected;
} vlib_isalpha_case;

int main(void)
{
    static const vlib_isalpha_case cases[] = {
        {'a', 1}, {'b', 1}, {'m', 1}, {'y', 1}, {'z', 1},
        {'A', 1}, {'B', 1}, {'M', 1}, {'Y', 1}, {'Z', 1},

        {'`', 0}, {'{', 0}, {'@', 0}, {'[', 0},

        {'0', 0}, {'1', 0}, {'5', 0}, {'9', 0},

        {' ', 0}, {'\t', 0}, {'\n', 0}, {'\r', 0},
        {'\v', 0}, {'\f', 0}, {'\0', 0},

        {'!', 0}, {'?', 0}, {'.', 0}, {',', 0},
        {';', 0}, {':', 0}, {'-', 0}, {'_', 0},
        {'+', 0}, {'*', 0}, {'/', 0}, {'\\', 0},
        {'(', 0}, {')', 0}, {'#', 0}, {'&', 0},

        {-1, 0}, {128, 0}, {255, 0}, {256, 0}, {1024, 0}
    };

    size_t i;

    for (i = 0; i < sizeof(cases) / sizeof(cases[0]); ++i)
    {
        VLIB_TEST_ASSERT_EQ_INT(vlib_isalpha(cases[i].input), cases[i].expected);
    }

    return 0;
}
