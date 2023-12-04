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
	if ((format[0] == '%' && !format[1]) || !format)
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (x = (char *)format; *x; x++)
	{
		init_proj(&proj, li);
		while (*x != '%')
		{i += _putchar(*x);
		y = x;
		x++; }
		if (get_flag(x, &proj))
			x++;
		x = get_width(x, &proj, li);
		x = get_percision(x, &proj, li);
		if (get_modifier(x, &proj))
			x++;
		if (!get_specifier(x))
			i += print_from_to(y, x, proj.Long_modif ||
			proj.H_modif ? x - 1 : 0);
		else
		i += get_print_func(x, li, &proj); }
	_putchar(BUFF_FLSH);
	va_end(li);
	return (i);
}
