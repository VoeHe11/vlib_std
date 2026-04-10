// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    unit_toupper_lowercase_mapping.c
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

int main(void)
{
    int c;

    for (c = 'a'; c <= 'z'; ++c)
    {
        VLIB_TEST_ASSERT_EQ_INT(vlib_toupper(c), c - ('a' - 'A'));
    }

    return 0;
}
