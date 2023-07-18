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
	int len1, len2;
	len1 = _printf("%");
	printf("\n\n");
	len2 = printf("%");
	printf("\n%d\n%d\n", len1, len2);
	return (0);
}
