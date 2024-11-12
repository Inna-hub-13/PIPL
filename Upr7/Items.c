
// Write a program, that creates a text file and writes information to it
// in a given format about the items in a factory.

// Write a function, that reads from the created file and finds
// the items from given room.

#include <stdio.h>
#define N 30

int input(char*);
int find_items(char*, int);

int main() {

    printf("input() returned: %d\n", input("items.txt"));
    printf("find_items() returned: %d\n", find_items("items.txt", 102));
    return 0;
}

int input(char* filename) {

    FILE * pf;
    // try to open text file in write mode
    pf = fopen(filename, "w");
    if(!pf)
        return - 1;

    char answ;
    printf("Do you want to add item? (Y/N): ");
    scanf(" %c", &answ);

    if(answ == 'Y') {

        int num_item, num_room;
        char name_item[N];

        while(answ == 'Y') {

            printf("Enter num_item: ");
            scanf(" %d", &num_item);

            printf("Enter num_room: ");
            scanf(" %d", &num_room);

            printf("Enter name_item: ");
            scanf(" %[^\n]s", name_item);

            fprintf(pf, "%d\t%d\t%s\n", num_item, num_room, name_item);

            printf("Do you want to add item? (Y/N): ");
            scanf(" %c", &answ);
        } 

        fclose(pf);
        return 0;
    }

    return -1;
}

int find_items(char* filename, int num_r) {

    FILE *pf;
    pf = fopen(filename, "r");
    if(!pf)
        return -1;
    
    int num_room, num_item, end;
    char name_item[N];
    
    // fscanf reads from a file, pointed by the FILE pointer
    // it returns zero or EOF, if unsuccessful 
    // otherwise, it returns the number of items successfully assigned
    while(fscanf(pf, " %d\t%d\t%[^\n]s", &num_item, &num_room, name_item) > 0) {

        if(num_r == num_room)
            printf("%s\n", name_item);
        
    }

    fclose(pf);
    return 0;
}

