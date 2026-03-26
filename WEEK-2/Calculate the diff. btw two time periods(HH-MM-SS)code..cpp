#include <stdio.h>
struct time {
    int hours;
    int minutes;
    int seconds;
};

struct time difference(struct time t1, struct time t2) {
    struct time diff;

    int totalSec1 = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    int totalSec2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;

    int diffSec = totalSec1 - totalSec2;
    if(diffSec < 0)
        diffSec = -diffSec;

    // Convert seconds back to HH:MM:SS
    diff.hours = diffSec / 3600;
    diffSec = diffSec % 3600;
    diff.minutes = diffSec / 60;
    diff.seconds = diffSec % 60;

    return diff;
}

int main() {
    struct time t1, t2, diff;

    printf("Enter first time (HH MM SS): ");
    scanf("%d %d %d", &t1.hours, &t1.minutes, &t1.seconds);

    printf("Enter second time (HH MM SS): ");
    scanf("%d %d %d", &t2.hours, &t2.minutes, &t2.seconds);

    diff = difference(t1, t2);

    printf("Difference = %02d:%02d:%02d\n", diff.hours, diff.minutes, diff.seconds);

    return 0;
}
