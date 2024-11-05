
// Write a function that reads the first and the last byte of an integer
// *we assume the integer has size 4 bytes

#include <stdio.h>

void first_last_byte(int *);

int main() {

    int num = 1200;
    first_last_byte(&num);
    num = 4;
    first_last_byte(&num);
    num = 0;
    first_last_byte(&num);
    num = -1;
    first_last_byte(&num);

    return 0;
}

void first_last_byte(int* n) {

    char* pc = (char*)n;
    printf("first byte: %d\n", *pc);
    printf("last byte: %d\n", *(pc + 3));
}