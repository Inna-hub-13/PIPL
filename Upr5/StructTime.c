
// Write an implementation of a function that takes as a parameter struct time.
// The function must return a string representation of the time in format
// hh:mm:ssPM

// Reverse the first function to take string in given format and return struct time.

#include <stdio.h>
#include <stdlib.h>

struct time {

    int hour;
    int min;
    int sec;
};

char* parse_time(const struct time*);
struct time* get_time(char*);

int main() {

    struct time time1 = {16, 52, 30};
    char* str = parse_time(&time1);
    printf("%s\n", str);

    struct time* time2 = get_time("12:17:18PM");
    printf("time2 -> hour: %d\n", time2 -> hour);
    printf("time2 -> min: %d\n", time2 -> min);
    printf("time2 -> sec: %d\n", time2 -> sec);

    return 0;
}

char* parse_time(const struct time* time) {

    //hh:mm:ssPM
    char* str = (char*)malloc(11 * sizeof(char));
    if(!str)
        return NULL;

    // determine hours
    if(time -> hour > 12) {

        *(str) = (time -> hour - 12) / 10 + '0';;
        *(str + 1) = (time -> hour - 12) % 10 + '0';
        *(str + 8) = 'P';
    }
    else if(time -> hour == 12) {
        
        *(str) = time -> hour / 10 + '0';
        *(str + 1) = time -> hour % 10 + '0';
        *(str + 8) = 'P';
    }
    else {

        *(str) = time -> hour / 10 + '0';
        *(str + 1) = time -> hour % 10 + '0';
        *(str + 8) = 'A';
    }

    // determine minutes
    *(str + 3) = time -> min / 10 + '0';
    *(str + 4) = time -> min % 10 + '0';

    // determine secundes
    *(str + 6) = time -> sec / 10 + '0';
    *(str + 7) = time -> sec % 10 + '0';

    *(str + 2) = ':';
    *(str + 5) = ':';
    *(str + 9) = 'M';
    *(str + 10) = '\0';

    return str;
}

struct time* get_time(char* str) {

    struct time* time = (struct time*)malloc(sizeof(struct time));
    if(!time)
        return NULL;

    //hh:mm:ssPM
    if(*(str + 8) == 'P' && *(str + 1) != '2')
        time -> hour = (*(str) - '0') * 10 + *(str + 1) - '0' + 12;
    else if(*(str + 1) == 2)
        time -> hour = (*(str) - '0') * 10 + *(str + 1) - '0';
    else
        time -> hour = (*(str) - '0') * 10 + *(str + 1) - '0';

    time -> min = (*(str + 3) - '0') * 10 + *(str + 4) - '0';
    time -> sec = (*(str + 6) - '0') * 10 + *(str + 7) - '0';

    return time;
}