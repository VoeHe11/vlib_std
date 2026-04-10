// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    unit_tolower_lowercase_unchanged.c
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
        VLIB_TEST_ASSERT_EQ_INT(vlib_tolower(c), c);
    }

    return 0;
}
