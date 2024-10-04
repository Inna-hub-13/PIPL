
// Assume we have an array of integers
// write a program that returns the address
// of the first element that can be
// divided by its index

#include <stdio.h>
#define N 10

void print_arr(int*, int);
int* get_address(int*, int);

int main() {

    int arr[N] = {1, 10, 5, 17, 19, 7, 61, 13, 11, 81};
    print_arr(arr, N);
    int* p_a = get_address(arr, N);

    for(int i = 0; i < N; i++)
        printf("%d - %p\n", i, (arr + i));
    
    printf("\np = %p\n", p_a); 
    return 0;
}

void print_arr(int* arr, int size) {

    for(int i = 0; i < size; i++)
        printf("%d ", *(arr + i));
    
    printf("\n");
}

int* get_address(int* arr, int size) {

    // i = 2 -> all numbers are divided by 1 and none by 0
    for(int i = 2; i < size; i ++) 
        if(*(arr + i) % i == 0)
            return (arr + i);
    

    return NULL;
}
