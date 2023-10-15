#include "../main.h"
#include <limits.h>
#include <stdio.h>

int main() {


    /**
    * _printf("%s\n", NULL);
    * _printf("Character: %c, String: %s, Integer: %d\n", 'X', "Testing", 123);
    */

    /**
    * i = 2;
    * ptr = &i;
    * num = printf("The address is: %p, the value is %d\n", (void *)ptr, *ptr);
    * num1 = _printf("The address is: %p, the value is %d\n", (void *)ptr, *ptr);
    * printf("return value _printf: %d\n return value printf: %d\n\n", num, num1);
    */

    /**
    * ptr = NULL;
    * printf("%p\n", ptr);
    * _printf("%p\n", ptr);
    */

    char basicChar, newline, tab, asciiValue, nullChar, nonPrintableChar;
    int charAsInt;

    basicChar= 'A';
    printf("Basic Character: %c\n", basicChar);
    _printf("Basic Character: %c\n", basicChar);

    newline = '\n';
    printf("Newline Character: %c\n", newline);
    _printf("Newline Character: %c\n", newline);

    tab = '\t';
    printf("Tab Character: %c|\n", tab);
    _printf("Tab Character: %c|\n", tab);

    asciiValue = 65;
    printf("Character from ASCII value: %c\n", asciiValue);
    _printf("Character from ASCII value: %c\n", asciiValue);


    nullChar= '\0';
    printf("Null Character: %c\n", nullChar);
    _printf("Null Character: %c\n", nullChar);

    nonPrintableChar= 1;
    printf("Non-Printable Character: %c\n", nonPrintableChar);
    _printf("Non-Printable Character: %c\n", nonPrintableChar);

    charAsInt = 'B';
    printf("Character represented as integer: %d\n", charAsInt);
    _printf("Character represented as integer: %d\n", charAsInt);


    return (0);

}
