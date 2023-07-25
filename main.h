#ifndef MAIN_H
#define MAIN_H

#define BUFSIZE 1025
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>


/**
 * struct format_converter - a structure that associate a format specifier
 *                          string with its corresponding function conversion.
 * @specifier: a pointer to a string containing the format specifier.
 * @function: a function pointer that point to the conversion function.
 */
typedef struct format_converter
{
	char *specifier;
	char *(*function)(va_list);
} f_converter;

/* functions prototypes */
int _printf(const char *format, ...);
char *convert_char(va_list c);
char *convert_string(va_list s);
char *convert_percent(va_list percent);
char *convert_decimal(va_list d);
char *convert_unsigned(va_list u);
char *convert_to_binary(va_list b);
char *convert_to_octal(va_list o);
char *convert_char_to_hex(int x);
char *convert_to_lower_hex(va_list x);
char *convert_to_upper_hex(va_list X);
char *convert_nstring(va_list S);
char *convert_memory_address(va_list p);
char *reverse_string(va_list r);
char *(*get_conversion_specifier(char s))(va_list);
int _putchar(char c);
int _strlen(char *str);

#endif

