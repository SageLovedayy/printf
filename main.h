#ifndef _MAIN_H_
#define _MAIN_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#define BUFFER 1024

int _printf(const char *format, ...);


/**
* struct format_specifier_struct - associates format specifiers with handlers
* @specifier: character representing specific format specifier
* @handler: pointer to function that handles specified format
*/

struct format_specifier_struct
{
	char specifier;  /* c, s, d, i... */
	int (*handler)(va_list args);
};

typedef struct format_specifier_struct format_specifier;

int handle_char(va_list args);
int handle_string(va_list args);
int handle_percent(va_list args);
int handle_int(va_list args);
int handle_unsigned(va_list args);

int handle_binary(va_list args);
int handle_octal(va_list args);
int handle_hex_lower(va_list args);
int handle_hex_upper(va_list args);
int handle_custom_string(va_list args);

int _strlen(char *s);
void _itoa(int value, char *output);

#endif /*_MAIN_H_*/
