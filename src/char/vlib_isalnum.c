// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    vlib_isalnum.c
// Project: vlib_std
//
// Module:  ISALNUM IMPLEMENTATION
//
// Created:  09.04.2026 – henri
// Modified: 09.04.2026
//
//

#include <vlib_std.h>
#include <vlib_internal.h>

COMP_CONST int  vlib_isalnum(const int c)
{
    return vlib_isalpha(c) | vlib_isdigit(c);
}

