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

/* think it'll be useful for handling i and d, let's see */
/**
 * _atoi - function that convert a string to an integer.
 * @s: The string to be converted.
 * Return: the converted integer.
 */
int _atoi(char *s)
{
	int i = 0, d = 0, n = 0, len = 0, f = 0, digit = 0;

	while (s[len] != '\0')
		len++;
	while (i < len && f == 0)
	{
		if (s[i] == '-')
			++d;
		if (s[i] >= '0' && s[i] <= '9')
		{
			digit = s[i] - '0';
			if (d % 2)
				digit = -digit;
			n = n * 10 + digit;
			f = 1;
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
			f = 0;
		}
		i++;
	}
	if (f == 0)
		return (0);

	return (n);
}


void _itoa(int value, char *output)
{
	const char *hex_chars = "0123456789ABCDEF";
	output[0] = hex_chars[(value >> 4) & 0xF];
	output[1] = hex_chars[value & 0xF];
	output[2] = '\0';
}