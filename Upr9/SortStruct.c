
//Sort the elements of an array of type <star>, based
// on some criteria.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

typedef struct{

    char Name[12];
    char Fam[15];
    unsigned long Tel;
}star;

void sort(byte*, int, int, int(*)());
int compare_Tel(byte*, byte*);

int main() {

    int i = 0;
    star Bel[5];

    while(i < 5){

        printf("Enter Name: ");
        scanf(" %s", Bel[i].Name);
        
        printf("Enter Fam: ");
        scanf(" %s", Bel[i].Fam);
        
        printf("Enter Tel: ");
        scanf(" %lu", &Bel[i].Tel);

        i++;
    }

    sort((byte*)Bel, 5, sizeof(star), compare_Tel);

    FILE* pf = fopen("Bel.txt", "w");
    if(!pf)
        return -1;

    for(i = 0; i < 5; i++)
        fprintf(pf, "%s\t%s\t%lu\n", Bel[i].Name, Bel[i].Fam, Bel[i].Tel);
    
    fclose(pf);
    return 0;
}

// Implementation of Bubble sort
void sort(byte* base, int size, int nbytes, int(*cmp)(byte* el1, byte* el2)) {

    int i, j, flag = 1;
    byte* help = (byte*)malloc(nbytes);
    if(!help)
        return;

    for(i = 0; flag; i++){

        for(j = 0, flag = 0; j < size - 1 - i; j++){

            if((*cmp)(base + j*nbytes, base + (j + 1)*nbytes)){

                memcpy(help, base + j*nbytes, nbytes);
                memcpy(base + j*nbytes, base + (j + 1)*nbytes, nbytes);
                memcpy(base + (j + 1)*nbytes, help, nbytes);
                flag = 1;
            }
        }
    }
    free(help);
}


int compare_Tel(byte* el1, byte* el2) {

    return *(unsigned long*)(el1 + 27) > *(unsigned long*)(el2 + 27) ? 1 : 0;
}