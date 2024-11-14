
// There is a given text file, containig toto 6/49 bets.
// Write a function that takes as parameters file and six winning numbers.
// The function must return the number of wins.

// *assume all the numbers in the text file are separated by intervals
// *at least 3 matches gives a win

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill_arr_random(int*, int, int, int);
int count_winners(char*, int*, int);

int main() {

    char* file = "totobets.txt\0";
    int wins[6];
    fill_arr_random(wins, 6, 1, 49);

    int i;
    printf("Winning combo:\n");
    for(i = 0; i < 6; i++)
        printf("%d ", *(wins + i));
    printf("\n");

    printf("count_winners() returned: %d\n", count_winners(file, wins, 6));
    return 0;
}

void fill_arr_random(int* arr, int size, int min, int max) {

    srand(time(0));
    int i;

    for(i = 0; i < size; i++)
        *(arr + i) = rand() % (max - min + 1) + min;

}

int count_winners(char* filename, int* wins, int size) {

    FILE* pf = fopen(filename, "r");
    if(!pf)
        return -1;

    // num -> current number
    // nums_row -> numbers per row, only 6 a row, forming one bet
    // count_matches -> counts matches of numbers per row
    int num, nums_row = 0, count_matches = 0, winners = 0, i;

    while(fscanf(pf, "%d ", &num) > 0) {

        nums_row++;

        for(i = 0; i < size; i++)
            if(num == *(wins + i)){
                count_matches ++;
                break;
            }
        
        if(nums_row == 6) {

            if(count_matches >= 3)
                winners++;

            nums_row = 0;
            count_matches = 0;
        }
    }

    return winners;
}

