#include "main.h"

int handle_char(va_list args)
{
	char c = va_arg(args, int);
	return write(1, &c, 1);
}

int handle_string(va_list args)
{
	char *str = va_arg(args, char *);
	return write(1, str, _strlen(str));
}

int handle_percent(va_list args)
{
	char percent = '%';
	(void)args;

	return write(1, &percent, 1);
}

int handle_int(va_list args)
{
	int i, num = va_arg(args, int), buffer_len = 0, num_str_len = 0;
	char buffer[BUFFER], *num_str;

	if (num < 0)
	{
		buffer[buffer_len++] = '-';
		num = -num;
	}

	num_str = malloc(BUFFER * sizeof(char));
	if (num_str == NULL)
		return (-1);

	do
	{
		num_str[num_str_len++] = '0' + (num % 10);
		num /= 10;
	} while (num > 0);

	for (i = num_str_len - 1; i >= 0; i--)
		buffer[buffer_len++] = num_str[i];

	free(num_str);
	return write(1, buffer, buffer_len);
}

int handle_unsigned(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[BUFFER], reversed_buffer[BUFFER];
	int i, buffer_len = 0, reversed_len = 0;

	do
	{
		buffer[buffer_len++] = '0' + (num % 10);
		num /= 10;
	} while (num > 0);

	for (i = buffer_len - 1; i >= 0; i--)
		reversed_buffer[reversed_len++] = buffer[i];

	return write(1, reversed_buffer, reversed_len);
}
