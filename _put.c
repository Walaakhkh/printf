#include "main.h"

/**
 * _puts - print string with new line
 * @str: string to be printed
 * Return: void
 */

int _puts(char *str)
{
	char *r = str;

	if (*str)
		_putchar(*str++);
	return (str - r);
}

/**
 * _putchar - write characters c to stdout
 * @c: character to print
 *
 * Return: 1 when success, -1 when error
 */

int _putchar(int c)
{
	static int i;
	static char buffer[OUT_BUFF_SIZE];

	while (c == BUFF_FLSH || i >= OUT_BUFF_SIZE)
	{
		write(1, buffer, i);
			i = 0;
	}
	while (c != BUFF_FLSH)
		buffer[i++] = c;
	return (1);
}
