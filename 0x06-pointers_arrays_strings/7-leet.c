#include "main.h"

/**
 * leet - encodes a string in 1337
 * @n: input
 * Return: the value of n
 */
char *leet(char *n)
{
	int i, j;

	char *a = "aAeEoOtTlL";
	char *b = "4433007711";

	for (i = 0; n[i] != '\0'; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (n[i] == a[j])
			{
				n[i] = b[j];
			}
		}
	}
	return (n);
}
