#include "main.h"

/**
* handle_binary - handles the binary specifier
* @args: va_list containing the unsigned integer argument
* Return: Number of characters printed
*/
int handle_binary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[BUFFER], *binary_str;
	int i, buffer_len = 0, binary_str_len = 0;

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
* Return: Number of characters printed
*/
int handle_octal(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[BUFFER], reversed_buffer[BUFFER];
	int i, buffer_len = 0, reversed_len = 0;

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
* Return: Number of characters printed
*/
int handle_hex_lower(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[BUFFER];
	int i, buffer_len = 0, remainder;

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
* Return: Number of characters printed
*/
int handle_hex_upper(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[BUFFER], reversed_buffer[BUFFER];
	int i, buffer_len = 0, remainder, reversed_len = 0;

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



int handle_custom_string(va_list args) {
    char *input = va_arg(args, char *);
    char buffer[BUFFER];
    int i, buffer_len = 0;

    for (i = 0; input[i] != '\0'; ++i)
    {
        if (input[i] >= 32 && input[i] < 127)
	{
            /* Printable characters*/
            buffer[buffer_len++] = input[i];
        } else {
            /* Non-printable characters*/
            buffer[buffer_len++] = '\\';
            buffer[buffer_len++] = 'x';
            /* Print ASCII code value in hexadecimal (always 2 characters)*/
            _itoa((int)input[i], buffer + buffer_len);
            buffer_len += 2;
        }
    }
    buffer[buffer_len] = '\0';

    return write(1, buffer, buffer_len);
}
