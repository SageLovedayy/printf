#include "main.h"

int main() {
    int num;
    int num1;

    num = _printf("Let's try to printf a simple sentence.\n");
    num1 = printf("Let's try to printf a simple sentence.\n");
    printf("return value _printf: %d\n return value printf: %d\n\n", num, num1);

    num = _printf("Character:[%c]\n", 'H');
    num1 = printf("Character:[%c]\n", 'H');
    printf("return value _printf: %d\n return value printf: %d\n\n", num, num1);

    num = _printf("String:[%s]\n", "I am a string !");
    num1 = printf("String:[%s]\n", "I am a string !");
    printf("return value _printf: %d\n return value printf: %d\n\n", num, num1);


    return 0;
}