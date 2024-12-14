
// Write a fcuntion that sorts an array of sturct Book

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

struct Book{

    char ISBN[14];
    char BookName[20];
    int Year;
    char Publisher[15];
};

int cmp_year(byte*, byte*);
void BubbleSort(byte*, int, int, int(*)());

int main() {

    struct Book* arr = (struct Book*)calloc(10, sizeof(struct Book));
    if(!arr)
        return -1;

    char ans = 'Y';
    int i = 0, j;
    struct Book temp;

    do{
        printf("ISBN: ");
        scanf(" %[^\n]s", temp.ISBN);
        printf("BookName: ");
        scanf(" %[^\n]s", temp.BookName);
        printf("Year: ");
        scanf(" %d", &temp.Year);
        printf("Publisher: ");
        scanf(" %[^\n]s", temp.Publisher);
        *(arr + i) = temp;
        printf("Do you want to add more books Y/N: ");
        scanf(" %c", &ans);
        i++;
    }while(ans == 'Y' && i < 10);

    for(j = 0; j < i; j++)
        printf("\nISBN: %s\nBookName: %s\nYear: %d\nPublisher: %s\n", (arr + j),
        (arr + j)->BookName, (arr + j)->Year, (arr + j)->Publisher);
    
    BubbleSort((byte*)arr, i, sizeof(struct Book), cmp_year);

    
    for(j = 0; j < i; j++)
        printf("\nISBN: %s\nBookName: %s\nYear: %d\nPublisher: %s\n", (arr + j),
        (arr + j)->BookName, (arr + j)->Year, (arr + j)->Publisher);

    return 0;
}

int cmp_year(byte* el1, byte*  el2) {

    return *(int*)(el1 + 34) > *(int*)(el2 + 34) ? 1 : 0;
}

void BubbleSort(byte* base, int nrec, int reclen, int(*cmp)(byte*, byte*)){

    int i, j, flag = 1;
    byte* temp = (byte*)malloc(reclen);
    if(!temp)
        return;
    
    for(i = 0; flag; i++) {

        flag = 0;
        for(j = 0; j < nrec - 1 - i; j++){

            if((*cmp)(base + j*reclen, base + (j + 1)*reclen)){

                memcpy(temp, base + j*reclen, reclen);
                memcpy(base + j*reclen, base + (j + 1)*reclen, reclen);
                memcpy(base + (j + 1)*reclen, temp, reclen);
                flag = 1;
            }
        }
    }

    free(temp);
}


