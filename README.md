# mips-dasm
mips-dasm is a mips disassembler written in Java. It accepts lines of 32-bit numbers
that it decodes into their MIPS32 instruction equivalent, through stdin or input file.

## Requirements
gcc or clang

## Getting started
Build using make: 

    make
    
    
and then execute:

    ./mips-dasm [input.txt]
    
## Tests
A test suite is included to verify the correctness of the disassembler.
To run it, do:

    make tests

## Supported instructions
Almost all instructions except for floating point are supported.

See instructions_test.c for a complete list of supported instructions.
