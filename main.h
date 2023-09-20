#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);
int _print_format(const char *format, va_list args);
int _print_char(char c);
int _print_string(char *str);
int _strlen(char *s);

#endif /* MAIN_H */
