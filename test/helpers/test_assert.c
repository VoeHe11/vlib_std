// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    test_assert.c
// Project: vlib_std
//
// Module:  Test Assert
//
// Created:  08.04.2026 – henri
// Modified: 08.04.2026
//
//
#include "test_assert.h"

#include <stdio.h>
#include <stdlib.h>

void vlib_test_fail_int(const char *expr,
                        const char *file,
                        int line,
                        int actual,
                        int expected)
{
    fprintf(stderr,
            "TEST FAILURE\n"
            "  file:     %s\n"
            "  line:     %d\n"
            "  expr:     %s\n"
            "  expected: %d\n"
            "  actual:   %d\n",
            file,
            line,
            expr,
            expected,
            actual);

    abort();
}

void vlib_test_fail_size(const char *expr,
                         const char *file,
                         int line,
                         size_t actual,
                         size_t expected)
{
    fprintf(stderr,
            "TEST FAILURE\n"
            "  file:     %s\n"
            "  line:     %d\n"
            "  expr:     %s\n"
            "  expected: %zu\n"
            "  actual:   %zu\n",
            file,
            line,
            expr,
            expected,
            actual);

    abort();
}