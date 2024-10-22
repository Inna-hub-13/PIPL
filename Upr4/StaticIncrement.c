
// Experiment static and auto variables

#include <stdio.h>

void increment_static();
void increment_auto();

int main() {

    int i;
    for(i = 1; i < 4; i++) {

        printf("Invokation %d\n", i);
        increment_static();
        increment_auto();
    }

    return 0;
}

void increment_static() {

    static int a = 1;
    a++;
    printf("increment_static a: %d\n", a);
}

void increment_auto() {

    int b = 1;
    b++;
    printf("increment_auto b: %d\n", b);
}

