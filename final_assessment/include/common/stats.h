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
 * @file stats.h
 * @brief stats library
 *
 * Stats library file
 *
 * @author Lucas Cunha
 * @date 04-07-2023
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

#ifdef VERBOSE
/**
 * @brief Print an array in formated way
 *
 * @param array unsigned char *array
 * @param size unsigned int size of the array
 *
 */
void print_array(unsigned char *array, unsigned int size);
#endif

/**
 * @brief Given an array of data and a length, returns the median value
 *
 * @param array unsigned char *array
 * @param size unsigned int size of the array
 *
 * @return Median value from the given array
 */
unsigned char find_median(unsigned char *array, unsigned int size);

/**
 * @brief Given an array of data and a length, returns the mean value
 *
 * @param array unsigned char *array
 * @param size unsigned int size of the array
 *
 * @return Mean value from the given array
 */
unsigned int find_mean(unsigned char *array, unsigned int size);

/**
 * @brief Given an array of data and a length, returns the maximum value
 *
 * @param array unsigned char *array
 * @param size unsigned int size of the array
 *
 * @return Maximum value from the given array
 */
unsigned char find_maximum(unsigned char *array, unsigned int size);

/**
 * @brief Given an array of data and a length, returns the minimum value
 *
 * @param array unsigned char *array
 * @param size unsigned int size of the array
 *
 * @return Minimum value from the given array
 */
unsigned char find_minimum(unsigned char *array, unsigned int size);


/**
 * @brief Given an array of data and a length, returns the reversed sorted array
 * 
 * This functions uses Bubble Sort algorithm implementation
 *
 * @param array unsigned char *array
 * @param size unsigned int size of the array
 *
 * @return Reeversed sorted array
 */
void sort_array(unsigned char array[], unsigned int size);


#endif /* __STATS_H__ */
