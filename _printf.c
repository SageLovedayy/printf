#include "main.h"

int _printf(const char *format, ...)
{
	unsigned int count = 0, i;
	va_list args;
	format_specifer specifiers[] = {
		{'c', handle_char},
		{'s', handle_string},
		/* add more: got this from your cent task we discussed in pld :D */
	};

	va_start(args, format);


	while (*format)
	{
		if (*format == '%')
		{
			format++;
			/*sizeof(specifiers) / sizeof(specifiers[0]) to calculate the number of element
			* we would replace it later with the number of element since sizeof is allowed */
			for (i = 0; i < sizeof(specifiers) / sizeof(specifiers[0]); i++)
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
