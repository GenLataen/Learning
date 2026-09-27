#include <stdio.h>
#include "hello.h"

int main() {
    printf("========== CMake Demo ==========\n");
    
    say_hello("World");
    print_date();
    
    printf("================================\n");
    return 0;
}
