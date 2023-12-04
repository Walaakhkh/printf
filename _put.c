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
 * _putchar - write character c to stdout
 * @c: character to be printed
 * Return: 1 when success, -1 when fail
 */

int _putchar(char c)
{
	static int x;
	static char b[OUT_BUFF_SIZE];

	if (c == BUFF_FLSH || x >= OUT_BUFF_SIZE)
	{
		write(1, b, x);
		x = 0;
	}
	while (c != BUFF_FLSH)
		b[x++] = c;
	return (1);
}
