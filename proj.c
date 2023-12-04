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

	proj->Plus_flag = 0;
	proj->Space_flag = 0;
	proj->Hash_flag = 0;
	proj->Zero_flag = 0;
	proj->Minus_flag = 0;

	proj->Long_modif = 0;
	proj->H_modif = 0;

	proj->Width = 0;
	proj->Percision = UINT_MAX;
	(void)li;
}
