// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    unit_in_range_negative.c
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
    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range(-10, -20, -5), 1);
    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range(-20, -20, -5), 1);
    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range(-5, -20, -5), 1);

    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range(-21, -20, -5), 0);
    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range(-4, -20, -5), 0);

    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range(-100, -100, -100), 1);
    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range(-101, -100, -100), 0);
    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range(-99, -100, -100), 0);

    return 0;
}