// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    unit_isspace_whitespace_set.c
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
    VLIB_TEST_ASSERT_EQ_INT(vlib_isspace(' '),  1);
    VLIB_TEST_ASSERT_EQ_INT(vlib_isspace('\t'), 1);
    VLIB_TEST_ASSERT_EQ_INT(vlib_isspace('\n'), 1);
    VLIB_TEST_ASSERT_EQ_INT(vlib_isspace('\v'), 1);
    VLIB_TEST_ASSERT_EQ_INT(vlib_isspace('\f'), 1);
    VLIB_TEST_ASSERT_EQ_INT(vlib_isspace('\r'), 1);

    return 0;
}