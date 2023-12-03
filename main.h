#ifndef MAIN_H
#define MAIN_H
#define BUFF_SIZE 1024
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _putchar(char c);
int _printf(const char *format, ...);

int print_char(va_list types, char buffer[], int flags, int width,
	int precision, int size);
int print_string(va_list types, char buffer[], int flags, int width,
	int precision, int size);
int print_percent(va_list types, char buffer[], int flags, int width,
	int precision, int size);

int handle_print(const char *fmt, int *i, ...);

#endif
