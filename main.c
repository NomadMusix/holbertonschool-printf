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
	int len, len2;
	len = _printf("%");
	len2 = printf("%");
	printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}
