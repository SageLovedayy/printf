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
	struct FormatSettings formatSettings;

	format_specifier specifiers[] = {
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
		{'\0', NULL},
		/* add more specifiers */
	};


	formatSettings.flags = parse_format_flags(format, &i);
	formatSettings.width = parse_format_width(format, &i, iter);
	formatSettings.precision = parse_format_precision(format, &i, iter);

	for (i = 0; specifiers[i].specifier != '\0'; i++)
	{
		if (*format == specifiers[i].specifier)
		{
			counter += (specifiers[i].handler(iter, &formatSettings));
			break;
		}
	}

	if (specifiers[i].specifier == '\0')
		return (-1);

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
#include "main.h"

/**
* handle_char - handles character specifier for printf
* @args: va_list containing the character argument
* @formatSettings: descri
* Return: Number of characters printed
*/
int handle_char(va_list args, struct FormatSettings *formatSettings)
{
	char c = va_arg(args, int);

	/* Apply width and flags */
	if (formatSettings->flags & 1)
	{  /* Left-justify flag '-' */
		write(1, &c, 1);
		while (formatSettings->width > 1)
		{
			write(1, " ", 1);
			formatSettings->width--;
		}
	}
	else
	{
		while (formatSettings->width > 1)
		{
			write(1, " ", 1);
			formatSettings->width--;
		}
		write(1, &c, 1);
	}

	return (1);
}

/**
* handle_string - handles string specifier for printf
* @args: va_list containing the character argument
* @formatSettings: descri
* Return: Number of characters printed (length of string)
*/
int handle_string(va_list args, struct FormatSettings *formatSettings)
{
	char *str = va_arg(args, char *);
	int str_len = 0;

	if (str == NULL)
		str = "(null)";
	str_len = _strlen(str); /* Calculate string length */
	/* Apply precision */
	if (formatSettings->precision >= 0 && formatSettings->precision < str_len)
		str_len = formatSettings->precision;
	/*Apply width and flags*/
	if (formatSettings->flags & 1)  /* Left-justify flag '-' */
	{
		write(1, str, str_len);
		while (formatSettings->width > str_len)
	{
			write(1, " ", 1);
			formatSettings->width--;
		}
	}
	else if (formatSettings->flags & 4) /* Zero padding flag '0' */
	{
		while (formatSettings->width > str_len)
	{
			write(1, "0", 1);
			formatSettings->width--;
		}
		write(1, str, str_len);
	}
	else
	{
		while (formatSettings->width > str_len)
	{
			write(1, " ", 1);
			formatSettings->width--;
		}
		write(1, str, str_len);
	}
	return (str_len);
}

/**
* handle_percent - handles percent specifier for printf
* @args: va_list containing the character argument
* @formatSettings: descri
* Return: Number of characters printed (Always 1)
*/
int handle_percent(va_list args, struct FormatSettings *formatSettings)
{
	char percent = '%';
	(void)args;

	/* Apply width and flags */
	if (formatSettings->flags & 1)
	{  /* Left-justify flag '-' */
		write(1, &percent, 1);
		while (formatSettings->width > 1)
		{
			write(1, " ", 1);
			formatSettings->width--;
		}
	}

	else if (formatSettings->flags & 4)
	{  /* Zero padding flag '0' */
		while (formatSettings->width > 1)
		{
			write(1, "0", 1);
			formatSettings->width--;
		}
		write(1, &percent, 1);
	}
	else
	{
		while (formatSettings->width > 1)
		{
			write(1, " ", 1);
			formatSettings->width--;
		}
		write(1, &percent, 1);
	}

	return (1);
}

/**
* handle_int - handles integer specifier for printf
* @args: va_list containing the integer argument
* @formatSettings: descri
* Return: Number of characters printed (including -)
*/
int handle_int(va_list args, struct FormatSettings *formatSettings)
{
	int num = va_arg(args, int), i;
	char buffer[BUFFER];
	int buffer_len = 0, is_negative = 0;

	UNUSED(formatSettings);
	if (num == 0)
	{
		buffer[buffer_len++] = '0';
	}
	else
	{
		if (num < 0)
		{
			is_negative = 1;
			num = -num;
		}

		while (num > 0)
		{
			buffer[buffer_len++] = '0' + (num % 10);
			num /= 10;
		}

		if (is_negative)
		{
			buffer[buffer_len++] = '-';
		}


		for (i = 0; i < buffer_len / 2; i++)
		{
			char temp = buffer[i];

			buffer[i] = buffer[buffer_len - i - 1];
			buffer[buffer_len - i - 1] = temp;
		}
	}

	buffer[buffer_len] = '\0';
	return (write(1, buffer, buffer_len));
}




/**
* handle_unsigned - handles unsigned integer specifier for printf
* @args: va_list containing the unsigned int argument
* @formatSettings: descri
* Return: Number of characters printed (excluding -)
*/
int handle_unsigned(va_list args, struct FormatSettings *formatSettings)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[BUFFER], reversed_buffer[BUFFER];
	int i, buffer_len = 0, reversed_len = 0;

	UNUSED(formatSettings);

	do {
		buffer[buffer_len++] = '0' + (num % 10);
		num /= 10;
	} while (num > 0);

	for (i = buffer_len - 1; i >= 0; i--)
		reversed_buffer[reversed_len++] = buffer[i];

	return (write(1, reversed_buffer, reversed_len));
}
#include "main.h"

/**
* handle_binary - handles the binary specifier
* @args: va_list containing the unsigned integer argument
* @formatSettings: descri
* Return: Number of characters printed
*/
int handle_binary(va_list args, struct FormatSettings *formatSettings)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[BUFFER], *binary_str;
	int i, buffer_len = 0, binary_str_len = 0;

	UNUSED(formatSettings);

	binary_str = malloc(BUFFER * sizeof(char));
	if (binary_str == NULL)
		return (-1);

	do {
		binary_str[binary_str_len++] = '0' + (num % 2);
		num /= 2;
	} while (num > 0);

	for (i = binary_str_len - 1; i >= 0; i--)
		buffer[buffer_len++] = binary_str[i];

	free(binary_str);
	return (write(1, buffer, buffer_len));
}

/**
* handle_octal - handles the octal specifier
* @args: va_list containing the unsigned integer argument
* @formatSettings: descri
* Return: Number of characters printed
*/
int handle_octal(va_list args, struct FormatSettings *formatSettings)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[BUFFER], reversed_buffer[BUFFER];
	int i, buffer_len = 0, reversed_len = 0;

	UNUSED(formatSettings);

	do {
		buffer[buffer_len++] = '0' + (num % 8);
		num /= 8;
	} while (num > 0);

	for (i = buffer_len - 1; i >= 0; i--)
		reversed_buffer[reversed_len++] = buffer[i];

	return (write(1, reversed_buffer, reversed_len));
}


/**
* handle_hex_lower - handles the lowercase hexadecimal specifier
* @args: va_list containing the unsigned integer argument
* @formatSettings: descri
* Return: Number of characters printed
*/
int handle_hex_lower(va_list args, struct FormatSettings *formatSettings)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[BUFFER];
	int i, buffer_len = 0, remainder;

	UNUSED(formatSettings);

	do {
		remainder = num % 16;
		if (remainder < 10)
			buffer[buffer_len++] = '0' + remainder;
		else
			buffer[buffer_len++] = 'a' + (remainder - 10);
		num /= 16;
	} while (num != 0);

	for (i = buffer_len - 1; i >= 0; i--)
		write(1, &buffer[i], 1);

	return (buffer_len);
}

/**
* handle_hex_upper - handles the uppercase hexadecimal specifier
* @args: va_list containing the unsigned integer argument
* @formatSettings: descri
* Return: Number of characters printed
*/
int handle_hex_upper(va_list args, struct FormatSettings *formatSettings)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[BUFFER], reversed_buffer[BUFFER];
	int i, buffer_len = 0, remainder, reversed_len = 0;

	UNUSED(formatSettings);

	do {
		remainder = num % 16;
		if (remainder < 10)
			buffer[buffer_len++] = '0' + remainder;
		else
			buffer[buffer_len++] = 'A' + (remainder - 10);
		num /= 16;
	} while (num > 0);

	for (i = buffer_len - 1; i >= 0; i--)
		reversed_buffer[reversed_len++] = buffer[i];

	return (write(1, reversed_buffer, reversed_len));
}


/**
* handle_custom_string - handles custom string containng unprintable
* @args: va_list containing argument
* @formatSettings: descri
* Return: Number of characters printed
*/
int handle_custom_string(va_list args, struct FormatSettings *formatSettings)
{
	char *input = va_arg(args, char *);
	char buffer[BUFFER];
	int i, buffer_len = 0;

	UNUSED(formatSettings);

	for (i = 0; input[i] != '\0'; ++i)
	{
		if (input[i] >= 32 && input[i] < 127)
		{
			/* Printable characters*/
			buffer[buffer_len++] = input[i];
		}

		else
		{
			/* Non-printable characters*/
			buffer[buffer_len++] = '\\';
			buffer[buffer_len++] = 'x';
			/* Print ASCII code value in hexadecimal (always 2 characters)*/
			_itoa((int)input[i], buffer + buffer_len);
			buffer_len += 2;
		}
	}
	buffer[buffer_len] = '\0';

	return (write(1, buffer, buffer_len));
}
#include "main.h"

/**
* handle_pointer - handles the address of a pointer
* @args: va_list containing argument
* @formatSettings: descri
* Return: Number of characters printed
*/

int handle_pointer(va_list args, struct FormatSettings *formatSettings)
{
	void *ptr = va_arg(args, void *);
	uintptr_t num;
	char buffer[BUFFER];
	int buffer_len = 0, remainder, i;

	UNUSED(formatSettings);

	if (ptr == NULL)
	{
		return (write(1, "(nil)", 5));
	}

	num = (uintptr_t)ptr;


	do {
		remainder = num % 16;
		if (remainder < 10)
			buffer[buffer_len++] = '0' + remainder;
		else
			buffer[buffer_len++] = 'a' + (remainder - 10);
		num /= 16;
	} while (num != 0);

	buffer[buffer_len++] = 'x';
	buffer[buffer_len++] = '0';
	/* Write the hexadecimal string in reverse order */
	for (i = buffer_len - 1; i >= 0; i--)
	{
		write(1, &buffer[i], 1);
	}

	return (buffer_len);
}
#include "main.h"

/**
* parse_format_flags - add descr
* @format: add descr
* @index: add descr
* Return: flags
*/
int parse_format_flags(const char *format, int *index)
{
	int current_index = *index + 1;
	int flags = 0;
	const char FLAG_CHARACTERS[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAG_VALUES[] = {1, 2, 4, 8, 16, 0};

	while (format[current_index] != '\0')
	{
		int flagIndex;

		for (flagIndex = 0; FLAG_CHARACTERS[flagIndex] != '\0'; flagIndex++)
		{
			if (format[current_index] == FLAG_CHARACTERS[flagIndex])
			{
				flags |= FLAG_VALUES[flagIndex];
				break;
			}
		}

		if (FLAG_CHARACTERS[flagIndex] == '\0')
		{
			/* If the current character is not a valid flag, exit the loop */
			break;
		}

		current_index++;
	}

	*index = current_index - 1;
	return (flags);
}
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
int parse_format_width(const char *format, int *index, va_list args)
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
