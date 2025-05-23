
// Create a hash table representing a dictionary.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct words{

    char w1[15];
    char w2[15];
};

int hash_func(char*);
int search_pos(struct words*, int, char*);
int add(struct words*, int, struct words*);
char* translate(struct words*, int, char*);
int delete(struct words*, int, char*);

int main() {

    struct words* table = (struct words*)calloc(128, sizeof(struct words));
    if(!table)
        return -1;
    
    struct words temp;

    int i;
    char ans = 'Y';
    do{
        printf("Enter word in Bulgarian: ");
        scanf(" %s", temp.w1);
        printf("Enter that word in English: ");
        scanf(" %s", temp.w2);
        printf("add() returned: %d\n", add(table, 128, &temp));
        printf("Do you want to enter other words Y/N: ");
        scanf(" %c", &ans);
    }while(ans == 'Y');

    for(i = 0; i < 128; i++)
        if((table + i) -> w1[0] != 0)
            printf("%s %s\n", (table + i) -> w1, (table + i) -> w2);

    char *p;
    char buff[15];
    ans = 'Y';
    do{
        
        printf("Enter word to translate: ");
        scanf(" %s", buff);
        p = translate(table, 128, buff);
        printf("%s -> %s\n", buff, p);
        printf("Do you want to continue Y/N: ");
        scanf(" %c", &ans);
    }while(ans == 'Y');

    printf("Enter word to delete: ");
    scanf(" %s", buff);
    printf("delete() returned: %d\n", delete(table, 128, buff));
    
    for(i = 0; i < 128; i++)
        if((table + i) -> w1[0] != 0)
            printf("%s %s\n", (table + i) -> w1, (table + i) -> w2);
    
    return 0;
}

int hash_func(char* word) {
    
    int sum = 0;
    while(*word != 0){

        sum += *word;
        word++;
    }

    return sum & 127;
}

int search_pos(struct words* table, int size, char* word) {

    int pos = hash_func(word);
    int index = pos;

    do{
        
        // Found position
        if((table + index) -> w1[0] == 0)
            return index + size;

        // Word is already in table
        if(strcmp((table + index) -> w1, word) == 0)
            return index;

        index++;
    }while(index < size);

    index = 0;
    do{
        
        // Found position
        if((table + index) -> w1[0] == 0)
            return index + size;

        // Word is already in table
        if(strcmp((table + index) -> w1, word) == 0)
            return index;

        index++;
    }while(index < pos);

    // Table is full
    return -1;
}

int add(struct words* table, int size, struct words* words) {

    int pos = search_pos(table, size, words->w1);
    if(pos >= size){

        *(table + pos - size) = *words;
        return 0;
    }
    
    return -1;
}

char* translate(struct words* table, int size, char* word) {

    int pos = search_pos(table, size, word);
    // The word is in the table
    if(pos <= size && pos >= 0)
        return (table + pos) -> w2;
        
    return NULL;
}

int delete(struct words* table, int size, char* word) {

    int pos = search_pos(table, size, word);
    // The word is in the table, delete it
    if(pos <= size && pos >= 0){

        (table + pos) -> w1[0] = 0;
        (table + pos) -> w2[0] = 0;
        return 0;
    }

    return -1;
}
