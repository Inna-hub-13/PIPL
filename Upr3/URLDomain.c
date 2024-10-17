
// Write a function that takes as a parameter
// string, which is a valid url address
// the function determines protocol, domain ...

//http://www.tu-plovdiv/students/grades/index.php?fac=fea;spec=cst;k=1

#include <stdio.h>
#include <stdlib.h>

struct par{

    char name[10];
    char val[10];
};

struct url {
    char prot[10];
    char dom[25];
    char dir[50];
    char php[25];
    struct par arr_params[10];
    int size;
};

void parse(char*, struct url*);

int main() {

    struct url* link1 = (struct url*)malloc(sizeof(struct url));
    parse("http://www.tu-plovdiv/students/grades/index.php?fac=fea;spec=cst;k=1;k=2\0", link1);
    return 0;
}

void parse(char* str, struct url* link) {

    int j, k;
    // keeps the address of the last '/' before '?'
    char * last_pos_address;
    for(j = 0; *str && *str != ':'; str++, j++)
        link -> prot[j] = *str;
    
     link -> prot[j] = '\0';

     str += 3;
     
     for(j = 0; *str && *str != '/'; str++, j++)
        link -> dom[j] = *str;

    link -> dom[j] = '\0';

    str++;

    for(j = 0; *str && *str != '?'; str++, j++){
        if(*str == '/')
            last_pos_address = str;
        link -> dir[j] = *str;  
    }
    // after the termination of this for loop, str is at '?'
    link -> dir[j - (str - last_pos_address) + 1] = '\0';

    // str = last_post_address -> str is palced at the beging of the php
    for(j = 0, str = last_pos_address + 1; *str && *str != '?'; str++, j++)
        link -> php[j] = *str;
    
    link -> php[j] ='\0';

    str++;

    for(k = 0; *str && *str != ';'; k++) {
        
        for(j = 0; *str && *str != '='; str++, j++)
            link -> arr_params[k].name[j] = *str;

        link -> arr_params[k].name[j++] = '=';
        link -> arr_params[k].name[j] = '\0';

        str++;

        for(j = 0; *str && *str != ';'; str++, j++)
            link -> arr_params[k].val[j] = *str;
        
        link -> arr_params[k].val[j] = '\0';
        str++;
    }

    link -> size = k ;

    printf("Protocol: %s\n", link -> prot);
    printf("Domain: %s\n", link -> dom);
    printf("Directories: %s\n", link -> dir);
    printf("Php: %s\n", link -> php);

    printf("Parameters: \n");
    for(j = 0; j < k; j++)
        printf("%s %s\n", link -> arr_params[j].name, link -> arr_params[j].val);
    
    printf("Number of parameters: %d\n", link -> size);

}