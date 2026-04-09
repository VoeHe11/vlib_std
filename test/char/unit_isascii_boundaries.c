// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    unit_isascii_boundaries.c
// Project: vlib_std
//
// Module:  UNIT TEST
//
// Created:  09.04.2026 – henri
// Modified: 09.04.2026
//
//

#include <vlib_std.h>

#include "../helpers/test_assert.h"

int main(void)
{
    VLIB_TEST_ASSERT_EQ_INT(vlib_isascii(-1), 0);
    VLIB_TEST_ASSERT_EQ_INT(vlib_isascii(0), 1);
    VLIB_TEST_ASSERT_EQ_INT(vlib_isascii(1), 1);

    VLIB_TEST_ASSERT_EQ_INT(vlib_isascii(126), 1);
    VLIB_TEST_ASSERT_EQ_INT(vlib_isascii(127), 1);
    VLIB_TEST_ASSERT_EQ_INT(vlib_isascii(128), 0);
    VLIB_TEST_ASSERT_EQ_INT(vlib_isascii(129), 0);

    return 0;
}
