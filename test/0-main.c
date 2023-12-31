#include <stdio.h>
#include <stdlib.h>
#include "../main.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */
int main(void)
{
	int len;
	len = printf("%+d\n", 1024);
	printf("len [%d]\n", len);
	fflush(stdout);
	return (0);
}
