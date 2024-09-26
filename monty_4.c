#include "monty.h"

/**
 * _atoi - Convert a string to an integer
 * @s: Char type string
 * @n: Pointer to the converted int
 * Return: Integer converted
 */
int _atoi(char *s, int *n)
{
	int sign = 1, resp = 0, firstNum, i;

	for (firstNum = 0; !(s[firstNum] >= 48 && s[firstNum] <= 57); firstNum++)
	{
		if (s[firstNum] == '-')
		{
			sign *= -1;
		}
	}
	for (i = firstNum; s[i] ; i++)
	{
		if (s[i] >= 48 && s[i] <= 57)
		{
			resp *= 10;
			resp += (s[i] - 48);
		}
		else
			return (-1);
	}

	*n = resp * sign;
	(void)(n);
sh: 1: :wq: not found
}
