
// Write an implementation of a function that takes as parameters -
// faculty number, name of discipline and faculty.
// The function returns the grade of the student with given faculty number
// at given discipline.

// Implementation, using structs!!

//N -> const for names length
//K -> const for number of elements

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 50
#define K 30

struct discipline{

    char discName[N];
    float grade;
};

struct student{

    char studName[N];
    // keeps all disciplines, studied by one student
    struct discipline disciplines[K];
    int facNumber;
    int countDisciplines;
    float averageGrade;
};

struct group{

    char groupName[N];
    // keeps all students in one group
    struct student students[K];
    int countStudents;
    // name of speciality
    char speciality[N];
};

struct faculty {

    char facName[N];
    // keeps all groups in one faculty
    struct group groups[K];
    int countGroups;
};

float get_grade(int, const struct faculty*, const char*);

int main() {

    struct discipline d1 = {"Computer Science", 5};
    struct discipline d2 = {"Computer Science", 6};
    struct discipline d3 = {"Biology", 5.5};
    struct discipline d4 = {"Biology", 6};

   /* Unfinished 22.10 2024
    struct discipline* ds1 = (struct discipline*)malloc(2 * sizeof(struct discipline));
    *ds1 = d1;
    *(ds1 + 1) = d2;
    struct discipline ds2[2] = {d2, d3};

    struct student s1 = {"Misho", ds1, 1015, 2, 5.45};
    struct student s2 = {"Gosho", ds1, 1016, 2, 5.45};
    struct student s3 = {"Ivan", ds2, 2015, 2, 5.45};
    struct student s4 = {"Nadya", ds2, 2016, 2, 5.6};

    struct student students1[2] = {s1, s2};
    struct student students2[2] = {s3, s4};

    struct group g1 = {"Group1", students1, 2, "Biocomputing"};
    struct group g2 = {"Group2", students2, 2, "Biocomputing"};

    struct group groups1[2] = {g1, g2};

    struct faculty fac1 = {"CBF", groups1, 2};

    float grade = get_grade(1015, &fac1, "Computer Science");
    printf("grade: %f\n", grade);*/

    return 0;
}

float get_grade(int facultyN, const struct faculty* fac, const char* nameD) {

    int i, j, indexGroup, indexStudent, flagFound = 0;

    for(i = 0; i < fac -> countGroups; i++)
        for(j = 0; j < fac -> groups[i].countStudents; j++)
            if(fac -> groups[i].students[j].facNumber == facultyN){

                // found matching faculty number
                indexGroup = i;
                indexStudent = j;
                flagFound = 1;
                // terminates loops
                i = fac -> countGroups;
                j == fac -> groups[i].countStudents;
            }
    
    // perform additional check
    // if no such student with <facultyN> exists
    struct student foundS1;
    if(flagFound)
        foundS1 = fac -> groups[indexGroup].students[indexStudent];
    else
        return -1;

    for(i = 0; i < foundS1.countDisciplines; i++)
        if(strcmp(foundS1.disciplines[i].discName, nameD) == 0)
            return foundS1.disciplines[i].grade;
    
    // no discpiline whit <nameD> found
    return -1;
}
