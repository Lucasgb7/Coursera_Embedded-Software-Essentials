# Programming Assignment Instructions

## Description:

The folder contains 4 files:

- ```main.c``` - Main file you are to work with
- ```misc.c``` - File that declares some data and defines some functions
- ```misc.h``` - File that contains function declarations and macros
- ```msp432p401r.lds``` - Linker file for the msp432

## Objective

Given the code and linker file provided from the zip file, you will need to specify where the listed symbols will be placed in our program.Once you have figured out your memory space, you can take the Programming Assignment Quiz where you will provide detailsabout  specific symbol elements including:

- **Location Top segment or Type** - Code, Data, Peripheral, Register, None
- **Location Sub-segment** - Stack, Heap, BSS, Data, const/rodata, None
- **Access Permissions** - Read (R), Write (W) Read-write (RW), None
- **Lifetime** - Function/Block, Program, Indefinite, None

## Quiz 

Based on your code and the linker file , specify the following details for the segment, sub-segment, permissions, and lifetime of the following variables (based on the following table):

<table> <tr>
<td>

| Segment  | 1st Digit|     
| -------- | -------- |
| Code     | 1 |
| Data     | 2 |
| Peripheral  | 3 |
| Register | 4 |
| None     | 5 | 

</td><td>

| Sub-Segment  | 1st Digit|     
| -------- | -------- |
| Stack     | 1 |
| Heap     | 2 |
| BSS  | 3 |
| Data | 4 |
| const/rodata     | 5 |
| None     | 6 |
| Text     | 7 | 

</td><td>

| Permissions  | 1st Digit|     
| -------- | -------- |
| Read     | 1 |
| Write     | 2 |
| Read-write  | 3 |
| None | 4 |

</td><td>

| Lifetime  | 1st Digit|     
| -------- | -------- |
| Function/Block     | 1 |
| Program | 2 |
| Idefinite  | 3 |
| None | 4 |

</td>
</tr> </table>

- ```g1```: data | bss | RW | program
- ```g2```: code | const | R | program
- ```g3```: data | data | RW | program
- ```g4```: data | bss | RW | program
- ```g5```: data | data | RW | program
- ```N```: none | none | none | none
- ```l1```: register | none | RW | function
- ```l2```: data | stack | RW | function
- ```*l2 (dereferenced)```: data | heap | RW | indefinite
- ```l3```: data | stack | RW | function
- ```SOME_VALUE```: none | none | none | none
- ```f1```: data | stack | RW | function
- ```f2```: data | bss | RW | program
- ```f3```: data | stack | RW | function
- ```Hello World! (The string)```: code | rodata | R | Program
- ```main()```: code | text | R | Program
- ```func()```: code | text | R | Program