// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    vlib_std.h
// Project: vlib_std
//
// Module:  GLOBAL HEADER
//
// Created:  08.04.2026 – henri
// Modified: 08.04.2026
//
//
#ifndef VLIB_STD_VLIB_STD_H
#define VLIB_STD_VLIB_STD_H

#ifdef __cplusplus
extern "C"
{
#endif

// ── Character ───────────────────────────────────────────
int     vlib_isalpha(int c)   __attribute__((const));
int     vlib_isdigit(int c)   __attribute__((const));
int     vlib_isalnum(int c)   __attribute__((const));
int     vlib_isascii(int c)   __attribute__((const));
int     vlib_isprint(int c)   __attribute__((const));
int     vlib_isspace(int c)   __attribute__((const));
int     vlib_isupper(int c)   __attribute__((const));

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* VLIB_STD_VLIB_STD_H */