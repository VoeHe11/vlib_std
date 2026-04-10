// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    unit_isupper_non_alpha_rejected.c
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
        if (c >= 'A' && c <= 'Z')
        {
            continue;
        }

        VLIB_TEST_ASSERT_EQ_INT(vlib_isupper(c), 0);
    }

    return 0;
}
