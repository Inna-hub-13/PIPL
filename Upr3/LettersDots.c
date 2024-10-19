
// Write a function that takes a string of letters and dots only.
// The function must resize the string as follows:

// If there is a sequence of the type - l1..l2,
// replace it with all the letters from l1 to l2, if l2 > l1

// Otherwise perform no change

//The function returns resized string
//*we assume the returned string can take all the added characters

#include <stdio.h>
#include <stdlib.h>
#define N 100

char* resize(char*);

int main() {

    char* str = "n.a..l..q..v..bsa..\0";
    printf("str: %s\n", str);
    char* str_r = resize(str);
    printf("str_r: %s\n", str_r);
    return 0;
}

char* resize(char* str) {

    char* str1 = (char*)malloc(N * sizeof(char));
    // k -> counts the number of letters form l1 to l2
    // i -> after every iteration, <i + *str> becomes the next character from ASCII
    int i, k;

    if(!str1)
        return NULL;

    // str1_p -> loops through str1 array
    char* str1_p = str1;

    while(*str) {

        // '.' < 'a', '.' < 'A' 
        if(*(str + 1) == '.' && *(str + 2) == '.' && *(str + 3) > *str){

                i = 0;
                k = *(str + 3) - *str;

                while(k >= 0) {

                    *str1_p = *str + i;
                    k--;
                    i++;
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

