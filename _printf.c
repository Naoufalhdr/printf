#include "main.h"
#include <stdarg.h>
#include <stdio.h>

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
		{
			_putchar(format[i]);
			count++;
		}

	}

	va_end(args);
	return (count);
}

