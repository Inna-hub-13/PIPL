
// Implement a function that takes as a parameter string, that represents
// first name, middle name and family name - all separated by random number of intervals
// The function must remove the middle name

#include <stdio.h>
#include <string.h>

void remove_middle(char*);
void f1(char*);

int main() {

    char name[30];

    strcpy(name, "Jorge    Pancho   Panza");
    printf("%s\n", name);
    remove_middle(name);
    printf("%s\n", name);

    return 0;
}

void remove_middle(char* str){

    int i = 0, flag = 0, j;

    while(*(str + i) != ' ')
        i++;
    
    j = i;
    while(flag != 2 && *(str + j + 1)){

        if(*(str + j) == ' ' && *(str + j + 1) != ' ')
            flag++;
        j++;
    }
    
    i += 1;
    while(*(str + j)){

        *(str + i) = *(str + j);
        i++;
        j++;
    }
    
    *(str + i) = 0;

}



