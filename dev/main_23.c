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

	len = _printf("% d", INT_MAX);
	len2 = printf("% d", INT_MAX);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		return (1);
	}
	return (0);
}
