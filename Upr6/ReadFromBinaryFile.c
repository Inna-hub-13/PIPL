
// Write an implementation of a function that takes a pointer to a file.
// The function reads that file and returns the number of read elements.

#include <stdio.h>
#include <stdlib.h>

// 5.11 2024 - last element read twice!!! Needs to be fixed
// 7.11 2024 - problem fixed
// Caused by feof function in while loop, replaced by -> fread(&car, sizeof(struct car), 1, pF) > 0

struct car{

    char model[15];
    char rnomer[9];
    float price;
};

struct stack{

    struct car car;
    struct stack* prev;
};

int push(struct stack**, struct car*);
//int pop(struct stack**);
void print_stack(const struct stack*);
int output(FILE*, struct stack**);

int main() {
    
    struct stack* top = NULL;

    FILE* pF;
    pF = fopen("C:\\Personal\\University\\PIPL\\Upr6\\cars.bin", "rb");

    if(!pF)
        printf("File cannot open\n");

    else{

        int counted = output(pF, &top);
        printf("Count elements read: %d\n", counted);
        print_stack(top);
    }
    
    fclose(pF);

    return 0;
}

int push(struct stack** top, struct car* car) {

    struct stack* el = (struct stack*)malloc(sizeof(struct stack));

    if(!el)
        return -1;
    
    el -> car = *car;
    el -> prev = *top;
    *top = el;
    return 0;
}

/*int pop(struct stack** top) {

    if(!(*top))
        return -1;
    
    struct stack* temp = *top;
    *top = (*top) -> prev;
    free(temp);
    return 0;
}*/

void print_stack(const struct stack* top) {

    for(;top; top = top -> prev)
        printf("model - \"%s\", rnomer - %s, price - %lf\n", top -> car.model, 
                    top -> car.rnomer, top -> car.price);
}

int output(FILE* pF, struct stack** top) {

    struct car car;
    int k = 0;

    while(fread(&car, sizeof(struct car), 1, pF) > 0) {

        push(top, &car);
        k++;
    }

    return k;
}
