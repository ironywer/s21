#include "print_module.h"

#include <stdio.h>
#include <time.h>

#include "documentation_module.h"

void print_log(char (*print)(char), char* message) {
    for (int i = 0; i < 5; i++) print(Log_prefix[i]);
    time_t t = time(NULL);
    struct tm* aTm = localtime(&t);
    int H = aTm->tm_hour;
    int M = aTm->tm_min;
    int S = aTm->tm_sec;
    char a[12] = {' ',          '0' + H / 10, '0' + H % 10, ':',          '0' + M / 10,
                  '0' + M % 10, ':',          '0' + S / 10, '0' + S % 10, ' '};
    for (int i = 0; i < 12; i++) {
        print(a[i]);
    }
    while (*message != '\0') {
        print(*message);
        message++;
    }
}

char print_char(char ch) { return putchar(ch); }
