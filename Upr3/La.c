
// Write a function that takes a string -> words, separated by one interval each
// the fuction must return the address of the first word, which ends in "la"

#include <stdio.h>
#define N 100

char* ends_with(char*, char*, int);

int main() {

    char string[N] = "mol berry kola cherry bang\0";
    
    printf("address %c : %p\n", *(string + 10), (string + 10));
    char* address = ends_with(string, "la\0", 2);
    printf("address: %p\n", address);
    return 0;
}

char* ends_with(char* str, char* suffix, int size_suffix) {

    char* address_check = NULL;
    // i -> iterates through str
    // j_suffix -> iterates through str_check
    // count_characters -> keeps the length of last found sequence of characters in str
    int i = 0, j_suffix, count_characters = 1;

    while(*(str + i)) {

        // no need to further check, if 
        // size_suffix >= count_characters
        // <ch> can't contain <cherry>
        if(*(str + i) == ' ' && size_suffix <= count_characters) {

            // because we don't need to count the ' ' charachter
            count_characters--;
            address_check = str + i - count_characters;
            j_suffix = 0;

            while(*(str + i - size_suffix + j_suffix) == *(suffix + j_suffix) 
                        && *(suffix))
                j_suffix ++;
            
            // all characters match
            if(j_suffix == size_suffix){
                
                printf("Starting character: %c\n", *address_check);
                return address_check;
            }
            
            count_characters = 0;
        }

        i++;
        count_characters ++;
    }

    return address_check;
}

