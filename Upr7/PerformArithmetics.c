
// There is a given text file, 
// that contains arithmetic expressions in Reverse Polish Notation.
// *assume the operands are separated by intervals

//  Write a function, that perfoms arithmetics

// 12.11 2024 - needs upgrade

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {

    int num;
    struct stack* prev;
};

int push(struct stack**, int);
int pop(struct stack**, int*);
void print_stack(const struct stack*);
int calculate(char*, struct stack**, int*);
int parse(char*);
int power(int, int);

int main() {

    struct stack* top = NULL;
    char* file = "expressions.txt\0";
    int res = 0;
    printf("calculate() returned: %d\n", calculate(file, &top, &res));
    printf("res: %d\n", res);

    return 0;
}

int push(struct stack** top, int num) {

    struct stack* temp = (struct stack*)malloc(sizeof(struct stack));
    if(!temp)
        return -1;
    
    temp -> num = num;
    temp -> prev = *top;
    *top = temp;
    return 0;
}

int pop(struct stack** top, int* num) {

    if(!(*top))
        return -1;
    
    struct stack* temp = *top;
    *num = temp -> num;
    *top = (*top) -> prev;
    free(temp);
    return 0;
}

void print_stack(const struct stack* top) {

    for(;top; top = top -> prev)
        printf("%d\n", top -> num);
    
    printf("\n");
}

int power(int a, int x) {

    int i = 1;
    for(;x >= 1; x--)
        i *= a;
    
    return i;
}

int parse(char* str_num) {

    int num = 0, size = 0;

    while(*(str_num + size))
        size++;
    
    size -= 1;
    while(size > -1) {

        num += (*str_num - '0') * power(10, size);
        size--;
        *str_num++;
    }
    return num;
}

int calculate(char* filename, struct stack** top, int *res) {

    FILE* pf;
    pf = fopen(filename, "r");
    if(!pf)
        return -1;
    
    char temp[15];
    int num1, num2;

    while(!feof(pf)) {

        fscanf(pf, "%s ", temp);

        if(strcmp(temp, "=") == 0)
            pop(top, res);
    
        
        if(strcmp(temp, "+") == 0 || strcmp(temp, "-") == 0 || 
                strcmp(temp, "*")  == 0 || strcmp(temp, "/") == 0) {
            
            pop(top, &num1);
            pop(top, &num2);

            // *temp -> gives the first character, which is the operator
            switch(*temp) {
                case '+' : push(top, num1 + num2);
                break;
                case '-' : push(top, num2 - num1);
                break;
                case '*' : push(top, num1 * num2);
                break;
                case '/' : push(top, num2 / num1);
                break;
            }
        }

        else {

            num1 = parse(temp);
            push(top, num1);
        }
    }

    fclose(pf);
    return 0;
}

