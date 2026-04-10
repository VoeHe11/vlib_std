// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    vlib_tolower.c
// Project: vlib_std
//
// Module:  TOLOWER IMPLEMENTATION
//
// Created:  10.04.2026 – henri
// Modified: 10.04.2026
//
//

#include <vlib_std.h>
#include <vlib_internal.h>

COMP_CONST int  vlib_tolower(const int c)
{
    const int mask = -(int)vlib_isupper(c);
    return c ^ (mask & 0x20);
}