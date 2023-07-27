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
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 * 
 * @author Lucas Cunha
 * @date July 25 2023
 */
#include <stdlib.h>
#include <stdint.h>
#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}


/***********************************************************
 Memory manipulation functions
***********************************************************/

uint8_t * my_memmove(uint8_t *src, uint8_t *dst, size_t length) {
    // Check if source and destination regions overlap
    if (src < dst && src + length > dst) {
        // Overlapping, copy from end to start to avoid data corruption
        src += length;
        dst += length;

        while (length--) {
            *(--dst) = *(--src);
        }
    } else {
        // Non-overlapping, copy from start to end
        while (length--) {
            *dst++ = *src++;
        }
    }
    return dst; // Return the pointer to the destination (dst)
}

uint8_t *my_memcopy(uint8_t *src, uint8_t *dst, size_t length) {
   // Perform the copy using pointer arithmetic
    while (length--) {
        *dst++ = *src++;
    }
    return dst; // Return the pointer to the destination (dst)
}

uint8_t *my_memset(uint8_t *src, size_t length, uint8_t value) {
    // Perform the memset using pointer arithmetic
    while (length--) {
        *src++ = value;
    }
    return src; // Return the pointer to the source (src)
}

uint8_t *my_memzero(uint8_t *src, size_t length) {
    // Perform the memzero using pointer arithmetic
    while (length--) {
        *src++ = 0;
    }
    return src; // Return the pointer to the source (src)
}

uint8_t *my_reverse(uint8_t *src, size_t length) {
    uint8_t *start = src;
    uint8_t *end = src + length - 1;
    // Perform the reverse using pointer arithmetic
    while (start < end) {
        // Swap the bytes pointed by start and end
        uint8_t temp = *start;
        *start = *end;
        *end = temp;
        // Move pointers inward
        start++;
        end--;
    }
    return src; // Return the pointer to the source (src)
}

int32_t *reserve_words(size_t length) {
    // Check for zero-length allocation
    if (length == 0) {
        return NULL;
    }
    // Allocate memory for the specified number of words
    int32_t *ptr = (int32_t *)malloc(length * sizeof(int32_t));

    return ptr; // Return the pointer to the allocated memory or NULL if allocation failed
}

void free_words(uint32_t *src) {
    // Check if the src pointer is not NULL before freeing
    if (src != NULL) {
        // Free the dynamically allocated memory
        free(src);
    }
}