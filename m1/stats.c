/******************************************************************************
 * Copyright (C) 2023 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c 
 * @brief  C example code
 *
 * Most of the functions in the stats.c file require 2 input parameters and one return value:
 * Input: A unsigned char pointer to an n-element data array
 * Input: An unsigned integer as the size of the array
 * Output: An unsigned char result from the function
 *
 * @author Lucas Cunha
 * @date 07-07-2023
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void print_array(unsigned char *array, unsigned int size) {
  unsigned int i;
  printf("[");
  for(i = 0; i < size; i++) {
    if (i == size - 1) printf("%u]", array[i]);
    else (printf("%u, ", array[i]));
  }
}

void print_statistics(unsigned char *array, unsigned int size) {
  printf("\n\n--------------- STATISTICS ---------------\n");
  printf("Requested values and indexes: ");
  // Take all the functions values
  unsigned char maximum = find_maximum(array, size);
  unsigned char minimum = find_minimum(array, size);
  unsigned int mean = find_mean(array, size);
  unsigned char median = find_median(array, size);
  // Declaring flags to trigger after the value is found
  bool min_flag = false, max_flag = false, med_flag = false;
  // Getting statitcs indexes
  for (unsigned int i = 0; i < size; i++) {
    if (array[i] == minimum && !min_flag) {
      printf("\nMINIMUM: %u [%u]", minimum, i);
      min_flag = !min_flag;
    } else if (array[i] == maximum && !max_flag){
      printf("\nMAXIMUM: %u [%u]", maximum, i);
      max_flag = !max_flag;
    } else if (array[i] == median && !med_flag) {
      printf("\nMEDIAN: %u [%u]", median, i);
      med_flag = !med_flag;
    }
  }
  // Mean value doesn't have an index
  printf("\nMEAN: %u", mean);
  printf("\n-------------------------------------------\n");
}

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  printf("\nORIGINAL ARRAY: ");
  print_array(test, SIZE);

  printf("\nREVERSE SORTED ARRAY: ");
  sort_array(test, SIZE);
  print_array(test, SIZE);
  
  print_statistics(test, SIZE);
}

/* Find the median value from a given array */
unsigned char find_median(unsigned char *array, unsigned int size) {
  unsigned int middle = size / 2;
  // It checks if the array's size is even or odd
  if (size % 2 == 0) return ((array[middle - 1] + array[middle]) / 2);
  else return array[middle];
  // return array[(size/2)]; // Basic median
}

/* Find the mean value from a given array */
unsigned int find_mean(unsigned char *array, unsigned int size) {
  // The sum value should be int (it arranges more values)
  unsigned int sum = 0;
  for(unsigned int i = 0; i < size; i++) {
    sum += array[i];
  }
  return sum/size;
}

/* Find the maximum value from a given array */
unsigned char find_maximum(unsigned char *array, unsigned int size) {
  // The max value it's the first value from the array (temporary)
  unsigned char max = array[0];
  for(unsigned int i = 1; i < size; i++) {
    if (array[i] > max) max = array[i];
  }
  return max;
}

/* Find the minimum value from a given array */
unsigned char find_minimum(unsigned char *array, unsigned int size) {
  // The min value it's the first value from the array (temporary)
  unsigned char min = array[0];
  for(unsigned int i = 1; i < size; i++) {
    if (array[i] < min) min = array[i];
  }
  return min;
}

/* Bublesort function (reversed) */
void sort_array(unsigned char *array, unsigned int size) {
  unsigned int i, j;
  unsigned char temp;
  for (i = 0; i < size - 1; i++) {
      for (j = 0; j < size - i - 1; j++) { 
          if (array[j] < array[j + 1]) {  // Here its where is the reverse verification
              temp = array[j];
              array[j] = array[j + 1];
              array[j + 1] = temp;
          }
      }
  }
}
