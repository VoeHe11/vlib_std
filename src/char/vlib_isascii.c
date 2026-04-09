// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    vlib_isascii.c
// Project: vlib_std
//
// Module:  ISASCII IMPLEMENTATION
//
// Created:  09.04.2026 – henri
// Modified: 09.04.2026
//
//
#include <vlib_std.h>
#include <vlib_internal.h>

COMP_CONST int vlib_isascii(const int c)
{
    return (unsigned int)(c) < 128u;
}