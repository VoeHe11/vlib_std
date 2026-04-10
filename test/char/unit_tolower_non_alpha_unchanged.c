// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    unit_tolower_non_alpha_unchanged.c
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
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            continue;
        }

        VLIB_TEST_ASSERT_EQ_INT(vlib_tolower(c), c);
    }

    return 0;
}
