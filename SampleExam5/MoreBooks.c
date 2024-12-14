
// There is data saved about books in a binary file
// Write a function that takes as parameteres pointer to input stream and a year
// The function must return the number of books after that year

#include <stdio.h>

struct Book{

    char ISBN[14];
    char BookName[30];
    int Year;
    char Publisher[25];
};

int BookCounter(FILE*, int);

int main() {

    FILE* pf, *InStream;

   /* pf = fopen("book.bin", "wb");
    if(!pf)
        return -1;

    struct Book temp;
    char ans = 'Y';

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
    }while(ans == 'Y');*/

    InStream = fopen("book.bin", "rb");
    if(!InStream)
        return -1;

    int count_books = BookCounter(InStream, 2011);

    printf("count_books: %d\n", count_books);

    //fclose(pf);
    fclose(InStream);

    return 0;
}

int BookCounter(FILE* InStream, int year) {

    struct Book temp;
    int count = 0;

    while(fread(&temp, sizeof(struct Book), 1, InStream) > 0)
        if(temp.Year > year)
            count++;
    
    return count;
}