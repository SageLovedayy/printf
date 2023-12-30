#include "main.h"

/**
* printhand - handles format specifier and prints formatted output
* @format: formatted input string containing specifier
* @iter: list of spec characters to iterate over (va_list)
* Return: number of characters printed successfully
*/
int printhand(const char *format, va_list iter)
{
	int i = 0, count = 0;
	format_setting_t format_setting;
	format_specifier_t specifier[] = {
		{'c', handle_char},
		{'s', handle_string},
		{'%', handle_percent},
		{'d', handle_int},
		{'i', handle_int},
		{'u', handle_unsigned},
		{'b', handle_binary},
		{'o', handle_octal},
		{'x', handle_hex_lower},
		{'X', handle_hex_upper},
		{'S', handle_custom_string},
		{'p', handle_pointer},
		{'R', handle_rot13},
		{'\0', NULL},
		/* add more specifier */
	};

	format_setting.flags = parse_format_flags(format, &i);
	format_setting.width = parse_format_width(format, &i, iter);
	format_setting.precision = parse_format_precision(format, &i, iter);

	for (i = 0; specifier[i].spec != '\0'; i++)
	{
		if (*format == specifier[i].spec)
		{
			count += specifier[i].handler(iter, &format_setting);
			break;
		}
	}

	if (specifier[i].spec == '\0')
	{
		write(1, "%", 1);
		write(1, format, 1);
		count += 2;
	}
	return (count);
}

/**
* _printf - custom printf implementation for formatted output
* @format: formatted string containing specifier
* Return: number of characters printed successfully. returns -1 on error
*/
int _printf(const char *format, ...)
{
	unsigned int count = 0, _count;
	va_list args;

	va_start(args, format);

	if (format == NULL)
		return (-1);

	while (*format)
	{
		if (*format == '%')
		{
			if (*(format + 1) == '\0')
				return (0);
			else
			{
				format++;
				_count = printhand(format, args);

				count += _count;
			}
		}
		else
		{
			if (write(1, format, 1) > 0)
				count++;
			else
				return (-1);
		}
		format++;
	}

	va_end(args);
	return (count);
}
