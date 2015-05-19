# mips-dasm
mips-dasm is a mips disassembler written in C. It accepts lines of 32-bit numbers
that it decodes into their MIPS32 instruction equivalent, through stdin or input file.

## Requirements
gcc or clang

## Getting started
Build using make:

    make


and then execute:

    ./mips-dasm [input.txt]

## Usage
The program takes one hexadecimal or decimal number per line. Example:

    0x01398821
    0x71208821
    0x0229001a
    0x213104d2
    0x8d31fb2e

becomes

    1 (R-type) [  20547617:0x01398821] addu $s1, $t1, $t9
    2 (R-type) [1897957409:0x71208821] clo $s1, $t1
    3 (R-type) [  36241434:0x0229001a] div $s1, $t1
    4 (I-type) [ 556860626:0x213104d2] addi $s1, $t1, 1234
    5 (I-type) [2368863022:0x8d31fb2e] lw $s1, -1234($t1)

## Tests
A test suite is included to verify the correctness of the disassembler.
To run it, do:

    make tests

## Supported instructions
Almost all instructions except for floating point are supported.

See instructions_test.c for a complete list of supported instructions.

## License
The code is licensed under CC0 - see LICENSE.txt
