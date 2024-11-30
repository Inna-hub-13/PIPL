
// Write a function that writes to a binary file data of type struct <car>.

// Write a function that takes a string parameter, date in format <yyyy.mm.dd>,
// and a pointer to a binary file. The function must print all register plates
// of the cars with expired vinetka.

#include <stdio.h>
#include <stdlib.h>

typedef struct{

    char reg_plate[9];
    char date[11];
    float price;
}car;

int write(char*, car*, int);
void read(char*);
void expired_vinetka(FILE*, char*);

int main() {
    
    char* name = "cars.bin\0";
    int n, i;
    printf("How many cars do you want to add: ");
    scanf(" %d", &n);

    car* cars = (car*)malloc(n * sizeof(car));
    if(!cars)
        return -1;

    for(i = 0; i < n; i++){

        printf("Enter register plate: ");
        scanf(" %s", (cars + i)->reg_plate);
        printf("Enter date: ");
        scanf(" %s", (cars + i)->date);
        printf("Enter price: ");
        scanf(" %f", &(cars + i)->price);
    }

    printf("write() returned: %d\n", write(name, cars, n));

    read(name);
    FILE* pf = fopen(name, "rb");
    if(!pf)
        return -1;
    
    expired_vinetka(pf, "2024.11.30\0");
    fclose(pf);
    return 0;
}

int write(char* file_name, car* arr, int size) {

    FILE* pf = fopen(file_name, "wb");
    if(!pf)
        return -1;
    
    fwrite(arr, sizeof(car), size, pf);
    fclose(pf);
    return 0;
}

void read(char* file_name) {

    FILE* pf = fopen(file_name, "rb");
    if(!pf)
        return;

    car buffer;
    while(fread(&buffer, sizeof(car), 1, pf))
        printf("%s %s %.2f\n", buffer.reg_plate, buffer.date, buffer.price);
    
    fclose(pf);
}

void expired_vinetka(FILE* pf, char* today) {

    car buffer;
    int i;
    printf("Expired: \n");
    while(fread(&buffer, sizeof(car), 1, pf)){

        i = 0;
        while(*(today + i) == buffer.date[i] && *(today + i))
            i++;

        if(*(today + i))
            if(*(today + i) > buffer.date[i])
                printf("%s\n", buffer.reg_plate);
    }
}