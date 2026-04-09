
# Tests for isalpha
vlib_add_unit_test(
        unit_isalpha_explicit
        unit.isalpha.explicit
        ${CMAKE_CURRENT_SOURCE_DIR}/unit_isalpha_explicit.c
)

vlib_add_unit_test(
        unit_isalpha_lowercase_range
        unit.isalpha.lowercase_range
        ${CMAKE_CURRENT_SOURCE_DIR}/unit_isalpha_lowercase_range.c
)

vlib_add_unit_test(
        unit_isalpha_uppercase_range
        unit.isalpha.uppercase_range
        ${CMAKE_CURRENT_SOURCE_DIR}/unit_isalpha_uppercase_range.c
)

vlib_add_unit_test(
        unit_isalpha_digits_rejected
        unit.isalpha.digits_rejected
        ${CMAKE_CURRENT_SOURCE_DIR}/unit_isalpha_digits_rejected.c
)

vlib_add_unit_test(
        unit_isalpha_ascii_classification
        unit.isalpha.ascii_classification
        ${CMAKE_CURRENT_SOURCE_DIR}/unit_isalpha_ascii_classification.c
)

vlib_add_unit_test(
        unit_isalpha_case_normalization
        unit.isalpha.case_normalization
        ${CMAKE_CURRENT_SOURCE_DIR}/unit_isalpha_case_normalization.c
)