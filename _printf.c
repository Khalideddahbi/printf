#include <unistd.h>
#include <stdarg.h>
#include "main.h"
#include <stdio.h>
/**
 * _printf - printf function
 * @format: Format string
 *
 * Return: Number of char
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
			char_count += write(1, format, 1);
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == 'c')
			{
				char c = va_arg(args, int);

				char_count += write(1, &c, 1);
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);

				if (str == NULL)
					str = "(null)";
				while (*str)
				{
					char_count += write(1, str, 1);
					str++;
				}
			}
			else if (*format == '%')
				char_count += write(1, "%", 1);
		}
		format++;
	}
	va_end(args);
	return (char_count);
}
