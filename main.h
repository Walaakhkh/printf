#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdarg.h>
#include <unstd.h>

#define OUT_BUFF_SIZE 1024
#define BUFF_FLSH -1

#define NULL_STRING "(null)"

#define CONVERT_LOWERCASE  1
#define CONVERT_UPPERCASE  2

int _puts(char *str);
int _putchar(char c);

int _printf(const char *format, ...);
int print_char(va_list li, proj_t *proj);
int print_string(va_list li, proj_t *proj);
int print_percent(va_list li, proj_t *proj);

int print_int(va_list li, proj_t *proj);

int print_binary(va_list li, proj_t *proj);

int print_unsigned(va_list li, proj_t *proj);
int print_octal(va_list li, proj_t *proj);
int print_hex(va_list li, proj_t *proj);
int print_HEX(va_list li, proj_t *proj);

int print_S(va_list li, proj_t *proj);

int print_address(va_list li, proj_t *proj);

char *convert(long int num, int base, int flags, proj_t *proj);

#define PROJ_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

/**
 * struct project - project struct
 *
 * @unsign: flag with unsigned value
 * @Plus_flag: if Plus_flag specified
 * @Space_flag: if Space_flag specified
 * @Hash_flag: if _flag specified
 * @Zero_flag: if _flag specified
 * @Minus_flag: if _flag specified
 *
 * @Width: field width specified
 * @Percision: field percision specified
 *
 * @Long_modif: if Long_modif specified
 * @H_modif: if H_modif specified
 *
 */

typedef struct project
{
	unsigned int unsign  : 1;

	unsigned int Plus_flag  : 1;
	unsigned int Space_flag  : 1;
	unsigned int Hash_flag  : 1;

	unsigned int Long_modif  :1;
	unsigned int H_modif  :1;

	unsigned int Width;

	unsigned int Percision;

	unsigned int Zero_flag :1;

	unsigned int Minus_flag :1;
} proj_t;

/**
 * struct specifier - struct token
 * @specifier: format token
 * @F: function associated
 */

typedef struct specifier
{
	char *specifier;
	int (*F)(va_list, proj_t *);
} specifier_t;

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

void init_proj(proj_t *proj, va_list li);

char *get_percision(char *p, proj_t *proj, va_list li);

#endif
