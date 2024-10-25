
// 1) Write a function that returns an array of all students,
// that can get scholarship.

// 2) Write a function that removes a student from group, if they have
// more or equal of given number of poor marks.

// Implementation, using structs!!

//N -> const for names length
//K -> const for number of elements

#include <stdio.h>
#include <stdlib.h>
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
struct student* get_scholarship(const struct faculty*, int, float);
void rearrange_group(struct group*, int);
void remove_std(struct group*, int);

int main() {

    struct discipline d1 = {"Computer Science", 5};
    struct discipline d2 = {"Computer Science", 5.5};
    struct discipline d3 = {"Biology", 5.5};
    struct discipline d4 = {"Biology", 3};
    struct discipline d5 = {"Biology", 4};
    struct discipline d6 = {"Genetics", 6};
    struct discipline d7 = {"Biology", 2};
    struct discipline d8 = {"Genetics", 2};

    struct student s1;

     strcpy_s(s1.studName, N, "Misho");
     s1.disciplines[0] = d2;
     s1.disciplines[1] = d3;
     s1.countDisciplines = 2;
     s1.facNumber = 1015;
     cal_avg_grade(&s1);

     struct student s2;

     strcpy_s(s2.studName, N, "Georgy");
     s2.disciplines[0] = d1;
     s2.disciplines[1] = d6;
     s2.disciplines[2] = d4;
     s2.countDisciplines = 3;
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
     s5.disciplines[0] = d1;
     s5.disciplines[1] = d6;
     s5.disciplines[2] = d3;
     s5.countDisciplines = 3;
     s5.facNumber = 2017;
     cal_avg_grade(&s5);

    struct student s6;
     
     strcpy_s(s6.studName, N, "Maria");
     s6.disciplines[0] = d2;
     s6.disciplines[1] = d4;
     s6.countDisciplines = 2;
     s6.facNumber = 2018;
     cal_avg_grade(&s6);

     struct student sr1;
     
     strcpy_s(sr1.studName, N, "Tisho");
     sr1.disciplines[0] = d7;
     sr1.disciplines[1] = d8;
     sr1.countDisciplines = 2;
     sr1.facNumber = 1014;
     cal_avg_grade(&sr1);

     struct student sr2;
     
     strcpy_s(sr2.studName, N, "Stoyan");
     sr2.disciplines[0] = d7;
     sr2.disciplines[1] = d8;
     sr2.countDisciplines = 2;
     sr2.facNumber = 1018;
     cal_avg_grade(&sr2);


     struct group g1;
     strcpy_s(g1.groupName, N, "Group1");
     g1.students[0] = sr1;
     g1.students[1] = s1;
     g1.students[2] = s2;
     g1.students[3] = sr2;
     g1.countStudents = 4;
     strcpy_s(g1.speciality, N, "Biocomputing");

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

    
    struct student* sch_holders = get_scholarship(&fac1, K, 5.50);
    remove_std(&g1, 2);

    print_group(&g1);

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

struct student* get_scholarship(const struct faculty* fac, int max_students,
                                    float min_grade) {

    // max_students -> the maximum amount of scholarships
    // min_grade -> the minimum average grade to take scholarship

    struct student* sch_holders = (struct student*)
                                    malloc(max_students * sizeof(struct student));

    if(!sch_holders)
        return NULL;
    
    // sch_holders_count -> counts the current amount of sch_holders
    // i -> outer loop iterates through all groups in faculty
    // j-> inner loop iterates through the students in each group
    int i, j, sch_holders_count = 0;

    for(i = 0; i < fac -> countGroups; i++)
        for(j = 0; j < fac -> groups[i].countStudents; j++)
            if(fac -> groups[i].students[j].averageGrade >= min_grade 
                && max_students > sch_holders_count) {

                    *(sch_holders + sch_holders_count) = fac -> groups[i].students[j];
                    sch_holders_count++;
                }
    
    printf("Scholarship holders");
    for(i = 0; i < sch_holders_count; i++)
        print_std(sch_holders + i);

    printf("\n");
    return sch_holders;
}

// help function that rearranges a group
void rearrange_group(struct group* group, int pos) {

    int i = pos;
    while(i < group -> countStudents - 1){

        group -> students[i] = group -> students[i + 1];
        i++;
    }
    
    group -> countStudents --;
        
}

void remove_std(struct group* group, int max_num_poor) {

    // max_num_poor -> gives the maximum amount of poor marks
    // a student can have to continue be part of faculty

    int i, j, count_marks;
    
    // 1. Find a student to be removed
    // 2. Remove the student with the help function - rearrange_group()
    for(i = 0; i < group -> countStudents; i++) {

        count_marks = 0;
        for(j = 0; j < group -> students[i].countDisciplines; j++)
            if(group -> students[i].disciplines[j].grade == 2)
                count_marks++;
        
        // check for potential student to remove
        if(count_marks >= max_num_poor){

            printf("%s removed from %s\n", group -> students[i].studName,
                        group -> groupName);
            rearrange_group(group, i);
        }

    }
    
}
