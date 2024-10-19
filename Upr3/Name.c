
// Write functions that take the names of a Bulgarian citizen
// *we assume the names are separated by spaces

// 1) func1 -> removes the second name
// 2) func2 -> replaces the second name with the corresponding intial and dot
// 3) func3 -> replaces the second and the first names with the corresponding intials

#include <stdio.h>
#include <string.h>
#define N 50

void remove_second(char*);
void make_second_initial(char*);
void make_first_second_initial(char*);

int main() {

    char name[N];
    strcpy_s(name, N, "Ivan Ivanov Popov");
    //printf("Enter a name: ");
    //scanf("%[^\n]s", name);
    printf("Name: %s\n", name);
    remove_second(name);
    printf("Name: %s\n", name);
    strcpy_s(name, N, "Ivan Ivanov Popov");
    make_second_initial(name);
    printf("Name: %s\n", name);
    strcpy_s(name, N, "Eva-Maria Ivanova Popova");
    make_first_second_initial(name);
    printf("Name: %s\n", name);

    return 0;
}

void remove_second(char* name) {

    int i = 0, j = 0, k = 0;

    while(*(name + i)) {

        /*if(*(name + i) == ' '){

            i++;
            while(*(name + i) != ' ')
                i++;
        }
           
        *(name + j) = *(name + i);
        j++;
        i++;*/

        if(*(name + i) == ' ')
            k++;
        
        if(k != 1){

            *(name + j) = *(name + i);
            j++;
        }
        i++;
    }

    *(name + j) = '\0';
}

void make_second_initial(char* name) {

    int i = 0, j = 0;

    while(*(name + i)) {

        if(*(name + i) == ' ') {

            *(name + j) = ' ';
            *(name + j + 1) = *(name + i + 1);
            *(name + j + 2) = '.';
            j += 3;
            i++;
            while(*(name + i) != ' ')
                i++;
        }

        *(name + j) = *(name + i);
        i++;
        j++;
    }

    *(name + j) = '\0';
}

void make_first_second_initial(char* name) {

    int i = 0, j = 0, k = 0;

    *(name + j) = *(name + i);
    *(name + j + 1) = '.';

    j += 2;

    while(*(name + i)) {

        if(*(name + i) == ' ')
            k++;
            
        // checks for hypothetical double
        else if(*(name + i) == '-'){

            *(name + j) = *(name + i);
            *(name + j + 1) = *(name + i + 1);
            *(name + j + 2) = '.';

            j += 3;
        }

        if(k == 1) {

            *(name + j) = *(name + i);
            *(name + j + 1) = *(name + i + 1);
            *(name + j + 2) = '.';

            j += 3;
            // otherwise this if will always be true
            k++;
        }

        // second whitespace found
        else if(k == 3) {

            *(name + j) = *(name + i);
            j++;
        }

        i++;
    }

    *(name + j) = '\0';
}
