#include "../main.h"
#include <limits.h>
#include <stdio.h>

int main() {

	char input[] = "Hello, World!";

	printf("Original String: %s\n", input);
	printf("Reversed String: ");
	_printf("%r", input);
	printf("\n");

	return (0);
}
