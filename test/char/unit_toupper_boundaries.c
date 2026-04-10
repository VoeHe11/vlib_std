// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    unit_toupper_boundaries.c
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
    VLIB_TEST_ASSERT_EQ_INT(vlib_toupper('a'), 'A');
    VLIB_TEST_ASSERT_EQ_INT(vlib_toupper('z'), 'Z');

    VLIB_TEST_ASSERT_EQ_INT(vlib_toupper('`'), '`');
    VLIB_TEST_ASSERT_EQ_INT(vlib_toupper('{'), '{');

    VLIB_TEST_ASSERT_EQ_INT(vlib_toupper('A'), 'A');
    VLIB_TEST_ASSERT_EQ_INT(vlib_toupper('Z'), 'Z');

    VLIB_TEST_ASSERT_EQ_INT(vlib_toupper('@'), '@');
    VLIB_TEST_ASSERT_EQ_INT(vlib_toupper('['), '[');

    return 0;
}
