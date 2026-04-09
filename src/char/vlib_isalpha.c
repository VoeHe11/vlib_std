// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    vlib_isalpha.c
// Project: vlib_std
//
// Module:  ISALPHA IMPLEMENTATION
//
// Created:  08.04.2026 – henri
// Modified: 08.04.2026
//
//

#include <vlib_std.h>
#include <vlib_internal.h>

COMP_CONST int vlib_isalpha(const int c)
{
    unsigned const int x = (unsigned int)c | 0x20u;
    return vlib_in_range((int)x, 'a', 'z');
}