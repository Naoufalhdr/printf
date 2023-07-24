#include "main.h"

/**
 * convert_to_binary - convert an unsigned integer to binary.
 * @b: a variable argument list containing an unsigned int to be converted.
 *
 * Return: a pointer to string containing the binary representation of
 *         the unsigned integer.
 */
char *convert_to_binary(va_list b)
{
	unsigned int num, bit_value;
	int i, j, k;
	int bits[32];
	char *bits_str;

	num = va_arg(b, unsigned int);

	/* Converting the number to binary */
	for (i = 0; num != 0; i++)
	{
		bit_value = num % 2;
		bits[i] = bit_value;
		num /= 2;
	}
	/* Allocating memory for the binary string based on the number of bits*/
	bits_str = malloc((i + 1) * sizeof(char));
	if (bits_str == NULL)
		return (NULL);

	/* Copying the elements in the bits[32] into the bits_str string */
	for (j = i - 1, k = 0; j >= 0; j--, k++)
		bits_str[k] = bits[j] + '0';
	bits_str[k] = '\0';

	return (bits_str);
}

/**
 * convert_to_octal - convert an unsigned integer to it's octal representation.
 * @o: a variable argument list containing an unsigned int to be converted.
 *
 * Return: a pointer to a string containing the octal representation.
 */
char *convert_to_octal(va_list o)
{
	unsigned int num, temp;
	int i;
	int octal_len = 0;
	char *octal_str;

	num = va_arg(o, unsigned int);
	temp = num;

	/* Calculate the lenght of the octal representations of the digit */
	if (num == 0)
		octal_len = 1;
	else
	{
		while (temp != 0)
		{
			temp /= 8;
			octal_len++;
		}
	}

	/* Allocate the memory for the octal string */
	octal_str = malloc((octal_len + 1) * sizeof(char));
	if (octal_str == NULL)
		return (NULL);

	/* convert the unsigned integer into octal representation */
	for (i = octal_len - 1; i >= 0; i--)
	{
		octal_str[i] = (num % 8) + '0';
		num /= 8;
	}
	octal_str[octal_len] = '\0';

	return (octal_str);

}

/**
 * convert_to_hex - convert an integer to it's hexadecimal representation.
 * @x: the argument list containing the unsigned int to be converted.
 * @letter_case: an integer flag indicating wether 0 if lowercase,
 *               or 1 if uppercase
 *
 * Return: a pointer to a string containing the hexadecimal representation.
 */
char *convert_to_hex(va_list x, int letter_case)
{
	unsigned int num, temp;
	int i, remain, hex_len = 0;
	char *hex_str;

	num = va_arg(x, unsigned int);
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
	hex_str = malloc((hex_len + 1) * sizeof(char));
	if (hex_str == NULL)
		return (NULL);
	/* Convert the number to it's hex representation */
	for (i = hex_len - 1; i >= 0; i--)
	{
		remain = num % 16;
		if (remain < 10)
			hex_str[i] = remain + '0';
		else
		{
			if (letter_case)
				hex_str[i] = remain - 10 + 'A';
			else
				hex_str[i] = remain - 10 + 'a';
		}
		num /= 16;
	}
	hex_str[hex_len] = '\0';

	return (hex_str);
}

/**
 * convert_to_lower_hex - convert an unsigned integer to it's hexadecimal
 *                        representation. (in lowercase)
 * @x: the argument list containing the unsigned int to convert.
 *
 * Return: a pointer to a string containing the hexadecimal representation
 *         in lowercase.
 */
char *convert_to_lower_hex(va_list x)
{
	return (convert_to_hex(x, 0));
}

/**
 * convert_to_upper_hex - convert an unsigned integer to it's hexadecimal
 *                        representation. (in uppercase)
 * @X: the argument list containing the unsigned int to convert.
 *
 * Return: a pointer to a string containing the hexadecimal representation
 *         in uppercase.
 */
char *convert_to_upper_hex(va_list X)
{
	return (convert_to_hex(X, 1));
}
