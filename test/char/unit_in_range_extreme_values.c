// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    unit_in_range_extreme_values.c
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

int main(void)
{
    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range(INT_MIN, INT_MIN, INT_MAX), 1);
    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range(0,       INT_MIN, INT_MAX), 1);
    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range(INT_MAX, INT_MIN, INT_MAX), 1);

    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range(INT_MIN, INT_MIN, INT_MIN), 1);
    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range(INT_MAX, INT_MAX, INT_MAX), 1);

    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range(INT_MIN + 1, INT_MIN, INT_MIN), 0);
    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range(INT_MAX - 1, INT_MAX, INT_MAX), 0);

    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range(INT_MIN, INT_MIN, -1), 1);
    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range(-1,      INT_MIN, -1), 1);
    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range(0,       INT_MIN, -1), 0);

    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range(0, 0, INT_MAX), 1);
    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range(INT_MAX, 0, INT_MAX), 1);
    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range(-1, 0, INT_MAX), 0);

    return 0;
}