// SPDX-License-Identifier: MIT
// Copyright (c) 2026

//
// File:    test_assert.h
// Project: vlib_std
//
// Module:  Test Assert
//
// Created:  08.04.2026 – henri
// Modified: 08.04.2026
//
//
#ifndef VLIB_STD_TEST_ASSERT_H
#define VLIB_STD_TEST_ASSERT_H

#include <stddef.h>

void vlib_test_fail_int(const char *expr,
                        const char *file,
                        int line,
                        int actual,
                        int expected);

void vlib_test_fail_size(const char *expr,
                         const char *file,
                         int line,
                         size_t actual,
                         size_t expected);

#define VLIB_TEST_ASSERT_EQ_INT(actual_expr, expected_value)                    \
    do {                                                                       \
        const int vlib_test_actual_ = (actual_expr);                           \
        const int vlib_test_expected_ = (expected_value);                      \
        if (vlib_test_actual_ != vlib_test_expected_) {                        \
            vlib_test_fail_int(#actual_expr, __FILE__, __LINE__,               \
                               vlib_test_actual_, vlib_test_expected_);        \
        }                                                                      \
    } while (0)

#define VLIB_TEST_ASSERT_EQ_SIZE(actual_expr, expected_value)                   \
    do {                                                                       \
        const size_t vlib_test_actual_ = (actual_expr);                        \
        const size_t vlib_test_expected_ = (expected_value);                   \
        if (vlib_test_actual_ != vlib_test_expected_) {                        \
            vlib_test_fail_size(#actual_expr, __FILE__, __LINE__,              \
                                vlib_test_actual_, vlib_test_expected_);       \
        }                                                                      \
    } while (0)

#define VLIB_TEST_ASSERT_TRUE(expr)                                            \
    VLIB_TEST_ASSERT_EQ_INT(((expr) ? 1 : 0), 1)

#define VLIB_TEST_ASSERT_FALSE(expr)                                           \
    VLIB_TEST_ASSERT_EQ_INT(((expr) ? 1 : 0), 0)

#endif /* VLIB_STD_TEST_ASSERT_H */