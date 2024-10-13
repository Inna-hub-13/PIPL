
// Write a program that checks if a given path is a path in a labyrinth
// path is represented by array
// 1 - top, 2 - right, 3 - bottom, 4 - left

// Assume the labyrinth is represented by a two dimentional array
// start[0][0], exit[N - 1][M - 1]
// 1 - 'you can step', 0 - 'you cannot step'

// Assume you can't make more than K steps

#include <stdio.h>
#include <stdbool.h>
#define N 7
#define M 10
#define K 20


int labyrinth[][M] = {
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 0, 1, 0, 0, 0},
    {1, 0, 0, 1, 1, 1, 1, 0, 0, 0},
    {1, 0, 0, 1, 0, 0, 1, 1, 1, 0},
    {1, 0, 0, 0, 0, 0, 1, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

bool is_a_path(int*, int, int, int);

int main() {

    int path1[] = {2, 3, 3, 2, 2, 2, 4};
    printf("path1 is valid -> %d\n", is_a_path(path1, 0, 0, 0));
    int path2[] = {3, 3, 2, 2, 2, 2, 3, 2, 2, 3, 2, 2, 3, 3, 2};
    printf("path2 is valid -> %d\n", is_a_path(path2, 0, 0, 0));

    return 0;
}

bool is_a_path(int* intput_path, int i, int j, int count_steps) {

    if(count_steps > K) return 0;
    if(i == N - 1 && j == M - 1) return 1;
    if(labyrinth[i][j] == 0) return 0;
    if(i < 0 || j < 0 || i > N || j > M) return 0;

    if(intput_path[count_steps] == 1)
     return is_a_path(intput_path, i - 1, j, count_steps + 1);
    if(intput_path[count_steps] == 2)
        return is_a_path(intput_path, i, j + 1, count_steps + 1);
    if(intput_path[count_steps] == 3)
        return is_a_path(intput_path, i + 1, j, count_steps + 1);
    if(intput_path[count_steps] == 4)
        return is_a_path(intput_path, i, j - 1, count_steps + 1);
}
