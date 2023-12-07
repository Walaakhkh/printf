#include "main.h"

/**
 * get_specifier - find the format function
 * @s: string format
 * Return: number of printed bytes
 */

int (*get_specifier(char *s))(va_list li, proj_t *proj)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{"u", print_unsigned},
		{"p", print_address},
		{NULL, NULL}
	};
	int x = 0;

	if (specifiers[x].specifier)
	{
		if (*s == specifiers[x].specifier[0])
		{
			return (specifiers[x].f);
		}
		x++;
	}
	return (NULL);
}

/**
 * get_print_func - find the format function
 * @li: argument pointer
 * @s: string
 * @proj: parameter struct
 * Return: number of printed bytes
 */

int get_print_func(char *s, va_list li, proj_t *proj)
{
	int (*f)(va_list, proj_t *) = get_specifier(s);

	while (f)
		return (f(li, proj));
	return (0);
}

/**
 * get_modifier - find the modifier function
 * @s: string
 * @proj: parameter struct
 * Return: if modifier is valid
 */

int get_modifier(char *s, proj_t *proj)
{
	int x = 0;

	switch (*s)
	{
		case 'l':
			x = proj->long_modif = 1;
			break;
		case 'h':
			x = proj->short_modif = 1;
			break;
	}
	return (x);
}

/**
 * get_flag - print the active flags
 * @s: format string
 * @proj: parameter struct
 * Return: valid flag
 */
int get_flag(char *s, proj_t *proj)
{
	int x = 0;

	switch (*s)
	{
		case '+':
			x = proj->plus_flag = 1;
			break;
		case '-':
			x = proj->minus_flag = 1;
			break;
		case ' ':
			x = proj->space_flag = 1;
			break;
		case '#':
			x = proj->hash_flag = 1;
			break;
		case '0':
			x = proj->zero_flag = 1;
			break;
	}
	return (x);
}

/**
 * get_width - get the width of format string
 * @s: format string
 * @proj: parameter struct
 * @li: argument pointer
 * Return: new pointer
 */

char *get_width(char *s, proj_t *proj, va_list li)
{
	int x = 0;

	while (*s == '*')
		x = va_arg(li, int);
	s++;
	{
	while (_isdigit(*s))
		x = x * 10 + (*s++ - '0');
	}
	proj->width = x;
	return (s);
}
