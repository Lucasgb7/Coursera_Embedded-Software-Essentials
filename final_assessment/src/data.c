/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file data.c
 * @brief Data source file
 *
 * @author Lucas Cunha
 * @date July 26 2023
 *
 */
#include <stdint.h>
#include "data.h"

uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base) {
    // Handle the special case of data = 0
    if (data == 0) {
        *ptr = '0';
        *(ptr + 1) = '\0';
        return 2;
    }
    uint8_t is_negative = 0;
    uint32_t value;
    uint8_t length = 0;
    uint8_t temp;
    int8_t remainder;
    // Check for negative number and make it positive for conversion
    if (data < 0) {
        is_negative = 1;
        value = -data;
    } else {
        value = data;
    }
    // Convert the number to the specified base
    while (value != 0) {
        remainder = value % base;
        *(ptr + length) = (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'A');
        value /= base;
        length++;
    }
    // Add negative sign for negative numbers
    if (is_negative) {
        *(ptr + length) = '-';
        length++;
    }
    // Add null terminator to the end of the string
    *(ptr + length) = '\0';
    // Reverse the string in-place using pointer arithmetic
    uint8_t *start = ptr;
    uint8_t *end = ptr + length - 1;
    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
    return length; // Return the length of the converted data
}

int32_t my_atoi(uint8_t *ptr, uint8_t digits, uint32_t base) {
    int32_t result = 0;
    int8_t is_negative = 0;
    uint8_t i = 0;
    // Handle the sign if the first character is '-'
    if (*ptr == '-') {
        is_negative = 1;
        i = 1;
    }
    // Convert the ASCII string to the specified base and calculate the integer result
    while (i < digits) {
        uint8_t current_digit = *(ptr + i);
        if (current_digit >= '0' && current_digit <= '9') {
            current_digit -= '0';
        } else if (current_digit >= 'A' && current_digit <= 'F') {
            current_digit = 10 + (current_digit - 'A');
        } else if (current_digit >= 'a' && current_digit <= 'f') {
            current_digit = 10 + (current_digit - 'a');
        } else {
            // Invalid character encountered, return 0
            return 0;
        }
        // Check if the digit is valid for the specified base
        if (current_digit >= base) {
            // Invalid digit for the specified base, return 0
            return 0;
        }
        result = result * base + current_digit;
        i++;
    }
    // Apply the sign to the result if the number is negative
    if (is_negative) {
        result = -result;
    }
    return result;
}