
// Write a function that takes a string -> words, separated by one interval each,
// the fuction must return the address of the first word, which ends in "la"

#include <stdio.h>
#define N 100

char* ends_with(char*, char*, int);

int main() {

    char string[N] = "berry cherry bang kot kola\0";
    
    printf("address of letter %c: %p\n", *(string + 22), string + 22);
    char* address = ends_with(string, "la\0", 2);
    printf("address: %p\n", address);
    return 0;
}

char* ends_with(char* str, char* suffix, int size_suffix) {

    char* address_check = NULL;
    // j_suffix -> iterates through suffix
    // count_characters -> keeps the length of the 
    // last found sequence of characters in str
    int j_suffix, count_characters = 0;

    while(*str) {

        // no need to further check, if 
        // size_suffix >= count_characters
        // <ch> can't contain <cherry>
        if(*str == ' ' && size_suffix <= count_characters) {

            j_suffix = 0;

            while(*(str - size_suffix + j_suffix) == *(suffix + j_suffix) 
                        && *(suffix + j_suffix))
                j_suffix ++;
            
            // all characters match
            if(j_suffix == size_suffix){
                
                address_check = str - count_characters;
                printf("Starting character: %c\n", *address_check);
                return address_check;
            }
            
            count_characters = 0;
        }
        else
            count_characters ++;

        str ++;
    }

    // because the last sequence of characters is skipped in while loop,
    // perform additional check
    if(size_suffix <= count_characters) {

        j_suffix = 0;
        while(*(str - size_suffix + j_suffix) == *(suffix + j_suffix) &&
                *(suffix + j_suffix))
            j_suffix++;

        if(j_suffix == size_suffix){
            
            address_check = str - count_characters;
            printf("Starting character: %c\n", *address_check);
                return address_check;
        }
    }

    return address_check;
}

