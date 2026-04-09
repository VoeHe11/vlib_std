// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    unit_isascii_above_ascii_rejected.c
// Project: vlib_std
//
// Module:  UNIT TEST
//
// Created:  09.04.2026 – henri
// Modified: 09.04.2026
//
//

#include <limits.h>
#include <vlib_std.h>

#include "../helpers/test_assert.h"

int main(void)
{
    static const int values[] = {
        128, 129, 130,
        255, 256, 257,
        1024, 4096,
        INT_MAX - 1, INT_MAX
    };

    size_t i;

    for (i = 0; i < sizeof(values) / sizeof(values[0]); ++i)
    {
        VLIB_TEST_ASSERT_EQ_INT(vlib_isascii(values[i]), 0);
    }

    return 0;
}
