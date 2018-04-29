#include <stdio.h>

struct time{
    int hours;
    int minutes;
    int seconds;
};

struct time timeUpdate(struct time new);

int main(void){

    struct time current_t;
    struct time next_t;
    printf("Enter the time in format hh:mm:ss");
    scanf("%i:%i:%i", &current_t.hours,
            &current_t.minutes, &current_t.seconds);

    next_t = timeUpdate(current_t);

    printf("%i:%i:%.2i", next_t.hours, next_t.minutes,
            next_t.seconds);
    return 0;
}

struct time timeUpdate(struct time new){

    new.seconds++;

    if(new.seconds==60){
        new.seconds = 0;
        new.minutes++;
    }
    if(new.minutes ==60){
        new.minutes = 0;
        new.hours++;
    }
    if(new.hours==24){
        new.hours = 0;
    }
    return new;
}