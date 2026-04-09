// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    unit_in_range_reference_equivalence.c
// Project: vlib_std
//
// Module:  UNIT TEST
//
// Created:  09.04.2026 – henri
// Modified: 09.04.2026
//
//

#include <limits.h>
#include "../src/internal/vlib_internal.h"

#include "../helpers/test_assert.h"

static int reference_in_range(int c, int low, int high)
{
    return (c >= low && c <= high) ? 1 : 0;
}

int main(void)
{
    static const int test_values[] = {
        INT_MIN, INT_MIN + 1,
        -1000, -100, -10, -1,
        0, 1, 10, 100, 1000,
        INT_MAX - 1, INT_MAX
    };

    static const int range_points[] = {
        INT_MIN, INT_MIN + 1,
        -1000, -100, -10, -1,
        0, 1, 10, 100, 1000,
        INT_MAX - 1, INT_MAX
    };

    size_t i;
    size_t j;
    size_t k;

    for (j = 0; j < sizeof(range_points) / sizeof(range_points[0]); ++j)
    {
        for (k = 0; k < sizeof(range_points) / sizeof(range_points[0]); ++k)
        {
            const int low = range_points[j];
            const int high = range_points[k];

            if (low > high)
            {
                continue;
            }

            for (i = 0; i < sizeof(test_values) / sizeof(test_values[0]); ++i)
            {
                const int c = test_values[i];
                const int expected = reference_in_range(c, low, high);
                const int actual = vlib_in_range(c, low, high);

                VLIB_TEST_ASSERT_EQ_INT(actual, expected);
            }
        }
    }

    return 0;
}
