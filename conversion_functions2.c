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
