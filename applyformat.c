#include "main.h"

/**
* apform - applies formatting
* @buffer: add descr
* @buffer_len: add descr
* @format_setting: descri
* Return: Number of characters printed (Always 1)
*/
int apform(char *buffer, int buffer_len, format_setting_t *format_setting)
{
	int padding = 0;
	int total_width, i;

	/* Apply precision */
	if (format_setting->precision > buffer_len)
	{
		padding = format_setting->precision - buffer_len;
	}
	/* Calculate total width considering width, precision, and content length */
	if (format_setting->width > buffer_len + padding)
		total_width = buffer_len + padding;
	else
		total_width = format_setting->width;
	/* Write padding before the content (if any) */
	if (!(format_setting->flags & 1) && !(format_setting->flags & 4))
	{/* If not left-justify and not zero padding */
		for (i = 0; i < format_setting->width - total_width; ++i)
		{
			write(1, " ", 1);
		}
	}
	/* Write padding before the content (if zero padding) */
	if ((format_setting->flags & 4) && !(format_setting->flags & 1))
	{/* If zero padding (and not left-justify) */
		for (i = 0; i < padding; ++i)
			write(1, "0", 1);
	}
	/* Write the content */
	write(1, buffer, buffer_len);

	/* Write padding after the content (if any) */
	if (format_setting->flags & 1)
	{ /* If left-justify */
		for (i = 0; i < format_setting->width - total_width; ++i)
		{
			write(1, " ", 1);
		}
	}

	/* oringinaly returns total_width */
	return (buffer_len);
}
