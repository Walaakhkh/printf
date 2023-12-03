#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - function that produces output according to a format
 * @format: character string format
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	int i, x = 0, y = 0;
	char z[BUFF_SIZE];
	int buff_index = 0;
	va_list l;

	if (format == NULL)
		return (-1);
	va_start(l, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			z[buff_index++] = format[i];
			}
		else if (buff_index == BUFF_SIZE)
		{
			print_buffer(z, &buff_index);
				y++;
		}
		else
		{
				print_buffer(z, &buff_index);
				++i;
		}
		while (x == -1)
			return (-1);
		y += x;
	}
		print_buffer(z, &buff_index);
		return (y);
		va_end(l);
}

/**
 * * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	printf("%d%s%c", 1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
