/**
* handle_string - handles string specifier for printf
* @args: va_list containing the character argument
* @formatSettings: descri
* Return: Number of characters printed (length of string)
*/
int handle_string(va_list args, struct FormatSettings *formatSettings)
{
	char *str = va_arg(args, char *);
	int str_len = 0;

	if (str == NULL)
		str = "(null)";
	str_len = _strlen(str); /* Calculate string length */
	/* Apply precision */
	if (formatSettings->precision >= 0 && formatSettings->precision < str_len)
		str_len = formatSettings->precision;
	/*Apply width and flags*/
	if (formatSettings->flags & 1)  /* Left-justify flag '-' */
	{
		write(1, str, str_len);
		while (formatSettings->width > str_len)
		{
			write(1, " ", 1);
			formatSettings->width--;
		}
	}
	else if (formatSettings->flags & 4) /* Zero padding flag '0' */
	{
		while (formatSettings->width > str_len)
		{
			write(1, "0", 1);
			formatSettings->width--;
		}
		write(1, str, str_len);
	}
	else
	{
		while (formatSettings->width > str_len)
		{
			write(1, " ", 1);
			formatSettings->width--;
		}
		write(1, str, str_len);
	}
	return (str_len);
}
