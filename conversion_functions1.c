#include "main.h"

char *convert_binary(va_list b)
{
	int num, bit_value;
	int i, j, k;
	int bits[64];
	char *bits_str;

	num = va_arg(b, int);

	for (i = 0; num != 0; i++)
	{
		bit_value = num % 2;
		bits[i] = bit_value;
		num /= 2;
	}

	bits_str = malloc((i + 1) * sizeof(char));
	if (bits_str == NULL)
		return (NULL);

	for (j = i - 1, k = 0; j >= 0; j--, k++)
		bits_str[k] = bits[j] + '0';
	bits_str[k] = '\0';

	return (bits_str);
}
