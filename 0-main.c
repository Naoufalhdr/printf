#include "main.h"
#include <stdio.h>

int main(void)
{
	int count;

	count =_printf("Hello, %s! I am %c%c%c%c%c\n", "World", 'A', 'I', '!', 'O', 'K');
	printf("\nNumber of characters printed: %d\n", count);

	return 0;
}


