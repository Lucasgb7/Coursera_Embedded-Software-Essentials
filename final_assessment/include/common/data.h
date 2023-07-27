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
 * @file data.h
 * @brief Data library
 *
 * Data library file
 *
 * @author Lucas Cunha
 * @date July 26 2023
 *
 */
#ifndef __DATA_H__
#define __DATA_H__
#include <stdint.h>

/**
 * @brief Integer-to-ASCII converts data from a standard integer type into an ASCII string.
 * 
 * Converts a passed data in as a signed 32-bit integer given a base (2 or 16).
 * 
 * @param data the number you wish to convert passed as a signed 32-bit integer.
 * @param ptr converted character string to the uint8_t* pointer.
 * @param base support bases 2 to 16 (decimal/hexadecimal).
 *
 * @return the length of the converted data.
 */
uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base); 

/**
 * @brief ASCII-to-Integer converts data back from an ASCII represented string into an integer type.
 * 
 * Converts a passed data in as a signed 32-bit string given a base (2 or 16).
 * 
 * @param ptr converted character string to the uint8_t* pointer. 
 * @param digits the number you wish to convert passed as a signed 8-bit integer.
 * @param base support bases 2 to 16 (decimal/hexadecimal).
 *
 * @return the length of the converted data.
 */
int32_t my_atoi(uint8_t *ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */
