#include "../main.h"
#include <limits.h>
#include <stdio.h>

void run_printf_tests() {
    int integerVal = 42;
    float floatVal = 3.14159;

    int hexVal = 255;
    char charVal = 'A';

    _printf("Integer: %+d\n", integerVal);
    _printf("Float: %.2f\n", floatVal);
    _printf("String: %s\n", "stringVal");
    _printf("Hex: %#x\n", hexVal);
    _printf("Character: %c\n", charVal);
    _printf("Invalid Format: %z\n", 123);
}

int main() {
    run_printf_tests();
    return 0;
}