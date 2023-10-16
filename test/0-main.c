#include "../main.h"
#include <limits.h>
#include <stdio.h>

int main() {

    int num, num1, len, len2, *ptr, i;
    unsigned int ui = (unsigned int)INT_MAX + 1024;

    /*printf("%\n");*/
    printf("%+d", 42);
    _printf("%+d", 42);

    _printf("%s\n", NULL);
    _printf("Character: %c, String: %s, Integer: %d\n", 'X', "Testing", 123);

    printf("Left-aligned: |%-20s|\n", "Left Aligned Text");
    _printf("Left-aligned: |%-20s|\n", "Left Aligned Text");

    i = 2;
    ptr = &i;
    num = printf("The address is: %p, the value is %d\n", (void *)ptr, *ptr);
    num1 = _printf("The address is: %p, the value is %d\n", (void *)ptr, *ptr);
    printf("return value _printf: %d\n return value printf: %d\n\n", num, num1);




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
