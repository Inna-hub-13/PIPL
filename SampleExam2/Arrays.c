
// Funnction takes two arrays, one with <size> and the other <2*size>.
// For every element of the smaller array add the sum of two elements of 
// the bigger array.

#include <stdio.h>

void to_sum(int*, int*, int);

int main() {

    int big[10] = {1, 2, 1, 2, -1, 2, 3, 4, 13, 11};
    int small[5] = {0,0,0,0,0};

    int i;
    for(i = 0; i < 10;i++)
        printf("%d ", *(big + i));
    
    printf("\n");
    to_sum(big, small, 10);
    for(i = 0; i < 5;i++)
        printf("%d ", *(small + i));

    return 0;
}

void to_sum(int* big, int* small, int size_big) {

    int i;
    for(i = 0; i < size_big; i += 2)
        *(small + i / 2) = *(big + i) + *(big + i + 1);
    
}

