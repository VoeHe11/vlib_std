// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    unit_tolower_boundaries.c
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
    VLIB_TEST_ASSERT_EQ_INT(vlib_tolower('A'), 'a');
    VLIB_TEST_ASSERT_EQ_INT(vlib_tolower('Z'), 'z');

    VLIB_TEST_ASSERT_EQ_INT(vlib_tolower('@'), '@');
    VLIB_TEST_ASSERT_EQ_INT(vlib_tolower('['), '[');

    VLIB_TEST_ASSERT_EQ_INT(vlib_tolower('a'), 'a');
    VLIB_TEST_ASSERT_EQ_INT(vlib_tolower('z'), 'z');

    VLIB_TEST_ASSERT_EQ_INT(vlib_tolower('`'), '`');
    VLIB_TEST_ASSERT_EQ_INT(vlib_tolower('{'), '{');

    return 0;
}
