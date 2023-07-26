#include "main.h"

/**
 * convert_char - converts a character argument to a string.
 * @c: the va_list containing the character argument to be converted.
 *
 * Return: a 2 byte string contained the character.
 */

char *convert_char(va_list c)
{
	char *result;

	result = (char *)malloc(2);
	if (result == NULL)
		return (NULL);

	result[0] = va_arg(c, int);
	result[1] = '\0';

	return (result);
}

/**
 * convert_string - convert a string argument from va_list.
 * @s: the va_list containing the string argument to be converted.
 *
 * Return: a pointer to the string, otherwise if string is NULL: "(nil)".
 */

char *convert_string(va_list s)
{
	char *result;

	result = va_arg(s, char *);
	if (result == NULL)
		return ("(null)");
	return (result);
}

/**
 * convert_percent - return a string containing '%' character.
 * @percent: a va_list, but not used in this function.
 *
 * Return: a pointer to a string containing '%'.
 */

char *convert_percent(va_list percent)
{
	(void)percent;
	return ("%");
}

/**
 * convert_decimal - convert a decimal integer into a string.
 * @d: the decimal integer to be converted.
 *
 * Return: a pointer to the string representation of the decimal integer.
 */

char *convert_decimal(va_list d)
{
	int n, n_len = 0, tmp, i, is_negative = 0, size;
	char *result;

	n = va_arg(d, int);
	tmp = n;
	/* Checks if the integer is negative or not*/
	if (n < 0)
	{
		n *= -1;
		is_negative = 1;
	}
	/* count the number of digits in the integer */
	if (n == 0)
		n_len = 1;
	else
	{
		while (tmp != 0)
		{
			tmp /= 10;
			n_len++;
		}
	}
	/* Allocate memory for the string */
	size = n_len + is_negative;
	result = (char *)malloc((size + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	/* Convert the decimal integer to a string */
	for (i = size - 1; i >= 0; i--)
	{
		result[i] = (n % 10) + '0';
		n /= 10;
	}
	if (is_negative)
		result[0] = '-';
	result[size] = '\0';

	return (result);
}

/**
 * convert_unsigned - convert an unsigned integer to a string.
 * @u: the unsigned integer to convert.
 *
 * Return: a pointer to the string represent the unsigned integer.
 */

char *convert_unsigned(va_list u)
{
	unsigned int n, n_len, tmp, i;
	char *result;

	n = va_arg(u, unsigned int);
	tmp = n;
	n_len = 0;

	/* count the number of digits in the unsigned integer */
	if (tmp == 0)
		n_len = 1;
	else
	{
		while (tmp != 0)
		{
			tmp /= 10;
			n_len++;
		}
	}

	/* Allocate memory for the string */
	result = (char *)malloc((n_len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);

	/* Convert the unsigned integer to a string */
	for (i = n_len - 1; i > 0; i--)
	{
		result[i] = (n % 10) + '0';
		n /= 10;
	}
	result[0] = (n % 10) + '0';
	result[n_len] = '\0';

	return (result);
}
