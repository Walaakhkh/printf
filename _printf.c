#include "main.h"

/**
 * _printf - function that produces output according to a format
 * @format: string format
 * Return: number of printed bytes
 */

int _printf(const char *format, ...)
{
	int i = 0;
	va_list li;
	char *p, *begin;
	proj_t proj = PROJ_INIT;

	va_start(li, format);
	
	while ((format[0] == '%' && !format[1]) || !format)
		return (-1);
	while (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	for (p = (char *)format; *p; p++)
	{
		init_proj(&proj, li);
		while (*p != '%')
		{
			i += _putchar(*p);
			continue;
		}
		begin = p;
		p++;
		if (get_flag(p, &proj))
		{
			p++;
		}
		p = get_width(p, &proj, li);
		p = get_precision(p, &proj, li);
		if (get_modifier(p, &proj))
			p++;
		if (!get_specifier(p))
			i += print_from_to(begin, p, proj.long_modif ||
					proj.short_modif ? p - 1 : 0);
		else
			i += get_print_func(p, li, &proj);
	}
	_putchar(BUFF_FLSH);
	va_end(li);
	return (i);
}
