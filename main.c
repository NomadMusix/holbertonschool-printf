#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * main - entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len1 = 0, len2 = 0;

	len1 = _printf("%");
	len2 = printf("%");
	printf ("len1: %d\n", len1);
	printf ("len2: %d\n", len2);
	if (len1 != len2)
	{
		printf("Lengths differ.\n");
		return (1);
	}
	return (0);
}
