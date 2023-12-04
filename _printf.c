#include "main.h"

/**
 * _printf - print everything
 * @format: character string
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list li;
	int i = 0;
	char *x, *y;
	proj_t proj = PROJ_INIT;

	va_start(li, format);

	while (format && format[i] != '\0')
	{
		if 
