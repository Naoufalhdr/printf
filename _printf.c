#include "main.h"

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
	int count, i, j, flag;
	char *holder;
	char *(*conversion_func)(va_list);

	va_start(args, format);
	count = 0;

	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			while (format[i + 1] == '+' || format[i + 1] == ' ' || format[i + 1] == '#')
			{
				if (format[i + 1] == '+')
					flag = 1;
				if (format[i + 1] == ' ')
					flag = 2;
				if (format[i + 1] == '#')
					flag = 3;
				i++;
			}
			conversion_func = get_conversion_specifier(format[i + 1]);
			if (conversion_func)
			{
				holder = conversion_func(args);
				j = 0;
				while (holder[j])
				{
					if (holder[0] != '-' && j == 0 && flag == 1 && (format[i + 1] == 'd' || format[i + 1] == 'i'))
						_putchar('+');
					if (holder[0] != '-' && j == 0 && flag == 2)
						_putchar(' ');
					if (holder[0] != '0' && flag == 3 && format[i + 1] == 'o')
						_putchar('0');
					if (holder[0] != '0' && flag == 3 && format[i + 1] == 'x')
					{
						_putchar('0');
						_putchar('x');
					}
					if (holder[0] != '0' && flag == 3 && format[i + 1] == 'X')
					{
						_putchar('0');
						_putchar('X');
					}
					_putchar(holder[j]);
					j++;
					count++;
					flag = 0;
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

