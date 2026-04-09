// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    unit_in_range_mixed_ranges.c
// Project: vlib_std
//
// Module:  UNIT TEST
//
// Created:  09.04.2026 – henri
// Modified: 09.04.2026
//
//

#include "../src/internal/vlib_internal.h"

#include "../helpers/test_assert.h"

int main(void)
{
    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range(-1, -10, 10), 1);
    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range(0, -10, 10), 1);
    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range(1, -10, 10), 1);

    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range(-10, -10, 10), 1);
    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range(10, -10, 10), 1);

    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range(-11, -10, 10), 0);
    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range(11, -10, 10), 0);

    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range(50, -10, 10), 0);
    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range(-50, -10, 10), 0);

    return 0;
}