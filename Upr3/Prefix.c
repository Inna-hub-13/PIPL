
// Write an implementation of a function that takes two strings -
// one containing words, seprated by one space only, the other a prefix

// The function must return the address of the first word that begins with the 
// given prefix


#include <stdio.h>
#define N 50

char* starts_with(char*, char*, int);

int main() {

    char str[N] = "pompa moza kola povdigam\0";
    printf("address of %c: %p\n", *(str + 16), str + 16);
    char * address = starts_with(str, "pov", 3);
    printf("address: %p\n", address);
    return 0;
}

char* starts_with(char* str, char* prefix, int size_prefix) {

    char* address = NULL;
    // j_prefix -> iterates through prefix
    // count_characters -> counts the number characters of the last
    // found sequence of characters
    int j_prefix, count_characters = 0;

    while(*str) {

        // count_characters >= size_prefix
        // prefix must be shorter than the last found sequence of characters
        // <ch> can't contain <cherry>
        if(*str == ' ' && count_characters >= size_prefix) {

            j_prefix = 0;
            while(*(str - count_characters + j_prefix) == *(prefix + j_prefix) && 
                    *(prefix + j_prefix))
                j_prefix++;
            
            // match found
            if(j_prefix == size_prefix) {

                address = str - count_characters;
                printf("Starting character: %c\n", *address);
                return address;
            }

            count_characters = 0;
        }
        else
            count_characters++;

        str++;
    }

    // because the last sequence of characters is skipped in the while loop
    // perform additional check
    if(count_characters >= size_prefix) {

        j_prefix = 0;
        while(*(str - count_characters + j_prefix) == *(prefix + j_prefix) &&
                *(prefix + j_prefix))
            j_prefix ++;
        
        if(j_prefix == size_prefix) { 

            address = str - count_characters;
            printf("Starting character: %c\n", *address);
            return address;
        }
    }

    return address;
}
