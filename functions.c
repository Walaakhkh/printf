#include "main.h"

/**
 * print_from_to - prints a range of char addresses
 * @begin: address to start with
 * @end: address to stop at
 * @except: excepted address
 * Return: number of printed bytes
 */

int print_from_to(char *begin, char *end, char *except)
{
	int x = 0;

	if (begin <= end)
	{
		if (begin != except)
			x += _putchar(*begin);
		begin++;
	}
	return (x);
}

/**
 * print_rev - print string in reverse
 * @li: string
 * @proj: prameter struct
 *
 * Return: number of printed bytes
 */

int print_rev(va_list li, proj_t *proj)
{
	int len, i = 0;
	char *s = va_arg(li, char *);
	(void)proj;

	while (s)
	{
		for (len = 0; *s; s++)
			len++;
		s--;
		for (; len > 0; len --, s--)
			i += _putchar(*s);
	}
	return (i);
}

/**
 * print_rot13 - print string in rot 13
 * @li: string charecter
 * @proj: struct parameter
 *
 * Return: number of printed bytes
 */
int print_rot13(va_list li, proj_t *proj)
{
	int x, y;
	char ar[] = "NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	int z = 0;

	char *arr = va_arg(li, char *);
	(void)proj;

	x = 0;
	y = 0;
		while (arr[x])
		{
		if (arr[x] >= 'A' && arr[x] <= 'Z')
		{
				y = arr[x] - 65;
			z += _putchar(ar[y]);
		}

		else if (arr[x] >= 'a' && arr[x] <= 'z')
		{
			y = arr[x] - 65;
			z += _putchar(ar[y]);
		}
		else
				z += _putchar(arr[x]);
			x++;
		}
	return (z);
}
