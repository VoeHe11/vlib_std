// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    unit_isalpha_uppercase_range.c
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

    for (c = 'A'; c <= 'Z'; ++c)
    {
        VLIB_TEST_ASSERT_EQ_INT(vlib_isalpha(c), 1);
    }

    return 0;
}
