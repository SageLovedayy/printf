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
