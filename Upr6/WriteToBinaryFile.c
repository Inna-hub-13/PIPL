
// Write an implementation of a function that takes a name of a file and an
// array of struct type.
// The function writes the data from the array to the file.

#include <stdio.h>
#define N 3

struct car{

    char model[15];
    char rnomer[9];
    float price;
};

int input(char*, struct car*, int);

int main() {

    struct car car1 = {"Ferarri\0", "PB2030CM\0", 450};
    struct car car2 = {"Jaguar\0", "CA2710XM\0", 550};
    struct car car3 = {"Bugatti\0", "CA4050SS\0", 850};

    struct car cars[N] = {car1, car2, car3};
    printf("input returned: %d\n", input("cars.bin", cars, N));

    return 0;
}

int input(char* namef, struct car* cars, int size) {

    FILE *pfile;
    pfile = fopen(namef, "wb");

    if(!pfile)
        return -1;
    
    fwrite(cars, sizeof(struct car), size, pfile);
    fclose(pfile);
    return 0;
}