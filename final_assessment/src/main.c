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
 * @file main.c
 * @brief Main entry point to the Final Assessment
 *
 * @author Lucas Cunha @Lucasgb7
 * @date July 26 2023
 *
 */
#include <stdint.h>
#include "../include/common/course1.h"
#include "../include/common/platform.h"
#include "../include/common/memory.h"
#include "../include/common/data.h"
#include "../include/common/stats.h"

int main(void) {
  #ifdef COURSE1
    course1();
  #endif 
  return 0;
}

