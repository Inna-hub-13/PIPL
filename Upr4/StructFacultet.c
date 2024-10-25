
// Write an implementation of a functions

// 1) The function that takes as parameters -
// faculty number, name of discipline and faculty.
// Returns grade of the student with given faculty number at given discipline.

// 2) The function takes faculty and name of a group.
// Returns the address of the student with higest average grade.

// 3) The function takes two groups and faculty number.
// Moves the student, with given faculty number, from the first to the second group.
// Returns 0 for success, -1 failure.

// 4) The function takes faculty and faculty number.
// Returns the address of the group of the student with given faculry number.

// Implementation, using structs!!

//N -> const for names length
//K -> const for number of elements

// Last update 25.10 2024

#include <stdio.h>
#include <string.h>
#define N 25
#define K 5

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

void cal_avg_grade(struct student*);
void print_group(const struct group*);
void print_std(const struct student*);
float get_grade(const struct faculty*, int, const char*);
struct student* get_best_std(struct faculty*, const char*);
int move_std(struct group*, struct group*, int);
struct group* get_group(struct faculty*, int);

int main() {

    struct discipline d1 = {"Computer Science", 5};
    struct discipline d2 = {"Computer Science", 6};
    struct discipline d3 = {"Biology", 5.5};
    struct discipline d4 = {"Biology", 6};
    struct discipline d5 = {"Biology", 4};
    struct discipline d6 = {"Genetics", 6};

    struct student s1;

     strcpy_s(s1.studName, N, "Misho");
     s1.disciplines[0] = d2;
     s1.disciplines[1] = d3;
     s1.countDisciplines = 2;
     s1.facNumber = 1015;
     cal_avg_grade(&s1);

     struct student s2;

     strcpy_s(s2.studName, N, "Georgy");
     s2.disciplines[0] = d2;
     s2.disciplines[1] = d3;
     s2.countDisciplines = 2;
     s2.facNumber = 1016;
     cal_avg_grade(&s2);

     struct student s3;
     strcpy_s(s3.studName, N, "Ivan");
     s3.disciplines[0] = d2;
     s3.disciplines[1] = d6;
     s3.countDisciplines = 2;
     s3.facNumber = 2015;
     cal_avg_grade(&s3);

     struct student s4;

     strcpy_s(s4.studName, N, "Nadya");
     s4.disciplines[0] = d1;
     s4.disciplines[1] = d6;
     s4.disciplines[2] = d3;
     s4.countDisciplines = 3;
     s4.facNumber = 2016;
     cal_avg_grade(&s4);

     struct student s5;

     strcpy_s(s5.studName, N, "Elena");
     s5.disciplines[0] = d2;
     s5.disciplines[1] = d6;
     s5.disciplines[2] = d3;
     s5.countDisciplines = 3;
     s5.facNumber = 2017;
     cal_avg_grade(&s5);

    struct student s6;
     
     strcpy_s(s6.studName, N, "Maria");
     s6.disciplines[0] = d1;
     s6.disciplines[1] = d6;
     s6.countDisciplines = 2;
     s6.facNumber = 2018;
     cal_avg_grade(&s6);


     struct group g1;
     strcpy_s(g1.groupName, N, "Group1");
     g1.students[0] = s1;
     g1.students[1] = s2;
     g1.countStudents = 2;
     strcpy_s(g1.speciality, N, "Biocompuing");

     struct group g2;
     strcpy_s(g2.groupName, N, "Group2");
     g2.students[0] = s3;
     g2.students[1] = s4;
     g2.students[2] = s5;
     g2.students[3] = s6;
     g2.countStudents = 4;
     strcpy_s(g2.speciality, N, "Biology");

     print_group(&g1);
     print_group(&g2);


     struct faculty fac1;
     strcpy_s(fac1.facName, N, "CBF");
     fac1.countGroups = 2;
     fac1.groups[0] = g1;
     fac1.groups[1] = g2;

     float grade1 = get_grade(&fac1, 2018, "Computer Science");
     float grade2 = get_grade(&fac1, 1015, "Biology");

     printf("grade1: %f\n", grade1);
     printf("grade2: %f\n", grade2);

     struct student* best1 = get_best_std(&fac1, "Group1"); 
     struct student* best2 = get_best_std(&fac1, "Group2");

     if(best1)
        print_std(best1);
     if(best2)
        print_std(best2);

     printf("\naddress best1: %p\n", best1);
     printf("address best2: %p\n", best2);

     int r = move_std(&g2, &g1, 2017);
     printf("r: %d\n", r);

     print_group(&g1);
     print_group(&g2);

     struct group* groupFound = get_group(&fac1, 1016);
     printf("address groupFound: %p\n", groupFound);

    return 0;
}

void cal_avg_grade(struct student* std) {

    int i;
    float sum = 0;
    for(i = 0; i < std -> countDisciplines; i++)
        sum += std -> disciplines[i].grade;
    
    std -> averageGrade = sum / std -> countDisciplines;
}

void print_group(const struct group* group) {

    int i;
    printf("\tGroup name: %s\n", group -> groupName);
    printf("\tSpeciality: %s\n", group -> speciality);
    printf("\tStudents\n");
    for(i = 0; i < group -> countStudents; i++){
        
        printf("\t\tStudent name: %s\n", group -> students[i].studName);
        printf("\t\tFaculty number: %d\n", group -> students[i].facNumber);
        printf("\t\tAverage grade: %.2f\n", group -> students[i].averageGrade);
        printf("\n");
    }
    printf("\n");
}

void print_std(const struct student* std) {

    printf("\nName: %s\n", std -> studName);
    printf("Average grade: %.2f\n", std -> averageGrade);
    printf("Faculty number: %d\n", std -> facNumber);
}

float get_grade(const struct faculty* fac, int facultyN, const char* nameD) {

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
                j = fac -> groups[i].countStudents;
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

struct student* get_best_std(struct faculty* fac, const char* nameG) {

    int i, indexS, indexG, flagFound = 0;
    for(i = 0; i < fac -> countGroups; i++)
        if(strcmp(fac -> groups[i].groupName, nameG) == 0){

            flagFound = 1;
            indexG = i;
            // terminates for loop
            i = fac -> countGroups;
        }
    
    // no group with name <nameG> found
    if(!flagFound)
        return NULL;
    
    float maxGrade = fac -> groups[indexG].students[0].averageGrade;
    indexS = 0;
    for(i = 1; i < fac -> groups[indexG].countStudents; i++)
        if(maxGrade < fac -> groups[indexG].students[i].averageGrade){

            maxGrade = fac -> groups[indexG].students[i].averageGrade;
            indexS = i;
        }

    printf("Best student in group %s: %s\n", nameG, 
            fac -> groups[indexG].students[indexS].studName);

    return fac-> groups[indexG].students + indexS;
}

int move_std(struct group* group1, struct group* group2, int facultyN) {

    int i, indexS, flagFound = 0;
    for(i = 0; i < group1 -> countStudents; i++)
        if(group1 -> students[i].facNumber == facultyN){

            indexS = i;
            flagFound = 1;
            // terminates for loop
            i = group1 -> countStudents;
        }

    // no student with <facultyN> found
    if(!flagFound)
        return -1;
    
    struct student temp = group1 -> students[indexS];
    // move the left students one position forward
    for(i = indexS; i < group1 -> countStudents - 1; i++)
        group1 -> students[i] = group1 -> students[i + 1];
    
    group1 -> countStudents --;

    group2 -> students[group2 -> countStudents] = temp;
    group2 -> countStudents ++;
    printf("%s moved to %s\n", temp.studName, group2 -> groupName);
    return 0;
}

struct group* get_group(struct faculty* fac, int facultyN) {

    int i, j;
    for(i = 0; i < fac -> countGroups; i++)
        for(j = 0; j < fac -> groups[i].countStudents; j++)
            if(fac -> groups[i].students[j].facNumber == facultyN) {

                printf("Student %s with faculty number %d in group %s\n", 
                    fac -> groups[i].students[j].studName, 
                    fac -> groups[i].students[j].facNumber,
                    fac -> groups[i].groupName);

                return fac -> groups + i;
            }
    
    // no student with <facultyN> found
    return NULL;
}
