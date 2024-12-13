
// Write a function that sorts an array of complex numbers ascending
// The function compares the sum of the real and imaginary part

//*use BubbleSort

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

struct Complex{

    int real;
    int imag;
};

int cmp1(byte*, byte*);
void BubbleSort(byte*, int, int, int(*)());

int main() {

    struct Complex arr[10];
    struct Complex temp;
    char ans = 'Y';
    int i = 0, j;

    do{
        printf("real: ");
        scanf(" %d", &temp.real);
        printf("imag: ");
        scanf(" %d", &temp.imag);
        printf("Y/N: ");
        scanf(" %c", &ans);
        arr[i] = temp;
        i++;
    }while(ans == 'Y' && i < 10);

    for(j = 0; j < i; j++)
        printf("real: %d, imag: %d\n", (arr + j)->real, (arr+ j)->imag);
    
    BubbleSort((byte*)arr, i, 8, cmp1);

    printf("\n");
    for(j = 0; j < i; j++)
        printf("real: %d, imag: %d\n", (arr + j)->real, (arr+ j)->imag);

    return 0;
}

int cmp1(byte* el1, byte* el2) {

    int sum1 = *(int*)(el1) + *(int*)(el1 + sizeof(int));
    int sum2 = *(int*)(el2) + *(int*)(el2 + sizeof(int));

    return sum1 > sum2 ? 1 : 0;
}

void BubbleSort(byte* base, int nrec, int reclen, int(*cmp)(byte* el1, byte* el2)){
    
    int i, j, flag = 1;
    byte* temp = (byte*)calloc(reclen, 1);
    if(!temp)
        return;

    for(i = 0; flag; i++){

        flag = 0;
        for(j = 0; j < nrec - 1 - i; j++){

            if((*cmp)(base + j*reclen, base + (j+1)*reclen)){
                
                memcpy(temp, base + j*reclen, reclen);
                memcpy(base + j*reclen, base + (j+1)*reclen, reclen);
                memcpy(base + (j+1)*reclen, temp, reclen);
                flag = 1;
            }
        }
    }
    free(temp);
}

