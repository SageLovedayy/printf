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

/**
* handle_rot13 - handles rot13
* @args: va_list containing argument
* @formatSettings: descri
* Return: Number of bytes written
*/
int handle_rot13(va_list args, struct FormatSettings *formatSettings)
{
	char *input = va_arg(args, char *);
	char buffer[BUFFER];
	int buffer_len = 0;
	int i, bytes_written;

	UNUSED(formatSettings);

	if (input == NULL)
	{
		return (-1);
	}

	for (i = 0; input[i] != '\0'; ++i)
	{
		char c = input[i];

		if (isalpha(c))
		{
			char base = isupper(c) ? 'A' : 'a';

			buffer[buffer_len++] = (c - base + 13) % 26 + base;
		}
		else
		{
			buffer[buffer_len++] = c;
		}
	}

	buffer[buffer_len] = '\0';

	bytes_written = write(1, buffer, buffer_len);
	if (bytes_written < 0)
	{
		return (-1);
	}

	return (bytes_written);
}


