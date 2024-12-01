
// Write a function that finds the second largest element in an array,
// without using the largest!!!

#include <stdio.h>

int second_largest(int*, int);

int main() {

    int arr[] = {7, 24, 26, 116, 16, 10, 12};
    int size = sizeof(arr)/sizeof(int);

    int sl = second_largest(arr, size);
    printf("Second largest: %d\n", sl);

    return 0;
}

int second_largest(int* arr, int size) {

    int i, j, temp;

    // Let's implement Bubble sort only to find the two largest elements
    for(i = 0; i < 2; i++)
        for(j = 0; j < size - 1 - i; j++)
            if(*(arr + j) > *(arr + j + 1)){

                temp = *(arr + j + 1);
                *(arr + j + 1) = *(arr + j);
                *(arr + j) = temp;
            }
    return *(arr + size - 2);
}