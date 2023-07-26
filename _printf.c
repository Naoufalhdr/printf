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
	int count, i, j, k, width_flag, holder_len;
	int plus_flag = 0, space_flag = 0, hash_flag = 0, zero_flag = 0;
	char *holder;
	char *(*conversion_func)(va_list);
	int width = 0;

	va_start(args, format);
	count = 0;

	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			while (format[i + 1] == '+' || format[i + 1] == ' ' || format[i + 1] == '#' || format[i + 1] == '0')
			{
				if (format[i + 1] == '+')	
					plus_flag = 1;
				else if (format[i + 1] == ' ')
					space_flag = 2;
				else if (format[i + 1] == '#')
					hash_flag = 3;
				else if (format[i + 1] == '0')
					zero_flag = 4;
				i++;
			}
			if (format[i + 1] >= '1' && format[i + 1] <= '9')
			{
				width_flag = 1;
				width = format[i + 1] - '0';
				i++;
				while (format[i + 1] >= '0' && format[i + 1] <= '9')
				{
					width = width * 10 + (format[i + 1] - '0');
					i++;
				}
			}
			conversion_func = get_conversion_specifier(format[i + 1]);
			if (conversion_func)
			{
				holder = conversion_func(args);
				holder_len = _strlen(holder);
				j = 0;
				while (holder[j] != '\0')
				{
					if (holder[0] != '-' && j == 0 && plus_flag && (format[i + 1] == 'd' || format[i + 1] == 'i'))
					{
						_putchar('+');
						holder_len++;
					}
					if (holder[0] != '-' && j == 0 && space_flag && (format[i + 1] == 'd' || format[i + 1] == 'i'))
					{
						_putchar(' ');
						holder_len++;
					}
					if (holder[0] != '0' && hash_flag && format[i + 1] == 'o')
						_putchar('0');
					if (holder[0] != '0' && hash_flag && format[i + 1] == 'x')
					{
						_putchar('0');
						_putchar('x');
					}
					if (holder[0] != '0' && hash_flag && format[i + 1] == 'X')
					{
						_putchar('0');
						_putchar('X');
					}
					if (width_flag == 1 && width > holder_len)
					{
							for (k = 0; k < width - holder_len; k++)
							{
								if (zero_flag == 4)
									_putchar('0');
								else
									_putchar(' ');
							}
					}
					_putchar(holder[j]);
					j++;
					count++;
					plus_flag = 0;
					space_flag = 0;
					hash_flag = 0;
					zero_flag = 0;
					width_flag = 0;
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
