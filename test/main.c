#include "../main.h"
#include <limits.h>
#include <stdio.h>

int main() {

    void *ptr;
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

    ptr = NULL;
    printf("%p\n", ptr);
    _printf("%p\n", ptr);

    return 0;
}
