#include "main.h"

/**
* parse_format_flags - add descr
* @format: add descr
* @index: add descr
* Return: flags
*/
int parse_format_flags(const char *format, int *index)
{
	int current_index = *index + 1;
	int flags = 0;
	const char FLAG_CHARACTERS[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAG_VALUES[] = {1, 2, 4, 8, 16, 0};

	while (format[current_index] != '\0')
	{
		int flagIndex;

		for (flagIndex = 0; FLAG_CHARACTERS[flagIndex] != '\0'; flagIndex++)
		{
			if (format[current_index] == FLAG_CHARACTERS[flagIndex])
			{
				flags |= FLAG_VALUES[flagIndex];
				break;
			}
		}

		if (FLAG_CHARACTERS[flagIndex] == '\0')
		{
			/* If the current character is not a valid flag, exit the loop */
			break;
		}

		current_index++;
	}

	*index = current_index - 1;
	return (flags);
}
