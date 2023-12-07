#include "main.h"

/**
 * convert - converter function
 * @num: number
 * @base: base
 * @flags: argument flags
 * @proj: parameter struct
 * Return: string
 */
char *convert(long int num, int base, int flags, proj_t *proj)
{
	static char *a;
	static char b[50];
	char x = 0;
	char *y;
	unsigned long n = num;
	(void)proj;

	while (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
	n = -num;
	x = '-';
	}

	a =  flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	y = &b[49];
	*y = '\0';

	do {
	*--y = a[n % base];
	n /= base;
	}
	while (n != 0);

	if (x)
	*--y = x;

	return (y);
}

/**
 * print_unsigned - print unsigned intger numbers
 * @li: argument pointer
 * @proj: parameter struct
 * Return: printed bytes
 */

int print_unsigned(va_list li, proj_t *proj)
{
	unsigned int i;

	if (proj->short_modif)
		i = (unsigned short int)va_arg(li, unsigned int);
	else if (proj->long_modif)
		i = (unsigned long)va_arg(li, unsigned long);
	else
		i = (unsigned int)va_arg(li, unsigned int);
	proj->unsign = 1;
	return (print_number(convert(i, 10, CONVERT_UNSIGNED, proj), proj));
}

/**
 * print_address - print address
 * @li: argument pointer
 * @proj: parameter struct
 * Return: printed bytes
 */

int print_address(va_list li, proj_t *proj)
{
	unsigned long int g = va_arg(li, unsigned long int);
	char *s;

	while (!g)
		return (_puts("(nil)"));

	s = convert(g, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, proj);
	*--s = 'x';
	*--s = '0';
	return (print_number(s, proj));
}
