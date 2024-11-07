
// Write a program, that generates binary file, which holds data 
// of type struct <stock>.

// Write a function, that takes as a parameter array of type struct <stock_count>, 
// and a file, that holds data - the name and price for the elements.
// The function must return total value of all elements in the array.

#include <stdio.h>
#include <string.h>
#define N 15

struct stock {

    char name[N];
    double price;
};

struct stock_count {

    char name[N];
    int count;
};

int input(char*);
double get_price(FILE*, struct stock_count*, int);

int main() {

    printf("input returned: %d\n", input("stock_price.bin"));

    FILE *pf = fopen("stock_price.bin", "rb");
    if(!pf)
        return -1;

    struct stock_count stocks[4];
    strcpy((*stocks).name, "Table");
    (*stocks).count = 20;
    strcpy((*(stocks + 1)).name, "Chair");
    (*(stocks + 1)).count = 5;
    strcpy((*(stocks + 2)).name, "Desk");
    (*(stocks + 2)).count = 5;
    strcpy((*(stocks + 3)).name, "Cupboard");
    (*(stocks + 3)).count = 10;

    double price = get_price(pf, stocks, 4);
    printf("price: %.2lf\n", price);

    fclose(pf);

    return 0;
}

int input(char* filename) {

    char ans;
    struct stock stock1;

    printf("Do you want to add a stock to a file (Y/N)? ");
    scanf(" %c", &ans);

    if(ans == 'Y'){

        FILE *pf = fopen(filename, "wb");

        if(!pf){

            printf("Cannot open file %s\n", filename);
            return -1;
        }
        
        while(ans == 'Y') {

            printf("Enter name of stock: ");
            scanf(" %s", stock1.name);
            printf("Enter price of stock: ");
            scanf(" %lf", &stock1.price);

            fwrite(&stock1, sizeof(struct stock), 1, pf);

            printf("Do you want to add a stock to a file (Y/N)? ");
            scanf(" %c", &ans);
        }

        fclose(pf);
        return 0;
    }

    return -1;
}

double get_price(FILE* pf, struct stock_count* arr, int size) {

    struct stock temp;
    int i;
    double total = 0;

    while(fread(&temp, sizeof(struct stock), 1, pf) > 0) {

        for(i = 0; i < size; i++)
            if(strcmp(temp.name, (*(arr + i)).name) == 0){
                
                total += (*(arr + i)).count * temp.price;
                break;
            }
    }

    return total;
}

