
// Write a function that takes as parameter a string of letters and dots only.
// The function must return a resized string as follows:

// If there is a sequence of the type l1 < l2 < l3 .. < ln,
// replace it with l1..ln

// Otherwise perform no changes
// *the opposite function of the one in LettersDots.c

#include <stdio.h>
#include <stdlib.h>
#define N 100

char* shrink(char*);

int main() {

    char str[N] = "abcd.lacvxyz..yj...klAbCDEFDA";
    printf("str: %s\n", str);
    char* str1 = shrink(str);
    printf("str1: %s\n", str1);
    return 0;
}

char* shrink(char* str) {

    char* str1 = (char*)malloc(N * sizeof(char));

    if(!str1)
        return NULL;
    
    // str_p -> stores the address of the first 
    // character form the sequence l1 < l2 < .. < ln
    // str1_p -> loops through the string str1
    char* str_p;
    char* str1_p = str1;

    while(*str) {

        if(*str < *(str + 1) && *(str + 1) < *(str + 2) && *str != '.'){

            str_p = str;
            while(*str < *(str + 1))
                str++;
            
            *str1_p = *str_p;
            *(str1_p + 1) = '.';
            *(str1_p + 2) = '.';
            *(str1_p + 3) = *str;
            str1_p += 4;
        }

        else {

            *str1_p = *str;
            str1_p++;
        }

        str++;
    }

    *str1_p = 0;
    return str1;
}


