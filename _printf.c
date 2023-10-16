#include "main.h"

/**
* printhand - handles format specifiers and prints formatted output
* @format: formatted input string containing specifiers
* @iter: list of specifier characters to iterate over (va_list)
* Return: number of characters printed successfully
*/
int printhand(const char *format, va_list iter)
{
	int i = 0, counter = 0;
	int unknown_len = 0;
	struct FormatSettings formatSettings;

	format_specifier specifiers[] = {
		{'c', handle_char}, {'s', handle_string}, {'%', handle_percent},
		{'d', handle_int}, {'i', handle_int}, {'u', handle_unsigned},
		{'b', handle_binary}, {'o', handle_octal}, {'x', handle_hex_lower},
		{'X', handle_hex_upper}, {'S', handle_custom_string}, {'p', handle_pointer},
		{'\0', NULL} /* add more specifiers */
	};
	for (i = 0; specifiers[i].specifier != '\0'; i++)
	{
		if (*format == specifiers[i].specifier)
		{
			counter += (specifiers[i].handler(iter, &formatSettings));
			break;
		}
	}

	if (specifiers[i].specifier == '\0')
	{
		if (format[i] == '\0') /* Handle unknown format specifier */
			return (-1);
		unknown_len += write(1, "%%", 1);
		if (format[i - 1] == ' ')
			unknown_len += write(1, " ", 1);
		else if (formatSettings.width)
		{
			--i;
			while (format[i] != ' ' && format[i] != '%')
				--i;
			if (format[i] == ' ')
				--i;
			return (1);
		}
		unknown_len += write(1, &format[i], 1);
		return (unknown_len);
	}
	return (counter);
}

/**
* _printf - custom printf implementation for formatted output
* @format: formatted string containing specifiers
* Return: number of characters printed successfully. returns -1 on error
*/
int _printf(const char *format, ...)
{
	unsigned int count = 0, prem_count;
	va_list args;

	va_start(args, format);

	if (format == NULL)
		return (-1);

	while (*format && (*format != '\0'))
	{
		if (*format == '%')
		{
			format++;
			prem_count = printhand(format, args);

			count += prem_count;
		}
		else
			count += write(1, format, 1);
		format++;
	}

	va_end(args);
	return (count);
}
