
// Assume we have a sorted array
// Write a program that adds a number to that array
// and returns the position of number

// *the array can be expanded

#include <stdio.h>
#define N 16

void print_arr(float*, int);
int get_pos(float*, float, int*);
void add_element(float*, float, int*, int);

int main() {

    float arr[N] = {2, 6, 7, 13, 18, 26};
    int size = 6;
    print_arr(arr, size);
    
    int pos = get_pos(arr, 9, &size);
    printf("At index %d\n", pos);
    printf("size = %d\n", size);
    print_arr(arr, size);

    return 0;
}

void print_arr(float* arr, int size) {

    for(int i = 0; i < size; i++)
        printf("%.2f ", *(arr + i));
    
    printf("\n");
}

int get_pos(float* arr, float num, int* size) {

    int index = 0;

    while(*(arr + index) < num && index < *size)
        index++;
    
    add_element(arr, num, size, index);
    
    return index;
}

void add_element(float* arr, float num, int* size, int pos) {

    // To add at the end
    if(pos > *size) {

        *(arr + *size) = num;
        (*size) ++;
        return;
    }

    for(int i = *size; i > pos; i--)
        *(arr + i) = *(arr + i - 1);
    
    *(arr + pos) = num;
    (*size) ++;
}