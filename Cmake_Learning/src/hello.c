#include <stdio.h>
#include <time.h>
#include "hello.h"

void say_hello(const char* name) {
    printf("Hello, %s! Welcome to CMake project.\n", name);
}

void print_date(void) {
    time_t t = time(NULL);
    struct tm* tm_info = localtime(&t);
    char buffer[100];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info);
    printf("Current time: %s\n", buffer);
}
