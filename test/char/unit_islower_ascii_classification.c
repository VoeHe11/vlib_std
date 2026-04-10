// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    unit_islower_ascii_classification.c
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

    for (c = 0; c <= 127; ++c)
    {
        const int expected = (c >= 'a' && c <= 'z') ? 1 : 0;

        VLIB_TEST_ASSERT_EQ_INT(vlib_islower(c), expected);
    }

    return 0;
}
