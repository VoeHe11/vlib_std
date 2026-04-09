// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    vlib_internal.h
// Project: vlib_std
//
// Module:  INTERNAL HEADER
//
// Created:  08.04.2026 – henri
// Modified: 08.04.2026
//
//
#ifndef VLIB_STD_VLIB_INTERNAL_H
#define VLIB_STD_VLIB_INTERNAL_H

// ── Compiler ───────────────────────────────────────────
#define COMP_INLINE     static inline __attribute__((always_inline))
#define COMP_CONST      __attribute__((const))

// ── Helpers ───────────────────────────────────────────
COMP_INLINE int vlib_in_range(int c, int low, int high)
{
    return (unsigned int)((unsigned int)(c) - (unsigned int)(low)) <=
           (unsigned int)((unsigned int)(high) - (unsigned int)(low));
}

#endif /* VLIB_STD_VLIB_INTERNAL_H */