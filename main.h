#ifndef _MAIN_H_
#define _MAIN_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include <ctype.h>
#include <stdbool.h>

#define UNUSED(x) (void)(x)
#define BUFFER 1024

int _printf(const char *format, ...);


/**
* struct FormatSettings - handles Formatsettings
* @flags: I will add description
* @width: Remember to add description
* @precision: remember to add desc
*/
struct FormatSettings
{
	int flags;
	int width;
	int precision;

};

/**
* struct format_specifier_struct - associates format specifiers with handlers
* @specifier: character representing specific format specifier
* @handler: pointer to function that handles specified format
*/
struct format_specifier_struct
{
	char specifier;  /* c, s, d, i... */
	int (*handler)(va_list args, struct FormatSettings *formatsettings);
};

extern struct FormatSettings formatSettings;
typedef struct format_specifier_struct format_specifier;

int handle_char(va_list args, struct FormatSettings *formatSettings);
int handle_string(va_list args, struct FormatSettings *formatSettings);
int handle_percent(va_list args, struct FormatSettings *formatSettings);
int handle_int(va_list args, struct FormatSettings *formatSettings);
int handle_unsigned(va_list args, struct FormatSettings *formatSettings);

int handle_binary(va_list args, struct FormatSettings *formatSettings);
int handle_octal(va_list args, struct FormatSettings *formatSettings);
int handle_hex_lower(va_list args, struct FormatSettings *formatSettings);
int handle_hex_upper(va_list args, struct FormatSettings *formatSettings);
int handle_custom_string(va_list args, struct FormatSettings *formatSettings);
int handle_pointer(va_list args, struct FormatSettings *formatSettings);
int handle_rot13(va_list args, struct FormatSettings *formatSettings);

int parse_format_flags(const char *format, int *index);
int parse_format_width(const char *format, int *index, va_list list);
int parse_format_precision(const char *format, int *index, va_list list);


int _strlen(char *s);
void _itoa(int value, char *output);
int is_digit(char c);

#endif /*_MAIN_H_*/
