
// Write an implementation of a stack, that holds
// dynamically allocated strings

#include <stdio.h>
#include <stdlib.h>

struct strStack{

    char* word;
    struct strStack* prev;
};

char* copy_str(char*);
int get_size(char*);

int push(struct strStack**, char*);
int pop(struct strStack**);
void print_stack(const struct strStack*);

int main() {

    struct strStack* top = NULL;

    push(&top, "leaves\0");
    push(&top, "pumpkin\0");
    push(&top, "tea\0");
    push(&top, "scarry\0");

    printf("\n");
    print_stack(top);
    printf("\n");
    while(top)
        pop(&top);


    return 0;
}


int get_size(char* str) {

    int size = 0;

    while(*(str + size))
        size++;

    return size;
}

// helper function that creates a dynamically allocated array of characters
// copiest str to it and returns the address to the first character of the sequence
char* copy_str(char* str) {

    int size = get_size(str);

    char* str_copy = (char*)malloc((size + 1) * sizeof(char));
    if(!str_copy)
        return NULL;
    
    int i;
    for(i = 0; i < size; i++)
        *(str_copy + i) = *(str + i);
    
    *(str_copy + i) = 0;
    return str_copy;
}

int push(struct strStack** top, char* str) {

    struct strStack* p = (struct strStack*)malloc(sizeof(struct strStack));
    // unsuccessful allocation
    if(!p)
        return -1;
    
    p -> word = copy_str(str);
    p -> prev = *top;
    *top = p;
    printf("\"%s\" successfully added to stack\n", p -> word);
    return 0;
}

int pop(struct strStack** top) {

    if(!(*top)) {

        printf("Stack is empty\n");
        return -1;
    }

    struct strStack* temp = *top;
    *top = (*top) -> prev;
    printf("\"%s\" popped out of stack\n", temp -> word);
    free(temp);
    return 0;
}

void print_stack(const struct strStack* top) {

    for(;top; top = top -> prev)
        printf("\"%s\"\n", top -> word);

}
