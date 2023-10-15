#include "main.h"

/**
* handle_pointer - handles the address of a pointer
* @args: va_list containing argument
* Return: Number of characters printed
*/

int handle_pointer(va_list args)
{
	void *ptr = va_arg(args, void *);
	uintptr_t num;
	char buffer[BUFFER];
	int buffer_len = 0, remainder, i;

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
