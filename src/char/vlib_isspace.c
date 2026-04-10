// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    vlib_isspace.c
// Project: vlib_std
//
// Module:  ISSPACE IMPLEMENTATION
//
// Created:  10.04.2026 – henri
// Modified: 10.04.2026
//
//
#include <vlib_std.h>
#include <vlib_internal.h>

COMP_CONST int  vlib_isspace(int c)
{
    static const unsigned long long space_bits =
        (1ULL << '\t') | (1ULL << '\n') | (1ULL << '\v') |
        (1ULL << '\f') | (1ULL << '\r') | (1ULL << ' ');

    return (unsigned int)(c) < 64u ? (int)((space_bits >> (unsigned)c) & 1ULL) : 0;
}