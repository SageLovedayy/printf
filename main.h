#ifndef _MAIN_H_
#define _MAIN_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h> /* because of sizeof function :( */

int _printf(const char *format, ...);

typedef struct {
	char specifier;  /* c, s, d, i... */
	int (*handler)(va_list args);
} format_specifer;

int handle_char(va_list args);
int handle_string(va_list args);
int handle_percent(va_list args);

int _strlen(char *s);

#endif /*_MAIN_H_*/
