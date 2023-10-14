#include "main.h"

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
	{'\0', NULL},
	/* add more specifiers */
};

int _printf(const char *format, ...)
{
	unsigned int count = 0, i;
	va_list args;

	va_start(args, format);


	while (*format && (*format != '\0'))
	{
		if (*format == '%')
		{
			format++;
			for (i = 0; specifiers[i].specifier != '\0'; i++)
			{
				if (*format == specifiers[i].specifier)
				{
					count += specifiers[i].handler(args);
					break;
				}
			}
		}
		else
			count += write(1, format, 1);
		format++;
	}

	va_end(args);
	return count;
}
