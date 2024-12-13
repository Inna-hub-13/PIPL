
// Write a function that takes as a parameter string
// The function must return 0 or 1 if the string contains a floating point number

#include <stdio.h>
#include <string.h>

int has_float(char*);

int main() {

    char str[30];
    strcpy(str, "dkek 0.k jd3 839 9.2");

    int i;
    i = has_float(str);
    printf("i = %d\n", i);
    return 0;
}

int has_float(char* str) {

    int i = 0;

    while(*(str + i + 2)){

        if(*(str + i) >= '0' && *(str + i) <= '9')
            if(*(str + i + 1) == '.')
                if(*(str + i + 2) >= '0' && *(str + i + 2) <= '9')
                    return 1;
        i++;
    }

    return 0;
}

