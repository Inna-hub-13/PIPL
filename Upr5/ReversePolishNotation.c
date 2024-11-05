
// Write an implementation of a function for 
// Reverse Polish Notation - a way of performing arithmetics

// Ex. 1 2 + 8 * = (1 + 2) * 8

// 5.11 2024 - only for digits

#include <stdio.h>
#include <stdlib.h>

struct stack{

    int num;
    struct stack* prev;
};

void push(struct stack**, int);
void pop(struct stack**, int*);
int perform_arithmetics(struct stack**, char*);

int main() {

    struct stack* top = NULL;
    char* ar_expression = "2 9 * 8 - 5 *\0";
    int res = perform_arithmetics(&top, ar_expression);
    printf("res: %d\n", res);

    return 0;
}

void push(struct stack** top, int n) {

    struct stack* el = (struct stack*)malloc(sizeof(struct stack));

    if(!el)
        return;
    
    el -> num = n;
    el -> prev = *top;
    *top = el;
    //printf("%d pushed to stack\n", el -> num);
}

void pop(struct stack** top, int* n) {

    if(!(*top)){
        printf("Stack is empty\n");
        return;
    }

    struct stack* temp = *top;
    *n = temp -> num;
    *top = temp -> prev;
    //printf("%d popped\n", temp -> num);
    free(temp);
}

// Implementation of Reverse Polish Notation
// Assume all of the operands and operators in <ar_expression> 
// are separated by intervals -> 1 5 * 2 +
int perform_arithmetics(struct stack** top, char* ar_expression) {

    while(*ar_expression) {

        int num1, num2;
        if(*ar_expression <= '9' && *ar_expression >= '0')
            push(top, (*ar_expression - '0'));

        // found arithmetic operation
        else if(*ar_expression != ' '){
            
            pop(top, &num2);
            pop(top, &num1);
            switch (*ar_expression) {

                case '+': 
                    push(top, num1 + num2);
                    break;
                case '-':
                    push(top, num1 - num2);
                    break;
                case '*': 
                    push(top, num1 * num2);
                    break;
                case '/':
                    push(top, num1 / num2);
                    break;
            }
        }

        ar_expression++;
    }

    return (*top) -> num;
}