
// Write a function, that takes a string <text> and a string <key> for encoding.
// The function must encode the text via simple summing, where each character
// in the encoded string is a sum of the chars at given pos of text and key.

// Write a reverse, decoding function.

// Write a function that reads from given text file and
// creates an encoded file.

#include <stdio.h>
#include <string.h>

int en_sum(int, int);
int de_sub(int, int);
void encode_decode(char*, char*, int(*)(int, int));
int encode_decode_file(char*, char*, char*, char);

int main() {

    char key[20];
    strcpy(key, "tikva");

    char f1[20];
    char f2[20];
    char f3[20];
    strcpy(f1, "text.txt");
    strcpy(f2, "code.txt");
    strcpy(f3, "decode.txt");

    printf("encode_decode_file() returned: %d\n", encode_decode_file(f1, f2, key, 'E'));
    printf("encode_decode_file() returned: %d\n", encode_decode_file(f2, f3, key, 'D'));

    return 0;
}

int en_sum(int ch1, int ch2) {

    return ch1 + ch2;
}

int de_sub(int ch1, int ch2) {

    return ch1 - ch2;
}

void encode_decode(char* text, char* key, int(*op)(int ch1, int ch2)) {
    
    int i, j;

    for(i = 0, j = 0; *(text + i); i++){

        if(*(key + j)){

            *(text + i) = op(*(text + i), *(key + j));
            j++;
        }
        else{

            j = 0;
            *(text + i) = op(*(text + i), *(key + j));
        }
    }
}

int encode_decode_file(char* f_read, char* f_write, char* key, char mode) {

    FILE* pf1;
    pf1 = fopen(f_read, "r");
    if(!pf1)
        return -1;
    
    FILE* pf2;
    pf2 = fopen(f_write, "w");
    if(!pf2){

        fclose(pf1);
        return -1;
    }

    char buffer[1025];
    if(mode == 'E'){

        while(fscanf(pf1, "%1024[^\n]\n", buffer) > 0) {

            encode_decode(buffer, key, en_sum);
            fprintf(pf2, "%s\n", buffer);
        }
    }
    else if(mode == 'D'){

        while(fscanf(pf1, "%1024[^\n]\n", buffer) > 0){

            encode_decode(buffer, key, de_sub);
            fprintf(pf2, "%s\n", buffer);
        }
    }
    else{

        fclose(pf1);
        fclose(pf2);
        return -1;
    }

    fclose(pf1);
    fclose(pf2);
    return 0;
}
