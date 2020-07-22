#include <stdio.h>
#include <stdlib.h>
#include "bootcamp.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */
int main(void)
{
	int len, len2;

	len = _printf("% d", -1024);
	len2 = printf("% d", -1024);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		return (1);
	}
	return (0);
}
