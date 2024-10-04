
// Assume we have a square matrix
// 1) find the sum under and over the main diagonal (sum1) 
// sum1 > sum2 return 1, sum1 < sum2 return -1, sum1 = sum2 return 0

// Assumme the square matrix is divdided by both diagonals into four triangles
// 2) print elements
// 2.1 top triangle
// 2.2 bottom triangle
// 2.3 left triangle 
// 2.1 right triangle

#include <stdio.h>
#define S 5

void print_matrix(int[][S], int, int);

// these fuctions are only for square matrices
int sum_under_main_diagonal(int[][S], int);
int sum_over_main_diagonal(int[][S], int);
int evaluate_sums(int[][S], int);
void print_top(int[][S], int);
void print_bottom(int[][S], int);
void print_left(int[][S], int);
void print_right(int[][S], int);

int main() {

    int m[S][S] = {
        {1, 2, 3, 5, 6},
        {11, 12, 13, 15, 16},
        {2, 4, 6, 8, 10},
        {1, 3, 5, 7, 9},
        {10, 1, 0, 100, 1}
    };

    print_matrix(m, S, S);
    printf("sum under = %d\n", sum_under_main_diagonal(m, S));
    printf("sum over = %d\n", sum_over_main_diagonal(m, S));

    int var1 = evaluate_sums(m, S);
    printf("After evaluation of sums var1 = %d\n", var1);

    print_top(m, S);
    print_left(m, S);
    print_bottom(m, S);
    print_right(m, S);
    return 0;
}

void print_matrix(int matrix[][S], int r, int c) {

    for(int i = 0; i < r; i++){

        for(int j = 0; j < c; j++)
            printf("%-4d ", *(*(matrix + i) + j));

        printf("\n");
    }

    printf("\n");
}

int sum_under_main_diagonal(int matrix[][S], int r) {

    int sum = 0;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < i; j++)
            sum += *(*(matrix + i) + j);

    return sum;
}

int sum_over_main_diagonal(int matrix[][S], int r) {

    int sum = 0;

    for(int j = 0; j < r; j++) 
        for(int i = 0; i < j; i++)
            sum += *(*(matrix + i) + j);

    return sum;
}

int evaluate_sums(int matrix[][S], int r) {

    int sum1 = sum_under_main_diagonal(matrix, r);
    int sum2 = sum_over_main_diagonal(matrix, r);

    if(sum1 > sum2)
        return 1;
    else if(sum1 < sum2)
        return -1;
    else
        return 0;
}

void print_top(int matrix[][S], int r) {

    printf("\n Top triangle\n");
    for(int i = 0; i < r / 2; i++)
        for(int j = i + 1; j < r - i - 1; j++)
            printf("%-4d ", *(*(matrix + i) + j));
    
    printf("\n");
}

void print_bottom(int matrix[][S], int r) {

    printf("\n Bottom triangle\n");
    for(int i = r - 1; i > r / 2; i--)
        for(int j = r - i; j < i; j++)
            printf("%-4d ", *(*(matrix + i) + j));

    printf("\n");
}

void print_left(int matrix[][S], int r) {

    printf("\n Left triangle\n");
    for(int i = 1; i < r; i++)
        for(int j = 0; j < i && j < r - i - 1; j++)
            printf("%-4d ", *(*(matrix + i) + j));
    
    printf("\n");
}

void print_right(int matrix[][S], int r) {

    printf("\n Right triangle\n");
    for(int i = 1; i < r; i++)
        for(int j = r - 1; j > i && j > r - i - 1; j--)
            printf("%-4d ", *(*(matrix + i) + j));
    
    printf("\n");
}
