
// Write a function that takes a string in the format
// "0-129-57342-0/The C++ Programing Language/2012/Addison-Wesley"

// The fuction must read the data from the string and write it to a struct element
// and return the address of the element

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Book{

    char ISBN[14];
    char BookName[30];
    int Year;
    char Publisher[25];
};

int get_number(char*);
struct Book* get_element(char*);

int main() {

    char str[100];
    strcpy(str, "0-129-57342-0/The C++ Programing Language/2012/Addison-Wesley");
    struct Book* temp = get_element(str);

    if(temp) {

        printf("ISBN: %s\n", temp->ISBN);
        printf("BookName: %s\n", temp->BookName);
        printf("Year: %d\n", temp->Year);
        printf("Publisher: %s\n", temp->Publisher);
    }
    
    return 0;
}


int get_number(char* number) {

    int size = 0, i, num = 0, pow, ten;
    while(*(number + size))
        size ++;
    
    for(i = 0; i < size; i++){

        pow = size - i - 1;
        ten = 1;

        while(pow) {
            ten *= 10; 
            pow--;
        }

        num += (*(number + i) - '0') * ten;
    }

    return num;
}

struct Book* get_element(char* str) {

    struct Book* temp = (struct Book*)malloc(sizeof(struct Book));
    if(!temp)
        return NULL;
    
    
    int i, j = 0;
    char year_str[6];
    
    for(i = 0; *(str + i) != '/'; i++, j++)
        temp->ISBN[j] = *(str + i);
    
    temp->ISBN[j] = 0;
    i++;

    for(j = 0; *(str + i) != '/'; i++, j++)
        temp->BookName[j] = *(str + i);
    
    temp->BookName[j] = 0;
    i++;
    
    for(j = 0; *(str + i) != '/'; i++, j++)
        year_str[j] = *(str + i);
    
    year_str[j] = 0;

    temp->Year = get_number(year_str);
    
    i++;
    for(j = 0; *(str + i); i++, j++)
        temp->Publisher[j] = *(str + i);
    
    temp->Publisher[j] = 0;

    return temp;
}

