
// Write a function that takes as parameters array of numbers and its size
// The function must shorten the array by removing all the even numbers and 0
// The function must return the size of the new array

#include <stdio.h>

int shorten(int*, int);

int main(){

    int arr[] = {10, 7, 0, 0, 8, 6, 41, 0, 0, 13, 15};

    int i, size, size_n;
    size = sizeof(arr)/sizeof(int);
    size_n = shorten(arr, size);
    
    printf("size_n = %d\n", size_n);
    for(i = 0; i < size_n; i++)
        printf("%d ", *(arr + i));
    printf("\n");
    return 0;
}

int shorten(int* arr, int size) {

    int i, j;
    for(i = 0, j = 0; i < size; i++)
        if(*(arr + i) % 2 != 0){
            *(arr + j) = *(arr + i);
            j++;
        }

    return j;
}
