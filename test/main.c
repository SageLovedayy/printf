#include "../main.h"
#include <limits.h>
#include <stdio.h>

int main() {

    int num, num1, len, len2;
    unsigned int ui = (unsigned int)INT_MAX + 1024;
    _printf("%s\n", NULL);
    _printf("Character: %c, String: %s, Integer: %d\n", 'X', "Testing", 123);




    num = _printf("Let's try to printf a simple sentence.\n");
    num1 = printf("Let's try to printf a simple sentence.\n");
    printf("return value _printf: %d\n return value printf: %d\n\n", num, num1);

    num = _printf("Character:[%c]\n", 'H');
    num1 = printf("Character:[%c]\n", 'H');
    printf("return value _printf: %d\n return value printf: %d\n\n", num, num1);

    num = _printf("String:[%s]\n", "I am a string !");
    num1 = printf("String:[%s]\n", "I am a string !");
    printf("return value _printf: %d\n return value printf: %d\n\n", num, num1);

    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");

    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("%S\n", "Best\nSchool");

    _printf("%b\n", 98);



    return 0;
}
