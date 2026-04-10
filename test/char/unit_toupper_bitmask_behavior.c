// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    unit_toupper_bitmask_behavior.c
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
        VLIB_TEST_ASSERT_EQ_INT(vlib_toupper(c), (c ^ 0x20));
    }

    for (c = 0; c <= 127; ++c)
    {
        if (c >= 'a' && c <= 'z')
        {
            continue;
        }

        VLIB_TEST_ASSERT_EQ_INT(vlib_toupper(c), c);
    }

    return 0;
}
