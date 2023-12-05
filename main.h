#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdarg.h>
#include <unistd.h>

#define OUT_BUFF_SIZE 1024
#define BUFF_FLSH -1

#define NULL_STRING "(null)"

#define CONVERT_LOWERCASE  1
#define CONVERT_UPPERCASE  2

#define PROJ_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

/**
 * struct proj - parameters struct
 *
 * @unsign: flag with unsigned value
 * @plus_flag: if plus_flag specified
 * @space_flag: if space_flag specified
 * @hash_flag: if hash_flag specified
 * @zero_flag: if zero_flag specified
 * @minus_flag: if minus_flag specified
 *
 * @width: field width specified
 * @precision: field percision specified
 *
 * @long_modif: if long_modif specified
 * @short_modif: if short_modif specified
 */

typedef struct proj
{
	unsigned int unsign  : 1;

	unsigned int plus_flag  : 1;
	unsigned int space_flag  : 1;
	unsigned int hash_flag  : 1;
	unsigned int zero_flag :1;
	unsigned int minus_flag : 1;
	
	unsigned int width;
	unsigned int precision;

	unsigned int long_modif  :1;
	unsigned int short_modif  :1;
} proj_t;

/**
 * struct specifier - struct token
 * @specifier: format token
 * @f: function associated
 */

typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, proj_t *);
} specifier_t;

/*_put.c modules*/
int _puts(char *str);
int _putchar(int c);

/* functions.c modules */
int print_char(va_list li, proj_t *proj);
int print_string(va_list li, proj_t *proj);
int print_percent(va_list li, proj_t *proj);
int print_S(va_list li, proj_t *proj);
int print_int(va_list li, proj_t *proj);

int print_binary(va_list li, proj_t *proj);
int print_octal(va_list li, proj_t *proj);
int print_hex(va_list li, proj_t *proj);
int print_HEX(va_list li, proj_t *proj);

/* number.c modules */
int print_address(va_list li, proj_t *proj);
int print_unsigned(va_list li, proj_t *proj);
char *convert(long int num, int base, int flags, proj_t *proj);

/* _specifier.c modules */
int (*get_specifier(char *s))(va_list li, proj_t *proj);
int get_print_func(char *s, va_list li, proj_t *proj);
int get_flag(char *s, proj_t *proj);
int get_modifier(char *s, proj_t *proj);
char *get_width(char *s, proj_t *proj, va_list li);


int print_rev(va_list li, proj_t *proj);
int print_rot13(va_list li, proj_t *proj);
int print_from_to(char *begin, char *end, char *except);

int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, proj_t *proj);
int print_number_right_shift(char *str, proj_t *proj);
int print_number_left_shift(char *str, proj_t *proj);

/* _printf.c modules */
int _printf(const char *format, ...);

/* _proj.c modules */
void init_proj(proj_t *proj, va_list li);

/* _string.c modules */
char *get_precision(char *p, proj_t *proj, va_list li);

#endif
