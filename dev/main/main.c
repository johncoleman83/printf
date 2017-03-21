#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
/**
 * main - main file to test for expected output of printf()
 * Return: Always 0
 */
int main(void)
{
// COMPILE with no -W flags, EXPECT MULTIPLE WARNINGS, then execute file to test
	int len;

	len = printf("long string long string long string long string long string \
long string long string long string long string long string long string \
long string long string long string long string long string long string \
long string long string long string long string long string long string \
long string long string long string long string long string long string \
long string long string long string long string long string long string \
long string long string long string long string long string long string \
long string long string long string long string long string long string \
long string long string long string long string long string long string \
long string long string long string long string long string long string \
long string long string long string long string long string long string \
long string long string long string long string long string long string \
long string long string long string long string long string long string \
long string long string long string long string long string long string \
long string long string long string long string long string long string \
long string long string long string long string long string long string \
long string long string long string long string long string long string \
long string long string long string long string long string long string \
long string long string long string long string long string long string \
long string long string long string long string long string long string\n");
	printf("Len :[%d]\n", len);

	len = printf("Let's try to printf a simple sentence:\n");
	printf("Len :[%d]\n", len);

	len = printf("'c': %c char 9999: %c:\n", 'c', 9999);
	printf("Len :[%d]\n", len);

	len = printf("'string': %     s NULL: %s:\n", "string", NULL);
	printf("Len :[%d]\n", len);

	len = printf("percent: 1:%% 5:%%%%%, unknown directive: %y:\n");
	printf("Len :[%d]\n", len);

	len = printf("spaces after %%: %     s, spaces with no directive:%        :\n", "string");
	printf("Len :[%d]\n", len);

	len = printf("percent:\%  :quote:\" quote:'hi' backslash: \\ :\n");
	printf("Len :[%d]\n", len);

	len = printf("integer: %d, max:%i, too large %i, char: %d, NULL: %d:\n", 1024, INT_MAX, 999999999999, 'c', NULL);
	printf("Len :[%d]\n", len);

	len = printf("hex: %x, max:%x, too large %X, char: %x, NULL: %X:\n", 31, UINT_MAX, 999999999999, 'c', NULL);
	printf("Len :[%d]\n", len);

	len = printf("oct: %o, max:%o, too large %o, char: %o, NULL: %o:\n", 31, UINT_MAX, 999999999999, 'c', NULL);
	printf("Len :[%d]\n", len);

	len = printf("oct: %u, max:%u, too large %u, char: %u, NULL: %u:\n", 31, UINT_MAX, 999999999999, 'c', NULL);
	printf("Len :[%d]\n", len);

	len = printf("reversed string: CANNOT TEST WITH PRINTF\n");

	len = printf("rot13: CANNOT TEST WITH ROT13\n");
	len = printf("CANNOT TEST FOR BINARY:\n");
	return (0);
}
