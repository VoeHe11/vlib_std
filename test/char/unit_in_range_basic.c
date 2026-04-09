// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    unit_in_range_basic.c
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
    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range(5, 0, 10), 1);
    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range(0, 0, 10), 1);
    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range(10, 0, 10), 1);

    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range(-1, 0, 10), 0);
    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range(11, 0, 10), 0);

    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range(100, 50, 150), 1);
    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range(49, 50, 150), 0);
    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range(151, 50, 150), 0);

    return 0;
}