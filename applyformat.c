#include "main.h"

/**
* apform - applies formatting
* @buffer: add descr
* @buffer_len: add descr
* @formatSettings: descri
* Return: Number of characters printed (Always 1)
*/
int apform(char *buffer, int buffer_len, struct FormatSettings *formatSettings)
{
	int padding = 0;
	int total_width, i;

	/* Apply precision */
	if (formatSettings->precision > buffer_len)
	{
		padding = formatSettings->precision - buffer_len;
	}
	/* Calculate total width considering width, precision, and content length */
	if (formatSettings->width > buffer_len + padding)
		total_width = buffer_len + padding;
	else
		total_width = formatSettings->width;
	/* Write padding before the content (if any) */
	if (!(formatSettings->flags & 1) && !(formatSettings->flags & 4))
	{/* If not left-justify and not zero padding */
		for (i = 0; i < formatSettings->width - total_width; ++i)
		{
			write(1, " ", 1);
		}
	}
	/* Write padding before the content (if zero padding) */
	if ((formatSettings->flags & 4) && !(formatSettings->flags & 1))
	{/* If zero padding (and not left-justify) */
		for (i = 0; i < padding; ++i)
			write(1, "0", 1);
	}
	/* Write the content */
	write(1, buffer, buffer_len);

	/* Write padding after the content (if any) */
	if (formatSettings->flags & 1)
	{ /* If left-justify */
		for (i = 0; i < formatSettings->width - total_width; ++i)
		{
			write(1, " ", 1);
		}
	}

	return (total_width);
}
