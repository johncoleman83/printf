#ifndef _BOOTCAMP_H_
#define _BOOTCAMP_H_

/* begin standard C header files */
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

/* macros */

#define BUFSIZE 1024
#define TRUE (1 == 1)
#define FALSE !TRUE
#define LOWHEX 0
#define UPHEX 1

/* structs */
/**
 * struct inventory_s - inventory of common variables needed
 * @fmt: the input format string
 * @i: index to traverse the format string
 * @args: the variadic arguments list of input arguments
 * @buffer: buffer to be written to before writing to stdout
 * @buf_index: index to traverse the buffer, also total chars written
 * @flag: notifies if there was a modifier flag
 * @space: notifies if space was printed
 * @c0: character to be written to buffer
 * @c1: character checking after % character
 * @c2: character to check 2 spaces after % symbol
 * @c3: unused for now, but may become a third specifier
 * @error: indicates error or not (0 no error, 1 error)
 */
typedef struct inventory_s
{
	const char *fmt;
	int i;
	va_list *args;
	char *buffer;
	int buf_index;
	int flag;
	int space;
	char c0;
	char c1;
	char c2;
	char c3;
	int error;
} inventory_t;

/**
 * struct matches_s - printf specifiers and paired function
 * @ch: the specifier
 * @func: pointer to the conversion specifier function
 */
typedef struct matches_s
{
	char ch;
	void (*func)(inventory_t *inv);
} matches_t;

/* initializing and ending functions */
int _printf(const char *format, ...);
inventory_t *build_inventory(va_list *args_list, const char *format);
int end_func(inventory_t *arg_inv);

/* custom memory allocation and buffer */
void *_calloc(unsigned int nmemb, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void write_buffer(inventory_t *inv);
void puts_buffer(inventory_t *inv, char *str);

/* string functions */
void rev_string(char *s);
int _strlen(char *s);
int _strlenconst(const char *s);
int _putchar(char c);
void puts_mod(char *str, unsigned int l);

/* parse and match functionality */
void (*match_specifier(inventory_t *inv))(inventory_t *inv);
void parse_specifiers(inventory_t *inv);

/* hexadecimal */
void print_hex(inventory_t *inv, unsigned long int n, int hexcase, int size);
void p_longlowhex(inventory_t *inv);
void p_longuphex(inventory_t *inv);
void p_lowhex(inventory_t *inv);
void p_uphex(inventory_t *inv);

/* integers */
void print_integers(inventory_t *inv, long int n);
void p_int(inventory_t *inv);
void p_longint(inventory_t *inv);
void print_unsign(inventory_t *inv, unsigned long int n);
void p_uint(inventory_t *inv);
void p_ulongint(inventory_t *inv);

/* octals */
void print_oct(inventory_t *inv, unsigned long int n, int size);
void p_oct(inventory_t *inv);
void p_longoct(inventory_t *inv);

/* handles specifier functions */
void p_char(inventory_t *inv);
void p_string(inventory_t *inv);
void p_string_hex(inventory_t *inv);
void p_pointer(inventory_t *inv);
void p_rev_string(inventory_t *inv);
void p_rot13(inventory_t *inv);
void p_percent(inventory_t *inv);
void p_binary(inventory_t *inv);

#endif /* end include guard for header files */
