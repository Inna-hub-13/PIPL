
// Write a program that removes the unncessary intervals
// *we assume there are no intial and ending intervals

#include <stdio.h>
#define N 100

void remove_intervals(char*);

int main() {

    char words[N];
    printf("Enter words, separated by spaces: ");
    scanf("%[^\n]s", words);
    printf("%s\n", words);
    remove_intervals(words);
    printf("%s\n", words);
    return 0;
}

void remove_intervals(char* str) {

    // k counts intervals
    int j = 0, i = 0, k = 0;

    while(*(str + i)) {

        if(*(str + i) == ' ')
            k++;

        else {

            if(k > 0) {

                *(str + j) = ' ';
                j++;
                k = 0;
            }

            *(str + j) = *(str + i);
                j++;
        }

        i++;
    }

    *(str + j) = '\0';
}