
// Write a function that takes a string of letters and dots only.
// The function must resize the string as follows:

// If there is a sequence of the type - l1..l2,
// replace it with all the letters from l1 to l2, if l2 > l1

// Otherwise perform no change

//The function returns resized string
//*we assume the returned string can take all the added characters

//Version 2 of LettersDots.c

#include <stdio.h>
#include <stdlib.h>
#define N 100

char* resize(char*);

int main() {

    char* str = "b...A..El..q..c..d\0";
    printf("str: %s\n", str);
    char* str1 = resize(str);
    printf("str1: %s\n", str1);
    return 0;
}

char* resize(char* str) {

    char* str1 = (char*)malloc(N * sizeof(char));

    if(!str1)
        return NULL;
    
    // k -> gives us the needed character from ASCII
    // str1_p -> iterates through str1
    char k;
    char* str1_p = str1;
    while(*str) {

        // '.' < 'a', '.' < 'A'
        if(*(str + 1) == '.' && *(str + 2) == '.' && *str < *(str + 3) && *str != '.') {

            k = *str;
            while(k <= *(str + 3)){

                *str1_p = k;
                k++;
                str1_p++;
            }
            str += 3;
        }
        else{
            
            *str1_p = *str;
            str++;
            str1_p++;
        }
    }

    *str1_p = 0;
    return str1;
}
