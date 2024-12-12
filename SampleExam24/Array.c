
// Write a function that takes as parameters an array of numbers and a number
// The fuction shortens the array, it removes all numbers bigger than the passed one
// The function must return the size of the new array and the number of
// removed elements

// *do not use additional array

#include <stdio.h> 

int shorten(int*, int, int, int*);

int main() {

    int arr[] = {12, 1, 2, 45, 6, 78, 90, 13, 10};
    int size, n_size, removed, i;
    size = sizeof(arr)/sizeof(int);

    for(i = 0; i < size; i++)
        printf("%d ", *(arr + i));
    printf("\n");

    removed = shorten(arr, size, 40, &n_size);
    printf("removed: %d\n", removed);

    for(i = 0; i < n_size; i++)
        printf("%d ", *(arr + i));
    printf("\n");

    return 0;
}

int shorten(int* arr, int size, int num, int* n_size) {

    int i, count = 0;

    for(i = 0; i < size; i++)
        if(*(arr + i) < num){

            *(arr + count) = *(arr + i);
            count++;
        }
    
    *n_size = count;
    return size - count;
}

