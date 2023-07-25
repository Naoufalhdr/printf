#include "main.h"

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
		{"b", convert_to_binary},
		{"o", convert_to_octal},
		{"x", convert_to_lower_hex},
		{"X", convert_to_upper_hex},
		{"S", convert_nstring},
		{"p", convert_memory_address},
		{"r", reverse_string},
		{"R", convert_rot13},
		{NULL, NULL}
	};

	for (i = 0; formats_converter[i].specifier; i++)
	{
		if (s == *(formats_converter[i].specifier))
			return (formats_converter[i].function);
	}

	return (NULL);
}

/**
 * _strlen - calculate the lenght of the string.
 * @str: a pointer to the string
 *
 * Return: the number of character in the string except null terminator.
 */
int _strlen(char *str)
{
	int len;

	len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
}

/**
 * convert_char_to_hex - convert an integer to it's two_digit hexadecimal value
 * @x: the intger value to be converted.
 *
 * Return: a pointer string containing the hexadecimal value of x.
 */
char *convert_char_to_hex(int x)
{
	unsigned int num, temp;
	int i, remain, hex_len = 0;
	char *hex_str;

	num = x;
	temp = num;

	/* Calculate the lenght of the hex representaion */
	if (num == 0)
		hex_len = 1;
	else
	{
		while (temp != 0)
		{
			temp /= 16;
			hex_len++;
		}
	}
	/* Allocate memory for the hex string */
	hex_str = malloc(3);
	if (hex_str == NULL)
		return (NULL);
	/* Convert the number to it's hex representation */
	for (i = 1; i >= 0; i--)
	{
		remain = num % 16;
		if (remain < 10)
			hex_str[i] = remain + '0';
		else
			hex_str[i] = remain - 10 + 'A';
		num /= 16;
	}
	hex_str[2] = '\0';

	return (hex_str);
}
