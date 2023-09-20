#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - printf function
 * @format: Format
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int char_count = 0;

	va_start(args, format);
	char_count = _print_format(format, args);
	va_end(args);

	return (char_count);
}

/**
 * _print_format - Print formatted
 * @format: Format string
 * @args: Variables
 *
 * Return: Number of char
 */
int _print_format(const char *format, va_list args)
{
	int char_count = 0;

	while (*format)
	{
		if (*format != '%')
		{
			char_count += write(1, format, 1);
		}
		else
		{
			format++;
			if (*format == 'c')
				char_count += _print_char(va_arg(args, int));
			else if (*format == 's')
				char_count += _print_string(va_arg(args, char *));
			else if (*format == '%')
				char_count += write(1, "%", 1);
		}
		format++;
	}
	return (char_count);
}

/**
 * _print_char - Print a char
 * @c: Character to print
 *
 * Return: Number of characters
 */
int _print_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * _print_string - Print a string
 * @s: String to print
 *
 * Return: Number of characters
 */
int _print_string(char *s)
{
	if (!s)
		s = "(null)";
	return (write(1, s, _strlen(s)));
}

/**
 * _strlen - Calculate the length
 * @s: The input
 *
 * Return: Length
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s++)
		len++;
	return (len);
}
