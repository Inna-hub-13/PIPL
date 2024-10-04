
// Assume we have an array 
// remove all occurences of number
// return the count of occurences of number

#include <stdio.h>
#define N 10

void print_arr(float*, int);
int remove_element(float*, float, int*);

int main() {

    float arr[N] = {2, 5, 8, 5, 5, 5, 16};
    int size = 7;
    print_arr(arr, size);

    int count = remove_element(arr, 5, &size);
    printf("count = %d\n", count);
    printf("size = %d\n", size);

    print_arr(arr, size);
    return 0;
}

void print_arr(float* arr, int size) {

    for(int i = 0; i < size; i++)
        printf("%.2f ", *(arr + i));
    
    printf("\n");
}

int remove_element(float* arr, float num, int* size) {
    
    int i, j;
    for(i = 0, j = 0; i < *size; i++){

        if(*(arr + i) != num){

            *(arr + j) = *(arr + i);
            j++;
        }
    }

    (*size) = j;
    return i - j;
}