
// Write a function that takes as a parameter array and a number
// The function must shorten the array by removing the elements equal to the number
// The fuction must return the size of the new array and the number of removed elements

#include <stdio.h>

int shorten(int*, int, int, int*);

int main() {

    int arr[] = {12, 6, 7, 2, 2, 8, 8, 9, 9, 1, 9, 2, 2, 21};

    int size, i, size_n, r;
    size = sizeof(arr)/sizeof(int);

    size_n = shorten(arr, size, 2, &r);

    for(i = 0; i < size_n; i++)
        printf("%d ", *(arr + i));

    printf("\nremoved: %d\n", r);
    
    return 0;
}

int shorten(int* arr, int size, int numb, int* removed) {

    int i, count = 0;

    for(i = 0; i < size; i++)
        if(*(arr + i) != numb){

            *(arr + count) = *(arr + i);
            count++;
        }

    *removed = size - count;
    return count;
}
