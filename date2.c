#include <stdio.h>
#include <time.h>

int main(void) {
    time_t _time = time(NULL);
    struct tm *tm= localtime(&_time);
    char Result[64];
    size_t ret = strftime(Result, sizeof(Result), "%c", tm);
    printf("Current date and time: %d-%02d-%02d %02d:%02d:%02d\n", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);

    return 0;
}
