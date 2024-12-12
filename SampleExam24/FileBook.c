
// In a binary file is stored data in form struct Book
// Write a function that reads the file and returns the number of books
// by a given publisher

#include <stdio.h>
#include <string.h>

struct Book{

    char ISBN[10];
    char BookName[15];
    int Year;
    char Publisher[15];
};

int BookCounter(FILE*, char*);

int main() {

    struct Book temp;
    char ans = 'Y';
    int count = 0;

    FILE* pf;
    FILE* InStream;

    pf = fopen("books.bin", "wb");
    if(!pf)
        return -1;

    do{
        printf("ISBN: ");
        scanf(" %s", temp.ISBN);
        printf("BookName: ");
        scanf(" %[^\n]s", temp.BookName);
        printf("Year: ");
        scanf(" %d", &temp.Year);
        printf("Publisher: ");
        scanf(" %[^\n]s", temp.Publisher);
        fwrite(&temp, sizeof(struct Book), 1, pf);
        printf("Do you want to add more books? Y/N: ");
        scanf(" %c", &ans);
    }while(ans == 'Y');

    InStream = fopen("books.bin", "rb");
    count = BookCounter(InStream, "Debelqnov\0");

    printf("count = %d\n", count);
    fclose(pf);
    fclose(InStream);
    return 0;
}

int BookCounter(FILE* InStream, char* Publisher) {

    int count = 0;
    struct Book temp;

    while(fread(&temp, sizeof(struct Book), 1, InStream) > 0)
        if(strcmp(temp.Publisher, Publisher) == 0)
            count++;

    return count;
}
