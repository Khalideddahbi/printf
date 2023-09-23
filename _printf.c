<<<<<<< HEAD
#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(list, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}
	print_buffer(buffer, &buff_ind);
	va_end(list);
	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
=======
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
>>>>>>> dbc8b7edd74e0b499ced7cb06e46b369a88a73df
}

