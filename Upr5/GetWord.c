
// Write a function that takes as a parameter string, made of words, separated
// by one interval each 

// 1) dynamically allocates array, copies the first word to it
// and returns the address of the array
// 2) dynamically allocates array, copies the last word to it
// and returns the address of the array
// 3) dynamically allocates array, copies the longest word to it
// and returns the address of the array


#include <stdio.h>
#include <stdlib.h>

char* get_first(char*);
char* get_last(char*);
char* get_longest(char*);

int main() {

    char* str = "cake you have crappywappy birthday\0";
    printf("str: %s\n", str);
    char* first = get_first(str);
    printf("first: %s\n", first);
    char* last = get_last(str);
    printf("last: %s\n", last);
    char* longest = get_longest(str);
    printf("longest: %s\n", longest);

    return 0;
}

char* get_first(char* str) {

    int count = 0, i;
    while(*(str + count) != ' ')
        count++;

    char* first = (char*)malloc((count + 1) * sizeof(char));

    if(!first)
        return NULL;

    for(i = 0; i < count; i++)
        *(first + i) = *(str + i);

    *(first + i) = 0;

    return first;
}

char* get_last(char* str) {

    int count = 0, i;
    while(*str){

        if(*str == ' ')
            count = 0;
        else
            count++;
        str++;
    }

    char* last = (char*)malloc((count + 1)*sizeof(char));
    if(!last)
        return NULL;
    
    // return str to point to the first character of the last word
    str -= count;
    for(i = 0; i < count; i++)
        *(last + i) = *(str + i);
    
    *(last + i) = 0;

    return last;
}

char* get_longest(char* str) {

    // count -> counts number of characters for the current word
    // max_count -> keeps the size of the longest word
    // p -> points to the begining of the longest word
    int count = 0, max_count = 0, i;
    char* p_max = NULL;

    while(*str) {

        if(*str == ' '){

            if(count > max_count){

                max_count = count;
                p_max = str - max_count;
            }
            count = 0;
        }
        else
            count++;
        
        str++;
    }

    //last word skipped in the loop
    if(count > max_count){

        max_count = count;
        p_max = str - max_count;
    }

    char* longest = (char*)malloc((max_count + 1)*sizeof(char));
    if(!longest)
        return NULL;
    
    for(i = 0; i < max_count; i++, p_max++)
        *(longest + i) = *p_max;
    
    *(longest + i) = 0;
    return longest ;
}
