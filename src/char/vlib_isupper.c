// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    vlib_isupper.c
// Project: vlib_std
//
// Module:  ISUPPER IMPLEMENTATION
//
// Created:  10.04.2026 – henri
// Modified: 10.04.2026
//
//
#include <vlib_std.h>
#include <vlib_internal.h>

COMP_CONST int vlib_isupper(const int c)
{
    return vlib_in_range(c, 'A', 'Z');
}
