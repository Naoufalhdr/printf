#include "main.h"

/**
 * convert_nstring - convert a string a with non-printable characters
 *                   to a string with hexadecimal representation.
 * @S: the va_list containing the input string.
 *
 * Return: a pointer to a string containing the converted string with
 *         hexadecimal representation.
 */
char *convert_nstring(va_list S)
{
	char *str, *result, *hex_value;
	int str_len;
	int count = 0, i, j = 0;

	str = va_arg(S, char *);
	str_len = _strlen(str);

	/* Calculate the number of non_printable character in the string */
	for (i = 0; i < str_len; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
			count++;
	}

	/* Allocate memory for the converted string */
	result = malloc(str_len + (count * 4) + 1);
	if (result == NULL)
		return (NULL);

	/* convert the non_printable character to \x representation */
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			result[j++] = '\\';
			result[j++] = 'x';
			hex_value = convert_char_to_hex(str[i]);
			result[j++] = hex_value[0];
			result[j++] = hex_value[1];
			free(hex_value);
		}
		else
			result[j++] = str[i];
	}
	result[j] = '\0';

	return (result);
}

/**
 * convert_memory_address - convert a memory address to a string representation
 * @p: The va_list containing the memory address.
 *
 * Return: a pointer to a string containing the memory address in hexadecimal
 *         format.
 */
char *convert_memory_address(va_list p)
{
	unsigned long int addr, temp;
	int remain, i;
	char *addr_str;
	int addr_len = 0;

	addr = (unsigned long int)va_arg(p, void *);
	temp = addr;

	/* Calculate the lenght of the address */
	while (temp != 0)
	{
		temp /= 16;
		addr_len++;
	}
	addr_len += 2;

	/* Allocate memory for the string containing the address */
	addr_str = malloc((addr_len + 1) * sizeof(char));
	if (addr_str == NULL)
		return (NULL);

	/* Convert the memory address to a string */
	addr_str[0] = '0';
	addr_str[1] = 'x';
	for (i = addr_len - 1; i >= 2; i--)
	{
		remain = addr % 16;
		if (remain < 10)
			addr_str[i] = remain + '0';
		else
			addr_str[i] = remain + 'a' - 10;
		addr /= 16;
	}
	addr_str[addr_len] = '\0';

	return (addr_str);
}

/**
 * reverse_string - reverses the string.
 * @r: a va_list containing the argument representing the string to be reversed
 *
 * Return: a pointer reversed string.
 */
char *reverse_string(va_list r)
{
	char *result, *str;
	int str_len, i;

	str = va_arg(r, char *);
	str_len = _strlen(str);

	result = malloc((str_len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);

	for (i = 0; i < str_len; i++)
		result[i] = str[str_len - 1 - i];
	result[str_len] = '\0';

	return (result);
}

/**
 * convert_rot13 - applies the rot13 cipher to a given string.
 * @R: a vaa_list containing the argument representing the string.
 *
 * Return: a pointer to the ro13'ed string.
 */
char *convert_rot13(va_list R)
{
	char *result, *str;
	int str_len, i;

	str = va_arg(R, char *);
	str_len = _strlen(str);

	result = malloc((str_len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);

	for (i = 0; i < str_len; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			result[i] = 'a' + ((str[i] - 'a' + 13) % 26);
		else if (str[i] >= 'A' && str[i] <= 'Z')
			result[i] = 'A' + ((str[i] - 'A' + 13) % 26);
		else
			result[i] = str[i];
	}
	result[str_len] = '\0';

	return (result);
}

