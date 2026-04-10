// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    unit_isspace_above_63_rejected.c
// Project: vlib_std
//
// Module:  UNIT TEST
//
// Created:  10.04.2026 – henri
// Modified: 10.04.2026
//
//

#include <limits.h>
#include <vlib_std.h>

#include "../helpers/test_assert.h"

int main(void)
{
    static const int values[] = {
        64, 65, 66,
        'A', 'Z', 'a', 'z',
        127, 128, 255, 256, 1024,
        INT_MAX - 1, INT_MAX
    };

    size_t i;

    for (i = 0; i < sizeof(values) / sizeof(values[0]); ++i)
    {
        VLIB_TEST_ASSERT_EQ_INT(vlib_isspace(values[i]), 0);
    }

    return 0;
}
