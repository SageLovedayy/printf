#include "main.h"

/**
* handle_char - handles character specifier for printf
* @args: va_list containing the character argument
* Return: Number of characters printed
*/
int handle_char(va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}

/**
* handle_string - handles string specifier for printf
* @args: va_list containing the character argument
* Return: Number of characters printed (length of string)
*/
int handle_string(va_list args)
{
	char *str = va_arg(args, char *);

	if (str == NULL)
	{
		str = "(null)";
	}

	return (write(1, str, _strlen(str)));
}

/**
* handle_percent - handles percent specifier for printf
* @args: va_list containing the character argument
* Return: Number of characters printed (Always 1)
*/
int handle_percent(va_list args)
{
	char percent = '%';
	(void)args;

	return (write(1, &percent, 1));
}

/**
* handle_int - handles integer specifier for printf
* @args: va_list containing the integer argument
* Return: Number of characters printed (including -)
*/
int handle_int(va_list args)
{
	int num = va_arg(args, int);
	/* Maximum length for an integer string representation (including '-' sign) */
	char buffer[12];
	int buffer_len = 0;

	/* Handle zero as a special case */
	if (num == 0)
	{
		buffer[buffer_len++] = '0';
	}

	else
	{
		/* Handle negative numbers */
		if (num < 0)
		{
			buffer[buffer_len++] = '-';
			num = -num;
		}

		/* Convert the integer to a string in reverse order */
		while (num > 0)
		{
			buffer[buffer_len++] = '0' + (num % 10);
			num /= 10;
		}

		/* Reverse the string to get the correct order */
		for (int i = 0; i < buffer_len / 2; i++)
		{
			char temp = buffer[i];

			buffer[i] = buffer[buffer_len - i - 1];
			buffer[buffer_len - i - 1] = temp;
		}
	}
	/* Write the buffer to stdout */
	int chars_written = write(1, buffer, buffer_len);
	/* Return the number of characters written or -1 in case of an error */
	return ((chars_written == buffer_len) ? chars_written : -1);
}




/**
* handle_unsigned - handles unsigned integer specifier for printf
* @args: va_list containing the unsigned int argument
* Return: Number of characters printed (excluding -)
*/
int handle_unsigned(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[BUFFER], reversed_buffer[BUFFER];
	int i, buffer_len = 0, reversed_len = 0;

	do {
		buffer[buffer_len++] = '0' + (num % 10);
		num /= 10;
	} while (num > 0);

	for (i = buffer_len - 1; i >= 0; i--)
		reversed_buffer[reversed_len++] = buffer[i];

	return (write(1, reversed_buffer, reversed_len));
}
