#include "main.h"

int handle_binary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[BUFFER], *binary_str;
	int i, buffer_len = 0, binary_str_len = 0;

	binary_str = malloc(BUFFER * sizeof(char));
	if(binary_str == NULL)
		return -1;

	do
	{
		binary_str[binary_str_len++] = '0' + (num % 2);
		num /= 2;
	} while (num > 0);

	for (i = binary_str_len - 1; i >= 0; i--)
		buffer[buffer_len++] = binary_str[i];

	free(binary_str);
	return write(1, buffer, buffer_len);
}

int handle_octal(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[BUFFER], reversed_buffer[BUFFER];
	int i, buffer_len = 0, reversed_len = 0;

	do
	{
		buffer[buffer_len++] = '0' + (num % 8);
		num /= 8;
	} while (num > 0);

	for (i = buffer_len - 1; i >= 0; i--)
		reversed_buffer[reversed_len++] = buffer[i];

	return write(1, reversed_buffer, reversed_len);
}

int handle_hex_lower(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[BUFFER], reversed_buffer[BUFFER];
	int i, buffer_len = 0, remainder, reversed_len = 0;

	do
	{
		remainder = num % 16;
		if (remainder < 10)
			buffer[buffer_len++] = '0' + remainder;
		else
			buffer[buffer_len++] = 'a' + (remainder - 10);
		num /= 16;
	} while (num /= 16);

	for (i = buffer_len - 1; i >= 0; i--)
		reversed_buffer[reversed_len++] = buffer[i];

	return write(1, reversed_buffer, reversed_len);
}


int handle_hex_upper(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[BUFFER], reversed_buffer[BUFFER];
	int i, buffer_len = 0, remainder, reversed_len = 0;

	do
	{
		remainder = num % 16;
		if (remainder < 10)
			buffer[buffer_len++] = '0' + remainder;
		else
			buffer[buffer_len++] = 'A' + (remainder - 10);
		num /= 16;
	} while (num > 0);

	for (i = buffer_len - 1; i >= 0; i--)
		reversed_buffer[reversed_len++] = buffer[i];

	return write(1, reversed_buffer, reversed_len);
}
