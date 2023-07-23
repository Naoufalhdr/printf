# _printf Project
_printf is a custom implementation of the C standard library printf function. It allows you to produce output according to a format string with support for various conversion specifiers.
## Description
The _printf function has the following prototype:
int _printf(const char *format, ...);
### Supported Conversion Specifiers
The _printf function supports the following conversion specifiers:
- %c: Print a character
- %s: Print a string
- %%: Print a literal %
- %d and %i: Print a decimal integer
- %u: Print an unsigned decimal integer
- %o: Print an octal integer
- %r: Print a reversed string
- %R: Print a rot13'ed string
### Custom Conversion Specifiers
You can extend the _printf function by adding more custom conversion specifiers. To do this, you need to define new conversion functions in conversion_functions.c and add corresponding entries to the conversion_list array in utility_functions.c.
## Project Structure
- main.c: Contains the main function for testing the _printf function.
- _printf.c: Contains the implementation of the _printf function.
- _printf.h: Contains function prototypes and the conversion_specifier_t struct.
- utility_functions.c: Contains utility functions such as _putchar, _puts, and get_conversion_specifier.
- conversion_functions.c: Contains the conversion functions for each supported conversion specifier.
## Compilation and Testing
Compile the project using the provided compilation command. Run the executable and check the output to verify the correctness of the _printf function.
## Authors
- Naoufal Hadra - Initial work
## Acknowledgments
This project was inspired by the C printf function from the standard library.
