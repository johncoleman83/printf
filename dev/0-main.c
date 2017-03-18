#include "holberton.h"
/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;

	len = _printf("custom     |Let's try to printf a simple sentence.\n");
	len2 = printf("standard   |Let's try to printf a simple sentence.\n");
	printf("custom     |Len :[%d, %i]\n", len, len);
	printf("standard   |Len2:[%d, %i]\n", len2, len2);
	len = _printf("custom     |testing char 'c': %c char 8899: %c\n", 'c', 8899);
	len2 = printf("stdlib     |testing char 'c': %c char 8899: %c\n", 'c', 8899);
	printf("custom     |Len :[%d, %i]\n", len, len);
	printf("standard   |Len2:[%d, %i]\n", len2, len2);
	len = _printf("custom     |testing: string 'string': %s\n", "string");
	len2 = printf("stdlib     |testing: string 'string': %s\n", "string");
	printf("custom     |Len :[%d, %i]\n", len, len);
	printf("standard   |Len2:[%d, %i]\n", len2, len2);
	len = _printf("custom     |testing: percent %%\n");
	len2 = printf("stdlib     |testing: percent %%\n");
	printf("custom     |Len :[%d, %i]\n", len, len);
	printf("standard   |Len2:[%d, %i]\n", len2, len2);
	return (0);
}
