# Expanded Build System and Memory

In this programming assignment, you will get more experience with Git Version control, write more C-programming code, and integrate your code with your build system. You will reuse your version control repository and add some new c-programming functions that manipulate memory. You will test your code on your host machine, but your code should compile for both the target platform and host platform. We will use the target platform in future assignments.

## Build Instructions

On the "final_assessment" folder type: 
``` Shell
make build
```
By default, the flags *-DVERBOSE -DHOST -DCOURSE1* are called. (You can change it by passing on the terminal or change in the Makefile)


### *main.c* 

Call a function that is defined in the course1.c source file. Simple main() function that can switch which course deliverable we wish to call by specifying the -DCOURSE1 compile time switch.

``` C
#ifdef COURSE1
  course1();
#endif
```

### *stats.c/stats.h*

Modified print_array() function in stats.c that you can enable/disable debug printing with a compile time switch. This compile time switch is enabled (by default) with a VERBOSE flag in the makefile ( -DVERBOSE). If enabled, the print_array function print as normal. If not defined, nothing should print. Additionally, PRINTF macro defined in platform.h is used.

### *memory.c/memory.h*

This file have some basic memory movement options and some memory manipulation functions.

- **my_memmove()**: This function takes two byte pointers (one source and one destination) and a length of bytes to move from the source location to the destination.
- **my_memcopy()**: This function takes two byte pointers (one source and one destination) and a length of bytes to copy from the source location to the destination.
- **my_memset()**: This should take a pointer to a source memory location, a length in bytes and set all locations of that memory to a given value.
- **my_memzero()**: This should take a pointer to a memory location, a length in bytes and zero out all of the memory.
- **my_reverse()**: This should take a pointer to a memory location and a length in bytes and reverse the order of all of the bytes.
- **reserve_words()**: This should take number of words to allocate in dynamic memory
- **free_words()**: Should free a dynamic memory allocation by providing the pointer src to the function

### *data.c/data.h*

This file should do some very basic data manipulation.

- **my_itoa()**: Integer-to-ASCII needs to convert data from a standard integer type into an ASCII string.

- **my_atoi()**: ASCII-to-Integer needs to convert data back from an ASCII represented string into an integer type.

### *course1.c/course.h*

These files are new and will hold some final course assessment functions.

- **course1()**: These include test_data1(), test_data2(), test_memmove1(), test_memmove2(), test_memmove3(), test_memcopy(), test_memset(), and test_reverse().
- **test_data1()**: This function will test to atoi and itoa conversions.
- **test_data2()**: This function will test to atoi and itoa conversions.
- **test_memmove1()**: This function will test non-overlapped memmove.
- **test_memmove2()**: This function will test overlapped memmove where there is overlap of the end of destination and start of the source regions.
- **test_memmove3()**: This function will test overlapped memmove where there is overlap of the start of destination and end of the source regions.
- **test_memcopy()**: This function will test memcopy.
- **test_memset()**: This function will test memset and memzero.
- **test_reverse()**: This function will test reverse.

