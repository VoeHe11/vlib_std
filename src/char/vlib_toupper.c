// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    vlib_toupper.c
// Project: vlib_std
//
// Module:  TOUPPER IMPLEMENTATION
//
// Created:  10.04.2026 – henri
// Modified: 10.04.2026
//
//

#include <vlib_std.h>
#include <vlib_internal.h>

COMP_CONST int  vlib_toupper(const int c)
{
    // 0x00 or 0xFF…FF
    const int mask = -(int)vlib_islower(c);
    return c ^ (mask & 0x20);
}