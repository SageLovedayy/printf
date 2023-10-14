#include "main.h"

int main() {
    int num, num1, len, len2;

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

    return 0;
}
