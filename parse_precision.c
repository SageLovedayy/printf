#include "main.h"


/**
* parse_format_precision - add descr
* @format: character representing specific format specifier
* @index: add descr
* @args: add descr
* Return: precision
*/
int parse_format_precision(const char *format, int *index, va_list args)
{
	int current_index = *index + 1;
	int precision = -1;

	/* Check if precision indicator is present (format[current_index] == '.')*/
	if (format[current_index] != '.')
	{
		return (precision); /* No precision specified*/
	}

	precision = 0;
	current_index++; /* Move past the '.'*/

	/* Parse precision value */
	while (format[current_index] != '\0')
	{
		if (is_digit(format[current_index]))
		{
			precision = precision * 10 + (format[current_index] - '0');
			current_index++;
		}
		else if (format[current_index] == '*')
		{
			/* Handle '*' specifier for precision */
			current_index++;
			precision = va_arg(args, int);
			break;
		}
		else
		{
			break; /* Invalid character, exit loop */
		}
	}

	*index = current_index - 1; /* Update index pointer */
	return (precision);
}
