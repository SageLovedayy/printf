#include "main.h"

/**
* is_digit - check if is digit
* @c: character
* Return: check
*/
int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
* parse_format_width - add descr
* @format: character representing specific format specifier
* @index: add descr
* @args: add descr
* Return: width
*/
int parse_format_width(const char *format, unsigned int *index, va_list args)
{
	int current_index = *index + 1;
	int width = 0;

	while (format[current_index] != '\0')
	{
		if (is_digit(format[current_index]))
		{
			/* Accumulate the width value */
			width = width * 10 + (format[current_index] - '0');
			current_index++;
		}
		else if (format[current_index] == '*')
		{
			/* Handle '*' specifier for width */
			current_index++;
			width = va_arg(args, int);
			break;
		}
		else
		{
			break; /* Invalid character, exit loop */
		}
	}

	*index = current_index - 1; /* Update index pointer */
	return (width);
}
