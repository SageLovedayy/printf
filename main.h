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
* format_setting_t - handles format_setting
* @flags: I will add description
* @width: Remember to add description
* @precision: remember to add desc
*/
typedef struct FormatSetting_s
{
	int flags;
	int width;
	int precision;
} format_setting_t;

/**
* struct format_specifier_struct - associates format specifiers with handlers
* @specifier: character representing specific format specifier
* @handler: pointer to function that handles specified format
*/
typedef struct format_specifier_s
{
	char spec;  /* c, s, d, i... */
	int (*handler)(va_list args, format_setting_t *format_setting);
} format_specifier_t;

extern format_setting_t format_setting;

int handle_char(va_list args, format_setting_t *format_setting);
int handle_string(va_list args, format_setting_t *format_setting);
int handle_percent(va_list args, format_setting_t *format_setting);
int handle_int(va_list args, format_setting_t *format_setting);
int handle_unsigned(va_list args, format_setting_t *format_setting);

int handle_binary(va_list args, format_setting_t *format_setting);
int handle_octal(va_list args, format_setting_t *format_setting);
int handle_hex_lower(va_list args, format_setting_t *format_setting);
int handle_hex_upper(va_list args, format_setting_t *format_setting);
int handle_custom_string(va_list args, format_setting_t *format_setting);
int handle_pointer(va_list args, format_setting_t *format_setting);
int handle_rot13(va_list args, format_setting_t *format_setting);
int handle_reverse(va_list args, format_setting_t *format_setting);

int parse_format_flags(const char *format, int *index);
int parse_format_width(const char *format, int *index, va_list list);
int parse_format_precision(const char *format, int *index, va_list list);

int apform(char *buffer, int buffer_len,
	   format_setting_t *format_setting);

int _strlen(char *s);
void _itoa(int value, char *output);
int _putchar(char c);
int is_digit(char c);

#endif /*_MAIN_H_*/
