// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    unit_isdigit_digit_range.c
// Project: vlib_std
//
// Module:  UNIT TEST
//
// Created:  09.04.2026 – henri
// Modified: 09.04.2026
//
//

#include <vlib_std.h>

#include "../helpers/test_assert.h"

int main(void)
{
    int c;

    for (c = '0'; c <= '9'; ++c)
    {
        VLIB_TEST_ASSERT_EQ_INT(vlib_isdigit(c), 1);
    }

    return 0;
}
