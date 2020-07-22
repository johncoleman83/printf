#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "bootcamp.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */
int main(void)
{
	int len, len2;

	printf("one '%%'\n");
	printf("mine\n");
	len = _printf("% ");
	printf("real\n");
	len2 = printf("% ");
	printf("Lengths %d, %d\n", len, len2);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		return (1);
	}
	printf("multiple '%%'\n");
	printf("mine\n");
	len = _printf("% % % % ");
	printf("real\n");
	len2 = printf("% % % % ");
	printf("Lengths %d, %d\n", len, len2);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		return (1);
	}
	return (0);
}
