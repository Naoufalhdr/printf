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
