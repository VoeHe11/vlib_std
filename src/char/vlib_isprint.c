// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    vlib_isprint.c
// Project: vlib_std
//
// Module:  ISPRINT IMPLEMENTATION
//
// Created:  09.04.2026 – henri
// Modified: 09.04.2026
//
//
#include <vlib_std.h>
#include <vlib_internal.h>

COMP_CONST int  vlib_isprint(const int c)
{
    return vlib_in_range(c, 0x20, 0x7e);
}