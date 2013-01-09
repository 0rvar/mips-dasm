#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "mips_dasm.h"

int main(int argc, char **argv) {

    FILE *fd;
    char line[32];
    int line_no = 0;
    /*
     * Use either file from first argument or stdin.
     */
    if(argc < 2) {
        fd = stdin;
    } else {
        fd = fopen(argv[1], "r");
        if(fd == NULL) {
            perror(argv[1]);
            return 1;
        }
    }



    while(fgets(line, sizeof line, fd) != NULL) {
        uint32_t number = 0;
        mips_instruction_t* instruction = calloc(1, sizeof(mips_instruction_t));

        line_no += 1;

        /*
         * Parse both decimal and hexadecimal numbers
         */
        if(line[0] == '0' && line[1] == 'x') {
            sscanf(line, "%x", &number);
        } else {
            number = atoi(line);
        }
        
        printf("%d", line_no);

        

        if(mips_disassemble(instruction, number)) {
            printf(" (%c-type) ", instruction->type);
            printf("[%10u:0x%08x] ", number, number);
            printf("%s %s", instruction->name, instruction->arguments);
        } else {
            printf("Invalid instruction");
        }

        printf("\n");
        free(instruction);
    }

    return 0;
}
