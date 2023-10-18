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
int handle_string(va_list args, struct FormatSettings *formatSettings) {
	char *str = va_arg(args, char *);
	int str_len = (str != NULL) ? _strlen(str) : 6; /* Default length for "(null)" */

	/* Apply precision */
	if (formatSettings->precision >= 0 && formatSettings->precision < str_len) {
		str_len = formatSettings->precision;
	}

	/* Call apply_format to handle width, precision, and padding */
	return apform(str, str_len, formatSettings);
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
	int num = va_arg(args, int), i, bytes_written;
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
			buffer[buffer_len++] = '-';
		for (i = 0; i < buffer_len / 2; i++)
		{
			char temp = buffer[i];

			buffer[i] = buffer[buffer_len - i - 1];
			buffer[buffer_len - i - 1] = temp;
		}
	}
	buffer[buffer_len] = '\0';
	/*16/10/23*/
	bytes_written = (write(1, buffer, buffer_len));

	if (bytes_written < 0)
		return (-1);

	return (bytes_written);
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
