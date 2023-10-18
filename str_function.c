#include "main.h"

/**
 * _strlen - Returns the length of a string
 * @s: string to be counted
 * Return: lenth
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
* _itoa - add descr
* @value: add descr
* @output: descri
*/
void _itoa(int value, char *output)
{
	const char *hex_chars = "0123456789ABCDEF";

	output[0] = hex_chars[(value >> 4) & 0xF];
	output[1] = hex_chars[value & 0xF];
	output[2] = '\0';
}
