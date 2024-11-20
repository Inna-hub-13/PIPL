
// Write a program that compresses a number in hexadecimal
// Every two digits in hex should be placed in one byte
// A -> 1010, F -> 1111 --> AF 10101100

#include <stdio.h>
#include <stdlib.h>

typedef struct{

    unsigned count:10;
    unsigned sum:22;
}Head;

typedef struct{

    Head head;
    unsigned char data[1024];
}Pac;

int compress(Pac*, char*);
int decompress(Pac*, char*);

int main() {

    Pac* pac = (Pac*)malloc(sizeof(Pac));
    if(!pac)
        return -1;

    char* hex = "AB49C8\0";
    printf("compress() returned: %d\n", compress(pac, hex));

    char* dhex = (char*)malloc(25*sizeof(char));
    if(!dhex)
        return -1;

    printf("decompress() returned: %d\n", decompress(pac, dhex));
    printf("dhex: %s\n", dhex);

    return 0;
}

int compress(Pac* pac, char* hex) {

    int i, c1, c2;
    pac -> head.sum = 0;

    for(i = 0; *(hex + i);) {

        // firstly, convert the characters to integers
        c1 = *(hex + i);
        if(c1 >= 'A' && c1 <= 'F')
            c1 = c1 - 'A' + 10;
        else if(c1 >= '0' && c1 <= '9')
            c1 = c1 - '0';
        else
            return -1;
        
        if(*(hex + i + 1) == 0){

            c2 = 0;
            i++;
        }

        else{

            c2 = *(hex + i + 1);
            if(c2 >= 'A' && c2 <= 'F')
                c2 = c2 - 'A' + 10;
            else if(c2 >= '0' && c2 <= '9')
                c2 = c2 - '0';
            else
                return -1;
        }

        pac -> data[i/2] = (c1<<4) | c2;
        pac -> head.sum += pac -> data[i/2];
        if(c1 && c2)
            i+=2;
    }

    pac -> head.count = i;
    return i;
}

int decompress(Pac* pac, char* hex) {

    int i, c1, c2, sum = 0;

    for(i = 0; i < pac->head.count; i += 2) {
        
        sum += pac -> data[i/2];
        c1 = (pac -> data[i/2] >> 4) & 0xF;
        c2 = (pac -> data[i/2]) & 0xF;

        if(c1 >= 10)
            c1 = c1 + 'A' - 10;
        else
            c1 = c1 + '0';
        
        if(c2 >= 10)
            c2 = c2 + 'A' - 10;
        else if(c2 != 0)
            c2 = c2 + '0';
        else
           c2 = 0; 
        
        *(hex + i) = c1;
        *(hex + i + 1) = c2;
    }

    // for even amount of digits '\0' is not added to the end of hex in for
    if(pac->head.count % 2 == 0)
        *(hex + i) = 0;
    
    if((sum & 0x3FFFFF) == pac -> head.sum)
        return pac -> head.sum;
    
    return -1;
}


