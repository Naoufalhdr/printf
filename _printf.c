#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - custom implementation of the printf function.
 * @format: a character string containing the format specifier
 *          and optional arguments.
 * @...: Optional arguments corresponding to the format specifiers
 *       in the format string.
 * Return: The number of characters printed (excluding the null byte).
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count, i;
	char *holder;
	char *(*conversion_func)(va_list);

	va_start(args, format);
	count = 0;

	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			conversion_func = get_conversion_specifier(format[i + 1]);
			if (conversion_func)
			{
				holder = conversion_func(args);
				while (*holder)
				{
					_putchar(*holder);
					holder++;
					count++;
				}
				i++;
			}
			else
				_putchar(format[i]);
		}
		else
		{
			_putchar(format[i]);
			count++;
		}

	}

	va_end(args);
	return (count);
}

