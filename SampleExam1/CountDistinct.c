
// In a text file are stored words, separated by one or more intervals.
// Write a function that takes a pointer to input stream and returns the 
// number of the different words.

#include <stdio.h>
#include <string.h>

int words_count(FILE*);

int main() {

    FILE* input = fopen("words.txt", "r");
    if(!input)
        return -1;
    
    printf("words_count() returned: %d\n", words_count(input));

    fclose(input);
    return 0;
}

int words_count(FILE* input) {

    FILE* output = fopen("words2.txt", "w+");
    if(!output)
        return -1;

    char word[25];
    char cmp[25];

    char ch, flag = '0';
    int i = 0, count = 0;

    while(fscanf(input, "%c", &ch) > 0) {

        if(ch != ' ' && ch != '\n'){

            *(word + i) = ch;
            i++;
            flag = '1';
        }
        // we have a word
        else if(flag == '1'){

            *(word + i) = '\0';

            while(fscanf(output, "%s\n", cmp) > 0 && flag != '2'){

                // found a repeated word
                if(strcmp(cmp, word) == 0)
                    flag = '2';
            }
                

            if(flag != '2'){

                fprintf(output, "%s\n", word);
                count++;
            }

            // return the pointer to the begining of the file
            fseek(output, 0, SEEK_SET);
            flag = '0';
            i = 0;
        }
    }

    fclose(output);
    return count;
}
