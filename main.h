#ifndef _MAIN_H_
#define _MAIN_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h> /* for comparing our printf in our main.c */

#define BUFFER 1024

int _printf(const char *format, ...);

typedef struct {
	char specifier;  /* c, s, d, i... */
	int (*handler)(va_list args);
} format_specifier;

int handle_char(va_list args);
int handle_string(va_list args);
int handle_percent(va_list args);
int handle_int(va_list args);

int _strlen(char *s);

#endif /*_MAIN_H_*/
