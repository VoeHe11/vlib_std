// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    unit_isprint_del_rejected.c
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
    VLIB_TEST_ASSERT_EQ_INT(vlib_isprint(0x7f), 0);
    return 0;
}
