#include <stdio.h>
#include <time.h>

int main(void) {
    time_t _time = time(NULL);
    struct tm *Time = localtime(&_time);
    char Result[64];
    size_t FLAG = strftime(Result, sizeof(Result), "%c", Time);
    printf("Current date and time: %s\n", Result);
    return 0;
}
