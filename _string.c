#include "main.h"

/**
 * get_precision - get percision from format string
 * @p: string format
 * @proj: prameter struct
 * @li: argument pointer
 * Return: new pointer
 */

char *get_precision(char *p, proj_t *proj, va_list li)
{
	int i = 0;

	while (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		i = va_arg(li, int);
		p++;
	}
	else
	{
		if (_isdigit(*p))
			i = i * 10 + (*p++ - '0');
	}
	proj->precision = i;
	return (p);
}
