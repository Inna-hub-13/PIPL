#include <stdio.h>
#include <stdlib.h>

#define R 3

void print_arr(int*, int);
void print_matrix(int* [], int, int);

int main() {

    int* m[R];
    for(int i = 0; i < R; i++)
        m[i] = (int*)malloc(4 * sizeof(int));
    
    
    for(int i = 0; i < R; i++)
        for(int j = 0; j < 4; j++)
            m[i][j] = 10;

    print_matrix(m, R, 4);
    return 0;
}

void print_arr(int* arr, int  size){

    for(int i = 0; i < size; i++)
        printf("%d ", *(arr + i));
    
    printf("\n");
}

void print_matrix(int* m[], int r, int c) {

    for(int i = 0; i < r; i++){

        for(int j = 0; j < c; j++)
            printf("%d ", *(*(m + i) + j));

        printf("\n");
    }
    printf("\n");
}