
// Write an implementation of a function that takes array of integers.
// The function returns an array of only the even numbers and the number
// of even numbers.

#include <stdio.h>
#include <stdlib.h>

int* evens(int*, int, int*);

int main() {

    int arr[] = {1, 10, 12, 2, 4, 24, 16, 23, 100, 14, 32, 9};
    int count, i;
    int* even = evens(arr, sizeof(arr) / sizeof(int), &count);

    for(i = 0; i < count; i++)
        printf("%d ", *(even + i));

    printf("\n");

    return 0;
}

int* evens(int* arr, int size_arr, int* count) {

    int* arr_even = (int*)malloc(size_arr * sizeof(int));

    if(!arr_even){

        *count = -1;
        return NULL;
    }

    int i, k;
    for(i = 0, k = 0; i < size_arr; i++)
        if(*(arr + i) % 2 == 0){
            *(arr_even + k) = *(arr + i);
            k++;
        }
    
    arr_even = (int*)realloc(arr_even, k * sizeof(int));

    *count = k;
    return arr_even;
}

