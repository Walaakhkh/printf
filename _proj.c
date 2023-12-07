#include "main.h"

/**
 * init_proj - clear struct fields and reset buffer
 * @proj: parameters struct
 * @li: argument pointer
 * Return: void
 */
void init_proj(proj_t *proj, va_list li)
{
	proj->unsign = 0;

	proj->plus_flag = 0;
	proj->space_flag = 0;
	proj->hash_flag = 0;
	proj->zero_flag = 0;
	proj->minus_flag = 0;
	
	proj->width = 0;
	proj->precision = UINT_MAX;

	proj->long_modif = 0;
	proj->short_modif = 0;
	(void)li;
}
