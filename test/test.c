#include "../main.h"
#include <limits.h>
#include <stdio.h>

int main() {

	char input[] = "Hello, World!";

	printf("Original String: %s\n", input);
	printf("ROT13 Encoded String: ");

	_printf("%R", input);
	printf("\n");

	return (0);

}
