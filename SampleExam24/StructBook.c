
// Write a function that takes as parametres array of type Book, number of elements
// and year
// The function adds to a dynamically allocated array the books, published that year
// It returns the array and number of records

#include <stdio.h>
#include <stdlib.h>

struct Book{

    char ISBN[10];
    char BookName[15];
    int Year;
    char Publisher[15];
};

struct Book* year_books(struct Book*, int, int, int*);

int main() {

    struct Book arr[10];
    struct Book temp;

    int i, size;
    for(i = 0; i < 3; i++){

        printf("ISBN: ");
        scanf(" %s", temp.ISBN);
        printf("BookName: ");
        scanf(" %s", temp.BookName);
        printf("Year: ");
        scanf(" %d", &temp.Year);
        printf("Publisher: ");
        scanf(" %s", temp.Publisher);
        *(arr + i) = temp;
    }

    struct Book* books = year_books(arr, 3, 2024, &size);
    for(i = 0; i < size; i++)
        printf("BookName: \"%s\" Year: %d\n", (books + i) ->BookName, (books + i) ->Year);

    return 0;
}

struct Book* year_books(struct Book* arr, int size, int year, int* n_size) {

    int i, j, count = 0;

    for(i = 0; i < size; i++)
        if((arr + i) -> Year == year)
            count++;

    struct Book* books_year = (struct Book*)calloc(count, sizeof(struct Book));
    if(!books_year)
        return NULL;

    for(i = 0, j = 0; i < size; i++)
        if((arr + i) -> Year == year){

            *(books_year + j) = *(arr + i);
            j++;
        }
    
    *n_size = count;
    return books_year;
}
