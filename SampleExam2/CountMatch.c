
// Write a function that takes as a parameter string, that has words, separated by
// intervals. The function must return the number of words, containing
// the symbol '_' at least once.

#include <stdio.h>

int count_words(char*, char);

int main() {

    char str[100];
    printf("Enter words: ");
    scanf(" %[^\n]s", str);
    int count = count_words(str, '_');
    printf("count_words returned: %d\n", count);
    printf("%s\n", str);

    return 0;
}

int count_words(char* str, char key) {

    int flag_found = 0, count = 0;

    while(*str){

        if(*str == ' ' && flag_found){

            count += 1;
            flag_found = 0;
        }
        else if(*str == key)
            flag_found = 1;

        str++; 
    }

    // check for the last word
    if(flag_found)
        count += 1;
    
    return count;
}
