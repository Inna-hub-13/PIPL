
// Write a function that takes an array of complex numbers and returns address
// to the number with the smallest real part.

#include <stdio.h>

struct complex{

    float real;
    float imag;
};

struct complex* smallest_real(struct complex*, int);

int main() {

    struct complex complex1 = {1, 6};
    struct complex complex2 = {-1, 5};
    struct complex complex3 = {31, 5};
    struct complex complex4 = {-14, 15};
    struct complex complex5 = {21, 3};

    struct complex arr[5];
    arr[0] = complex1;
    arr[1] = complex2;
    arr[2] = complex3;
    arr[3] = complex4;
    arr[4] = complex5;

    struct complex* smallest = smallest_real(arr, 5);
    printf("smallest->real %.2f, smallest->imag %.2f\n", smallest -> real, smallest -> imag);

    return 0;
}

struct complex* smallest_real(struct complex* arr, int size) {

    int i = 1, min_index = 0;

    while(i < size) {

        if((*(arr + i)).real < (*(arr + min_index)).real)
            min_index = i;

        i++;
    }

    return arr + min_index;
}
