#include "main.h"

/**
 * get_spec_func - Finds the appropriate print function for a given specifier.
 *
 * @spec: Specifier to find a print function for.
 *
 * Return: Pointer to the print function correspoding to @spec, or NULL
 * function does not exists.
 */
static int (*get_spec_func(char spec))(va_list)
{
	static specifier_t specs[] = {
		{'c', print_char},
		{'s', print_str},
		{'%', print_percent},
		{'d', print_int},
		{'i', print_int},
		{'u', print_unsigned},
		{'o', print_octal},
		{'x', print_hex},
		{'X', print_HEX},
		{'\0', NULL}
	};

	int i;

	for (i = 0; specs[i].spec != '\0'; i++)
	{
		if (spec == specs[i].spec)
			return (specs[i].func);
	}

	return (NULL);
}

/**
 * _printf - Custom printf function
 * @format: a character string containing zero or more directives
 *
 * Return: the number of characters printed (excluding the null byte
 * used to end output of strings)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0, i;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			int (*func)(va_list);

			i++;

			func = get_spec_func(format[i]);
			
			if (func != NULL)
				count += func(args);
			else if (format[i] != '\0')
			{
				count += _putchar('%');
				count += _putchar(format[i]);
			}
		}
		else
		{
			count += _putchar(format[i]);
		}
	}

	va_end(args);

	return (count);
}

/**
 * print_char - function to print a char
 * @arg: A va_list containing the next argument of type char
 * 
 * Return: the number of characters printed
 */
int print_char(va_list arg)
{
	char c = va_arg(arg, int);

	return (_putchar(c));
}

/**
 * print_str - function to print a string
 * @arg: a va_list containing the next argument type of char *
 *
 * Return: the number of characters printed
 */
int print_str(va_list arg)
{
	char *str = va_arg(arg, char *);
	int i;

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);

	return (i);
}

/**
 * print_percent - a function to print a percent symbol
 * @arg: a va_list containing no argument
 *
 * Return: number of characters printed
 */
int print_percent(va_list arg)
{
	int length = 1;
	(void)arg;
	_putchar('%');
	return length;
}
