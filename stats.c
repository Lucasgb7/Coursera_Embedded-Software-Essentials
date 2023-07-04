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
 * @file stats.c 
 * @brief  C example code
 *
 * <Add Extended Description Here>
 *
 * @author Lucas Cunha
 * @date 30/06/2023
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  void print_array(unsigned char array[], unsigned int size) {
    int i;
    printf("[");
    for(i = 0; i < size; i++) {
      if (i == size - 1) printf("%u]", array[i]);
      else (printf("%u,", array[i]));
    }
  }

  printf("\nORIGINAL ARRAY: ");
  print_array(test, SIZE);

  printf("\nREVERSE SORTED ARRAY: ");
  sort_array(test, SIZE);
  print_array(test, SIZE);

  void print_statistics(unsigned char *array, unsigned int size) {
    printf("\n\n--------------- STATISTICS ---------------\n");
    printf("MINIMUM: %u", find_minimum(array, size));
    printf("\nMAXIMUM: %u", find_maximum(array, size));
    printf("\nMEAN: %u", find_mean(array, size));
    printf("\nMEDIAN: %u", find_median(array, size));
    printf("\n-------------------------------------------\n");
  }
  
  print_statistics(test, SIZE);
}

unsigned char find_median(unsigned char *array, unsigned int size) {
  return array[(size/2)-1];
}

unsigned char find_mean(unsigned char *array, unsigned int size) {
  unsigned char sum = 0;
  for(unsigned int i = 0; i < size; i++) {
    sum += array[i];
  }
  return sum/size;
}

unsigned char find_maximum(unsigned char *array, unsigned int size) {
  unsigned char max = array[0];
  for(unsigned int i = 1; i < size; i++) {
    if (array[i] > max) max = array[i];
  }
  return max;
}

unsigned char find_minimum(unsigned char *array, unsigned int size) {
  unsigned char min = array[0];
  for(unsigned int i = 1; i < size; i++) {
    if (array[i] < min) min = array[i];
  }
  return min;
}

void sort_array(unsigned char *array, unsigned int size) {
  unsigned int i, j;
  unsigned char temp;
  for (i = 0; i < size - 1; i++) {
      for (j = 0; j < size - i - 1; j++) {
          if (array[j] < array[j + 1]) {
              temp = array[j];
              array[j] = array[j + 1];
              array[j + 1] = temp;
          }
      }
  }
}
