#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>

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
char *(*get_conversion_specifier(char s))(va_list);
int _putchar(char c);

#endif

