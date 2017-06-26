#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

/* begin standard C header files */
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

/* macros */

#define BUFSIZE 1024
#define TRUE (1 == 1)
#define FALSE !TRUE

/* structs */
/**
 * struct inventory_s - inventory of common variables needed
 * @fmt: the input format string
 * @i: index to traverse the format string
 * @args: the variadic arguments list of input arguments
 * @buffer: buffer to be written to before writing to stdout
 * @buf_index: index to traverse the buffer, also total chars written
 * @c0: character to be written to buffer
 * @c1: character checking after % character
 * @c2: character to check 2 spaces after % symbol
 * @error: indicates error or not (0 no error, 1 error)
 */
typedef struct inventory_s
{
	const char *fmt;
	unsigned int i;
	va_list *args;
	char *buffer;
	unsigned int buf_index;
	char c0;
	char c1;
	char c2;
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
	int (*func)(inventory_t *inv);
} matches_t;

/* initializing and ending functions */
int _printf(const char *format, ...);
inventory_t *build_inventory(va_list *args_list, const char *format);
int end_func(inventory_t *arg_inv);

/* custom memory allocation and buffer */
void *_calloc(unsigned int nmemb, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void write_buffer(inventory_t *inv);
void print_buffer(char *buffer);

/* string functions */
void rev_string(char *s);
int _strlen(char *s);
int _strlenconst(const char *s);
int _putchar(char c);
int puts_mod(char *str);

/* functions to match input with _printf functionality */
int (*match_specifier(inventory_t *inv))(inventory_t *inv);
int (*is_modifier(inventory_t *inv))(inventory_t *inv);

/* handles long integers */
int p_longint(inventory_t *inv);
int p_ulongint(inventory_t *inv);
int p_longoct(inventory_t *inv);
int p_longlowhex(inventory_t *inv);
int p_longuphex(inventory_t *inv);

/* handles specifier functions */
int p_char(inventory_t *inv);
int p_string(inventory_t *inv);
int p_string_hex(inventory_t *inv);
int p_pointer(inventory_t *inv);
int p_rev_string(inventory_t *inv);
int p_rot13(inventory_t *inv);
int p_percent(inventory_t *inv);
int p_int(inventory_t *inv);
int p_uint(inventory_t *inv);
int p_oct(inventory_t *inv);
int p_lowhex(inventory_t *inv);
int p_uphex(inventory_t *inv);
int p_binary(inventory_t *inv);

#endif /* end include guard for header files */
