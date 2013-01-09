#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "mips_dasm.h"

#define COMPARE(number, type, compare_name, compare_args) { \
    tests += 1; \
    if(assert_disassembles_to(number, type, compare_name, compare_args)) { \
        passed += 1; \
    } \
}

int assert_disassembles_to(uint32_t number, char type, const char *expected_name, const char *expexted_args);

int main(int argc, char** argv) {
    int tests = 0;
    int passed = 0;

    COMPARE(0x01398820, 'R', "add", "$s1, $t1, $t9");
    COMPARE(0x01398821, 'R', "addu", "$s1, $t1, $t9");
    COMPARE(0x01398824, 'R', "and", "$s1, $t1, $t9");
    COMPARE(0x71208821, 'R', "clo", "$s1, $t1");
    COMPARE(0x71208820, 'R', "clz", "$s1, $t1");
    COMPARE(0x0229001a, 'R', "div", "$s1, $t1");
    COMPARE(0x0229001b, 'R', "divu", "$s1, $t1");
    COMPARE(0x02290018, 'R', "mult", "$s1, $t1");
    COMPARE(0x02290019, 'R', "multu", "$s1, $t1");
    COMPARE(0x71398802, 'R', "mul", "$s1, $t1, $t9");
    COMPARE(0x72290000, 'R', "madd", "$s1, $t1");
    COMPARE(0x72290001, 'R', "maddu", "$s1, $t1");
    COMPARE(0x72290004, 'R', "msub", "$s1, $t1");
    COMPARE(0x72290005, 'R', "msubu", "$s1, $t1");
    COMPARE(0x01398827, 'R', "nor", "$s1, $t1, $t9");
    COMPARE(0x01398825, 'R', "or", "$s1, $t1, $t9");
    COMPARE(0x00098cc0, 'R', "sll", "$s1, $t1, 19");
    COMPARE(0x03298804, 'R', "sllv", "$s1, $t1, $t9");
    COMPARE(0x00098cc3, 'R', "sra", "$s1, $t1, 19");
    COMPARE(0x03298807, 'R', "srav", "$s1, $t1, $t9");
    COMPARE(0x00098cc2, 'R', "srl", "$s1, $t1, 19");
    COMPARE(0x03298806, 'R', "srlv", "$s1, $t1, $t9");
    COMPARE(0x01398822, 'R', "sub", "$s1, $t1, $t9");
    COMPARE(0x01398823, 'R', "subu", "$s1, $t1, $t9");
    COMPARE(0x01398826, 'R', "xor", "$s1, $t1, $t9");
    COMPARE(0x0139882a, 'R', "slt", "$s1, $t1, $t9");
    COMPARE(0x0139882b, 'R', "sltu", "$s1, $t1, $t9");
    COMPARE(0x01208809, 'R', "jalr", "$s1, $t1");
    COMPARE(0x00000000, 'R', "nop", "");
    
    COMPARE(0x213104d2, 'I', "addi", "$s1, $t1, 1234");
    COMPARE(0x2131fb2e, 'I', "addi", "$s1, $t1, -1234");
    COMPARE(0x253104d2, 'I', "addiu", "$s1, $t1, 1234");
    COMPARE(0x2531fb2e, 'I', "addiu", "$s1, $t1, -1234");
    COMPARE(0x293104d2, 'I', "slti", "$s1, $t1, 1234");
    COMPARE(0x2931fb2e, 'I', "slti", "$s1, $t1, -1234");
    COMPARE(0x2d3104d2, 'I', "sltiu", "$s1, $t1, 1234");
    COMPARE(0x2d31fb2e, 'I', "sltiu", "$s1, $t1, -1234");
    COMPARE(0x313104d2, 'I', "andi", "$s1, $t1, 1234");
    COMPARE(0x353104d2, 'I', "ori", "$s1, $t1, 1234");
    COMPARE(0x393104d2, 'I', "xori", "$s1, $t1, 1234");
    COMPARE(0x3c1104d2, 'I', "lui", "$s1, 1234");
    COMPARE(0x062c04d2, 'I', "teqi", "$s1, 1234");
    COMPARE(0x062cfb2e, 'I', "teqi", "$s1, -1234");
    COMPARE(0x062e04d2, 'I', "tnei", "$s1, 1234");
    COMPARE(0x062efb2e, 'I', "tnei", "$s1, -1234");
    COMPARE(0x062804d2, 'I', "tgei", "$s1, 1234");
    COMPARE(0x0628fb2e, 'I', "tgei", "$s1, -1234");
    COMPARE(0x062904d2, 'I', "tgeiu", "$s1, 1234");
    COMPARE(0x0629fb2e, 'I', "tgeiu", "$s1, -1234");
    COMPARE(0x062a04d2, 'I', "tlti", "$s1, 1234");
    COMPARE(0x062afb2e, 'I', "tlti", "$s1, -1234");
    COMPARE(0x062b04d2, 'I', "tltiu", "$s1, 1234");
    COMPARE(0x062bfb2e, 'I', "tltiu", "$s1, -1234");
    COMPARE(0x813104d2, 'I', "lb", "$s1, 1234($t1)");
    COMPARE(0x8131fb2e, 'I', "lb", "$s1, -1234($t1)");
    COMPARE(0x913104d2, 'I', "lbu", "$s1, 1234($t1)");
    COMPARE(0x9131fb2e, 'I', "lbu", "$s1, -1234($t1)");
    COMPARE(0x853104d2, 'I', "lh", "$s1, 1234($t1)");
    COMPARE(0x8531fb2e, 'I', "lh", "$s1, -1234($t1)");
    COMPARE(0x953104d2, 'I', "lhu", "$s1, 1234($t1)");
    COMPARE(0x9531fb2e, 'I', "lhu", "$s1, -1234($t1)");
    COMPARE(0x8d3104d2, 'I', "lw", "$s1, 1234($t1)");
    COMPARE(0x8d31fb2e, 'I', "lw", "$s1, -1234($t1)");
    COMPARE(0x893104d2, 'I', "lwl", "$s1, 1234($t1)");
    COMPARE(0x8931fb2e, 'I', "lwl", "$s1, -1234($t1)");
    COMPARE(0x993104d2, 'I', "lwr", "$s1, 1234($t1)");
    COMPARE(0x9931fb2e, 'I', "lwr", "$s1, -1234($t1)");
    COMPARE(0xc13104d2, 'I', "ll", "$s1, 1234($t1)");
    COMPARE(0xc131fb2e, 'I', "ll", "$s1, -1234($t1)");
    COMPARE(0xa13104d2, 'I', "sb", "$s1, 1234($t1)");
    COMPARE(0xa131fb2e, 'I', "sb", "$s1, -1234($t1)");
    COMPARE(0xa53104d2, 'I', "sh", "$s1, 1234($t1)");
    COMPARE(0xa531fb2e, 'I', "sh", "$s1, -1234($t1)");
    COMPARE(0xad3104d2, 'I', "sw", "$s1, 1234($t1)");
    COMPARE(0xad31fb2e, 'I', "sw", "$s1, -1234($t1)");
    COMPARE(0xa93104d2, 'I', "swl", "$s1, 1234($t1)");
    COMPARE(0xa931fb2e, 'I', "swl", "$s1, -1234($t1)");
    COMPARE(0xb93104d2, 'I', "swr", "$s1, 1234($t1)");
    COMPARE(0xb931fb2e, 'I', "swr", "$s1, -1234($t1)");
    COMPARE(0xe13104d2, 'I', "sc", "$s1, 1234($t1)");
    COMPARE(0xe131fb2e, 'I', "sc", "$s1, -1234($t1)");
    COMPARE(0x1229ffff, 'I', "beq", "$s1, $t1, -1");
    COMPARE(0x1229000e, 'I', "beq", "$s1, $t1, 14");
    COMPARE(0x0621fffd, 'I', "bgez", "$s1, -3");
    COMPARE(0x0621000c, 'I', "bgez", "$s1, 12");
    COMPARE(0x0631fffb, 'I', "bgezal", "$s1, -5");
    COMPARE(0x0631000a, 'I', "bgezal", "$s1, 10");
    COMPARE(0x1e20fff9, 'I', "bgtz", "$s1, -7");
    COMPARE(0x1e200008, 'I', "bgtz", "$s1, 8");
    COMPARE(0x1a20fff7, 'I', "blez", "$s1, -9");
    COMPARE(0x1a200006, 'I', "blez", "$s1, 6");
    COMPARE(0x0630fff5, 'I', "bltzal", "$s1, -11");
    COMPARE(0x06300004, 'I', "bltzal", "$s1, 4");
    COMPARE(0x0620fff3, 'I', "bltz", "$s1, -13");
    COMPARE(0x06200002, 'I', "bltz", "$s1, 2");
    COMPARE(0x1629fff1, 'I', "bne", "$s1, $t1, -15");
    COMPARE(0x16290000, 'I', "bne", "$s1, $t1, 0");
    
    COMPARE(0xbfffb2e, 'J', "j", "-1234");
    COMPARE(0x80004d2, 'J', "j", "1234");
    COMPARE(0xffffb2e, 'J', "jal", "-1234");
    COMPARE(0xc0004d2, 'J', "jal", "1234");

    printf("%d/%d tests passed\n", passed, tests); \
    return 0;
}


int assert_disassembles_to(uint32_t number, char type, const char *expected_name, const char *expected_args) {
    mips_instruction_t instruction;
    
    if(!mips_disassemble(&instruction, number)) {
        printf("Test failed for 0x%x: invalid instruction\n(expected %s %s) \n\n", 
                number, expected_name, expected_args);
        return 0;
    }
    
    if(instruction.type != type) {
        printf("Test failed for 0x%x: wrong type (got %c, expected %c) \n",
                number, instruction.type, type);
        return 0;
    }

    if(strcmp(expected_name, instruction.name) != 0) {
        printf("Test failed for 0x%x: wrong name (got %s, expected %s) \n",
                number, instruction.name, expected_name);
        return 0;
    }

    if(strcmp(expected_args, instruction.arguments) != 0) {
        printf("Test failed for 0x%x: (%s) wrong args\n(got %s, expected %s) \n\n",
                number, instruction.name, instruction.arguments, expected_args);
        return 0;
    }

    return 1;
}
