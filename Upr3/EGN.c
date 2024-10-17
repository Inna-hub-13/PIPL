
// Write a function that takes as a parameter 
// a valid egn of a Bulgarian citizen

// The function must print
// 1) the date of birth
// 2) the region of birth
// 3) the sex

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* get_region(int);
char* birth_date(char*);
void print_egn_info(char*);

int main() {

    char egn1[11];
    printf("Enter egn: ");
    scanf("%s", egn1);

    char egn2[11] = {'0', '0','4', '5','1', '0','2', '7','9', '6',0 };
    char egn3[11] = {'6', '7','0', '1','1', '0','6', '7','6', '6', 0};
    
    print_egn_info(egn1);
    print_egn_info(egn2);
    print_egn_info(egn3);

    return 0;
}

// YYMMDDOOPK - 9609134577
// YY - last two digits of birth year
// MM - month -> MM + 20 before 1900, MM from 1900 to 1999, MM + 40 from 2000 to 2999
// DD - date of birth
// OO - region
// P - sex -> odd for female, even for male
// K - random value

char* get_region(int r) {

    // some regions are intentionally left out
    char* region = (char*)malloc(20*sizeof(char));

    if(!region)
        return NULL;

    if(r <= 43)
        strcpy_s(region, 20, "Blagoevgrad");
    else if(r <= 93)
        strcpy_s(region, 20, "Burgas");
    else if(r <= 139)
        strcpy_s(region, 20, "Varna");
     else if(r <= 169)
        strcpy_s(region, 20, "Veliko Tarnovo");
    else if(r <= 182)
        strcpy_s(region, 20, "Vidin");
     else if(r <= 217)
        strcpy_s(region, 20, "Vratza");
    else if(r <= 233)
        strcpy_s(region, 20, "Gabrovo");
     else if(r <= 281)
        strcpy_s(region, 20, "Kardzhali");
    else if(r <= 301)
        strcpy_s(region, 20, "Kyostendil");
     else if(r <= 319)
        strcpy_s(region, 20, "Lovech");
    else if(r <= 341)
        strcpy_s(region, 20, "Montana");
     else if(r <= 377)
        strcpy_s(region, 20, "Pazardjik");
    else if(r <= 395)
        strcpy_s(region, 20, "Pernik");
     else if(r <= 435)
        strcpy_s(region, 20, "Pleven");
    else if(r <= 501)
        strcpy_s(region, 20, "Plovdiv");
    else
        strcpy_s(region, 20, "Unidentified");
    
    return region;
}

char* birth_date(char* egn) {
    
    // date in fromat 23.02 1983
    char* birth_date = (char*) malloc(11 * sizeof(char));

    if(!birth_date)
        return NULL;
    
    // 1900 - 1999
    if(*(egn + 2) == '0'){
        *(birth_date + 3) = '0';
        *(birth_date + 6) = '1';
        *(birth_date + 7) = '9';
    }
    else if(*(egn + 2) == '1'){
        *(birth_date + 3) = '1';
        *(birth_date + 6) = '1';
        *(birth_date + 7) = '9';
    }
    // 1800 - 1900
    else if(*(egn + 2) == '2'){
        *(birth_date + 3) = '0';
        *(birth_date + 6) = '1';
        *(birth_date + 7) = '8';
    }
    else if(*(egn + 2) == '3'){
        *(birth_date + 3) = '1';
        *(birth_date + 6) = '1';
        *(birth_date + 7) = '8';
    }
    // 2000 - 2099
    else if(*(egn + 2) == '4'){
        *(birth_date + 3) = '0';
        *(birth_date + 6) = '2';
        *(birth_date + 7) = '0';
    }
    else if(*(egn + 2) == '5'){
        *(birth_date + 3) = '1';
        *(birth_date + 6) = '2';
        *(birth_date + 7) = '0';
    }

    *(birth_date) = *(egn + 4);
    *(birth_date + 1) = *(egn + 5);
    *(birth_date + 2) = '.';
    *(birth_date + 4) = *(egn + 3);
    *(birth_date + 5) = ' ';
    *(birth_date + 8) = *(egn);
    *(birth_date + 9) = *(egn + 1);
    *(birth_date + 10) = 0;

    return birth_date;
}

void print_egn_info(char* egn) {
    
    char sex[7];

    // determine sex
    if((*(egn + 8) - '0') % 2 == 0)
        strcpy_s(sex, 7, "male");
    else
        strcpy_s(sex, 7, "female");

    int r = (*(egn + 6) - '0') * 100 + (*(egn + 7) - '0') * 10 + (*(egn + 8) - '0');

    printf("\n");
    printf("egn: %s\n", egn);
    printf("Birth date: %s\n", birth_date(egn));
    printf("Sex: %s\n", sex);
    printf("Region: %s\n", get_region(r));
}
