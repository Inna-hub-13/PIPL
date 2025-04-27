
// Write a program that generates 130 two-digit hex numbers and write them in a text file
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char generate_rand_hex_num();
void write_to_file(FILE*, int);

int main() {

    FILE* pf;
    pf = fopen("hex_numbers.txt", "w");
    if(!pf)
        return 1;
    write_to_file(pf, 130);

    fclose(pf);
    return 0;
}

char generate_rand_hex_num()
{
    char rand_num = rand() % 16;

    if(rand_num > 9)
        rand_num += 55;//ASCII upper letters
    else
        rand_num += 48;//ASCII decimal digits

    return rand_num;
}


void write_to_file(FILE* pF, int counter) {
    
    srand(time(0));
    char num1, num2;

    for(int i = 1; i < counter; i++){

        num1 = generate_rand_hex_num();
        num2 = generate_rand_hex_num();
        fprintf(pF, "%c%c, ", num1, num2);
        if(i % 10 == 0)
            fprintf(pF, "\n");
    }
    
    num1 = generate_rand_hex_num();
    num2 = generate_rand_hex_num();
    fprintf(pF, "%c%c\n", num1, num2);
}
