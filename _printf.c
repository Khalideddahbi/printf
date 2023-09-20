#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _putchar - Write a character to stdout
 * @c: The character to print
 *
 * Return: Number of characters printed (1)
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strlen - Calculate the length of a string
 * @s: The string to measure
 *
 * Return: The length of the string
 */
int _strlen(const char *s)
{
	int len = 0;

	while (s[len])
	{
		len++;
	}
	return (len);
}

/**
 * print_str - Print a string to stdout
 * @str: The string to print
 *
 * Return: Number of characters printed
 */
int print_str(char *str)
{
	int char_count = 0;

	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		char_count += _putchar(*str);
		str++;
	}
	return (char_count);
}

/**
 * print_int - Print an integer to stdout
 * @n: The integer to print
 *
 * Return: Number of characters printed
 */
int print_int(int n)
{
	char buffer[20];
	int i = 0;
	int char_count = 0;

	if (n == 0)
	{
		return (_putchar('0'));
	}
	while (n != 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (i > 0)
	{
		char_count += _putchar(buffer[--i]);
	}
	return (char_count);
}

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int char_count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			char_count += _putchar(*format);
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == 'c')
			{
				char c = va_arg(args, int);

				char_count += _putchar(c);
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);

				char_count += print_str(str);
			}
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(args, int);

				char_count += print_int(num);
			}
			else if (*format == '%')
			{
				char_count += _putchar('%');
			}
		}
		format++;
	}
	va_end(args);
	return (char_count);
}

