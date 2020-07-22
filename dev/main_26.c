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
	long int l = INT_MIN;

	l -= 1024;
	len = _printf("% d", l);
	len2 = printf("% d", l);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		return (1);
	}
	return (0);
}
