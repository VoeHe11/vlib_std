// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    vlib_isdigit.c
// Project: vlib_std
//
// Module:  ISDIGIT IMPLEMENTATION
//
// Created:  09.04.2026 – henri
// Modified: 09.04.2026
//
//

#include <vlib_std.h>
#include <vlib_internal.h>

COMP_CONST int  vlib_isdigit(const int c)
{
    return vlib_in_range(c, '0', '9');
}