default:
	gcc -Wall -o mips-dasm main.c mips_dasm.c

clang:
	clang -g -Wall -o mips-dasm main.c mips_dasm.c

tests:
	gcc -Wall -o tests instructions_test.c mips_dasm.c
	./tests; rm tests

tests-clang:
	clang -Wall -o tests instructions_test.c mips_dasm.c
	./tests; rm tests
