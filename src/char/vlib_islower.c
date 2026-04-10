// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    vlib_islower.c
// Project: vlib_std
//
// Module:  ISLOWER IMPLEMENTATION
//
// Created:  10.04.2026 – henri
// Modified: 10.04.2026
//
//

#include <vlib_std.h>
#include <vlib_internal.h>

COMP_CONST int  vlib_islower(const int c)
{
    return vlib_in_range(c, 'a', 'z');
}