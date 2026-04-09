// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    unit_in_range_boundaries.c
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
    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range(7, 7, 7), 1);
    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range(6, 7, 7), 0);
    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range(8, 7, 7), 0);

    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range('a', 'a', 'z'), 1);
    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range('z', 'a', 'z'), 1);
    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range('m', 'a', 'z'), 1);
    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range('`', 'a', 'z'), 0);
    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range('{', 'a', 'z'), 0);

    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range('A', 'A', 'Z'), 1);
    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range('Z', 'A', 'Z'), 1);
    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range('@', 'A', 'Z'), 0);
    VLIB_TEST_ASSERT_EQ_INT(vlib_in_range('[', 'A', 'Z'), 0);

    return 0;
}