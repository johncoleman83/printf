#include "bootcamp.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len, len2, i, j;
    void *addr;
	char *superlong, *filler;

	filler = "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Donec quam felis, ultricies nec, pellentesque eu, pretium quis, sem. Nulla consequat massa quis enim. Donec. ";

	superlong = calloc(4090, sizeof(char));
	i = 0, j = 0;
	while (i < 4089)
	{
		if (filler[j] == '\0')
			j = 0;
		superlong[i++] = filler[j++];
	}
	superlong[i] = '\0';


	_printf("************ Testing Standard Functionality ***************\n");
    _printf("________Order_______\nmy _printf() first.\n");
    printf("standard printf() second.\n");
	_printf("compile with following command\ngcc -Wall -Werror -Wextra -pedantic -w *.c\n");

	len = _printf("\n\nSuperLong: %s\n", superlong);
	len2 = printf("\n\nSuperLong: %s\n", superlong);
    _printf("\n\nMy Length: [%d, %i]\n", len, len);
    printf("Length: [%d, %i]\n", len2, len2);

	free(superlong);

    len = _printf("Negative: [%d]\n", -762534);
    len2 = printf("Negative: [%d]\n", -762534);
    _printf("My Length: [%d, %i]\n", len, len);
    printf("Length: [%d, %i]\n", len2, len2);

    _printf("Unsigned: [%u]\n", UINT_MAX);
    printf("Unsigned: [%u]\n", UINT_MAX);
    _printf("Unsigned octal: [%o]\n", UINT_MAX);
    printf("Unsigned octal: [%o]\n", UINT_MAX);

    len = _printf("hexadecimal: [%x, %X]\n", 5555, 33333);
    len2 = printf("hexadecimal: [%x, %X]\n", 5555, 33333);
    _printf("My Length: [%d, %i]\n", len, len);
    printf("Length: [%d, %i]\n", len2, len2);

    len = _printf("Unsigned max hexadecimal: [%x, %X]\n", UINT_MAX, UINT_MAX);
    len2 = printf("Unsigned max hexadecimal: [%x, %X]\n", UINT_MAX, UINT_MAX);
    _printf("My Length: [%d, %i]\n", len, len);
    printf("Length: [%d, %i]\n", len2, len2);

    len = _printf("hexadecimal with '#': [%#x, %#X]\n", 5555, 33333);
    len2 = printf("hexadecimal with '#': [%#x, %#X]\n", 5555, 33333);
    _printf("My Length: [%d, %i]\n", len, len);
    printf("Length: [%d, %i]\n", len2, len2);

    len = _printf("oct with #: [%#o, %#o]\n", 5555, 33333);
    len2 = printf("oct with #: [%#o, %#o]\n", 5555, 33333);
    _printf("My Length: [%d, %i]\n", len, len);
    printf("Length: [%d, %i]\n", len2, len2);

    _printf("Unsigned Short: [%hu]\n", USHRT_MAX);
    printf("Unsigned Short: [%hu]\n", USHRT_MAX);
    _printf("Unsigned octal Short: [%ho]\n", USHRT_MAX);
    printf("Unsigned octal Short: [%ho]\n", USHRT_MAX);

	len = _printf("Unsigned hexadecimal Short: [%hx, %hX]\n", USHRT_MAX, USHRT_MAX);
    len2 = printf("Unsigned hexadecimal Short: [%hx, %hX]\n", USHRT_MAX, USHRT_MAX);
    _printf("My Length: [%d, %i]\n", len, len);
    printf("Length: [%d, %i]\n", len2, len2);

	_printf("Unsigned long: [%lu]\n", ULONG_MAX);
    printf("Unsigned long: [%lu]\n", ULONG_MAX);
    _printf("Unsigned long octal: [%lo]\n", ULONG_MAX);
    printf("Unsigned long octal: [%lo]\n", ULONG_MAX);
    _printf("Unsigned long hexadecimal: [%lx, %lX]\n", ULONG_MAX, ULONG_MAX);
    printf("Unsigned long hexadecimal: [%lx, %lX]\n", ULONG_MAX, ULONG_MAX);

	len = _printf("long max: %ld\n", LONG_MAX);
	len2 = printf("long max: %ld\n", LONG_MAX);
    _printf("My Length: [%d, %i]\n", len, len);
    printf("Length: [%d, %i]\n", len2, len2);

	len = _printf("long min: %ld\n", LONG_MIN);
	len2 = printf("long min: %ld\n", LONG_MIN);
    _printf("My Length: [%d, %i]\n", len, len);
    printf("Length: [%d, %i]\n", len2, len2);

	len = _printf("another test: %hX - %hX = %hX\n", USHRT_MAX, 2048, USHRT_MAX - 2048);
	len2 = printf("another test: %hX - %hX = %hX\n", USHRT_MAX, 2048, USHRT_MAX - 2048);
    _printf("My Length: [%d, %i]\n", len, len);
    printf("Length: [%d, %i]\n", len2, len2);

	_printf("Character: [%c]\n", 'H');
    printf("Character: [%c]\n", 'H');

	len = _printf("NULL Character here: '[%c]'\n", '\0');
    len2 = printf("NULL Character here: '[%c]'\n", '\0');
    _printf("My Length: [%d, %i]\n", len, len);
    printf("Length: [%d, %i]\n", len2, len2);

	len = _printf("int with '+' flag: %+d\n", 1234);
	len2 = printf("int with '+' flag: %+d\n", 1234);
	_printf("My Length: [%d]\n", len);
    printf("Length: [%d]\n", len2);

	len = _printf("int with '+' flag and ' ' spaces: % + d\n", 1234);
	len2 = printf("int with '+' flag and ' ' spaces: % + d\n", 1234);
	_printf("My Length: [%d]\n", len);
    printf("Length: [%d]\n", len2);

	len = _printf("int with '+' flag and ' ' multi-spaces: %   +   d\n", 1234);
	len2 = printf("int with '+' flag and ' ' multi-spaces: %   +   d\n", 1234);
	_printf("My Length: [%d]\n", len);
    printf("Length: [%d]\n", len2);

	len = _printf("String: [%s]\n", "Upward Not Northward !");
    len2 = printf("String: [%s]\n", "Upward Not Northward !");
    _printf("My Length: [%d, %i]\n", len, len);
    printf("Length: [%d, %i]\n", len2, len2);

	len = _printf("Empty String: [%s]\n", "");
    len2 = printf("Empty String: [%s]\n", "");
    _printf("My Length: [%d, %i]\n", len, len);
    printf("Length: [%d, %i]\n", len2, len2);

    addr = (void *)0x7ffe637541f0;
	len = _printf("Address: [%p]\n", addr);
    len2 = printf("Address: [%p]\n", addr);
    _printf("My Length: [%d, %i]\n", len, len);
    printf("Length: [%d, %i]\n", len2, len2);

	_printf("\n\n****************** debugging *******************\n");
	printf("NULL checks:\n");
    len = _printf(NULL);
	len2 = printf(NULL);
    _printf("My Length: [%d, %i]\n", len, len);
    printf("Length: [%d, %i]\n", len2, len2);

	printf("\n*** checking '%%' 'hldx' w/ no args ***\n");
    len = _printf("try 'h' %h\n");
	len2 = printf("try 'h' %h\n");
    _printf("My Length: [%d, %i]\n", len, len);
    printf("Length: [%d, %i]\n", len2, len2);
    len = _printf("try 'l' %l\n");
	len2 = printf("try 'l' %l\n");
    _printf("My Length: [%d, %i]\n", len, len);
    printf("Length: [%d, %i]\n", len2, len2);
    len = _printf("try 'd' %d\n");
	len2 = printf("try 'd' %d\n");
    _printf("My Length: [%d, %i]\n", len, len);
    printf("Length: [%d, %i]\n", len2, len2);
    len = _printf("try 'x' %x\n");
	len2 = printf("try 'x' %x\n");
    _printf("My Length: [%d, %i]\n", len, len);
    printf("Length: [%d, %i]\n", len2, len2);
	printf("\n*** checking '%%' 'ds' with spaces ***\n");
    len = _printf("1 space 'd' % d\n", 98);
	len2 = printf("1 space 'd' % d\n", 98);
    _printf("My Length: [%d, %i]\n", len, len);
    printf("Length: [%d, %i]\n", len2, len2);
    len = _printf("1 space 's' % s\n", "battery");
	len2 = printf("1 space 's' % s\n", "battery");
    _printf("My Length: [%d, %i]\n", len, len);
    printf("Length: [%d, %i]\n", len2, len2);
    len = _printf("5 spaces 'd' %     d\n", 98);
	len2 = printf("5 spaces 'd' %     d\n", 98);
    _printf("My Length: [%d, %i]\n", len, len);
    printf("Length: [%d, %i]\n", len2, len2);
    len = _printf("5 spaces 's' %     s\n", "battery");
	len2 = printf("5 spaces's' %     s\n", "battery");
    _printf("My Length: [%d, %i]\n", len, len);
    printf("Length: [%d, %i]\n", len2, len2);
    len = _printf("5 spaces 'c' %     c\n", 'b');
	len2 = printf("5 spaces 'c' %     c\n", 'b');
    _printf("My Length: [%d, %i]\n", len, len);
    printf("Length: [%d, %i]\n", len2, len2);
	printf("\n*** checking NULL ***\n");


	len = _printf("NULL string: %s\n", NULL);
	len2 = printf("NULL string: %s\n", NULL);
    _printf("My Length: [%d, %i]\n", len, len);
    printf("Length: [%d, %i]\n", len2, len2);

    len = _printf("NULL pointer: %p\n", NULL);
	len2 = printf("NULL pointer: %p\n", NULL);
    _printf("My Length: [%d, %i]\n", len, len);
    printf("Length: [%d, %i]\n", len2, len2);

	len = _printf("test print %% + 'r' with no args: [%%r]\n");
	_printf("test print %% + 'd' with no args: [%%d]\n");
    len2 = printf("test print %% + 'r' with no args: [%%r]\n");
	printf("test print %% + 'd' with no args: [%%d]\n");
    _printf("My Length: [%d, %i]\n", len, len);
    printf("Length: [%d, %i]\n", len2, len2);


	_printf("custom print this '%%hy\\n' next: ");
    len = _printf("%hy\n");
	printf("std print this '%%hy\\n' next: ");
	len2 = printf("%hy\n");
	_printf("My Length: [%d]\n", len);
	printf("Length: [%d]\n", len2);

	_printf("print one '%%' here:");
    len = _printf("%");
	printf("\nprint one '%%' here:");
	len2 = printf("%");
	_printf("My Length: [%d]\n", len);
    printf("Length: [%d]\n", len2);

	_printf("print trailing '%%' here:\n");
    len = _printf("testing this %");
	printf("print trailing '%%' here:\n");
	len2 = printf("testing this %");
	_printf("My Length: [%d]\n", len);
    printf("Length: [%d]\n", len2);

	_printf("print '%%!\\n' then '%%K\\n' next: ");
	len = _printf("%!\n");
	printf("print '%%!\\n' then '%%K\\n' next: ");
	len2 = printf("%!\n");
	_printf("My Length: [%d]\n", len);
    printf("Length: [%d]\n", len2);

	len = _printf("%K\n");
	len2 = printf("%K\n");
	_printf("My Length: [%d]\n", len);
    printf("Length: [%d]\n", len2);

	_printf("\n***********CUSTOM _PRINTF FUNCTIONALITY************\n");
	len = _printf("Reverse, 'hello!': [%r]\n", "hello!");
	len = _printf("rot13 of 'Bootcamp', expected 'Ubyoregba': [%R]\n", "Bootcamp");
	len = _printf("reversed 1 char: [%r]\n", "c");
	len = _printf("binary, expected: '1100010' - %b\n", 98);

	return (0);
}
