#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes a character to the standard output.
 * @c: the character to be written.
 *
 * Return: on success, the number of char written 1,
 *         on error -1 is returned.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - print a buffer.
 * @buffer: buffer passed
 * @size: number of bytes to print
 */
void _puts(char *buffer, int size)
{
	write(1, buffer, size);
}

/**
 * get_conversion_specifier - Get the corresponding conversion function for
 *                            a format specifier.
 * @s: the format specifier char to look for.
 * 
 * Return: a pointer to the conversion function assiciated with the format
 *         specifier.
 */
char *(*get_conversion_specifier(char s))(va_list)
{
	int i;
	f_converter formats_converter[] = {
		{"c", convert_char},
		{"s", convert_string},
		{"%", convert_percent},
		{"d", convert_decimal},
		{"i", convert_decimal},
		{"u", convert_unsigned},
		{NULL, NULL}
	};

	for (i = 0; formats_converter[i].specifier; i++)
	{
		if (s == *formats_converter[i].specifier)
			return (formats_converter[i].function);
	}

	return (NULL);
}
