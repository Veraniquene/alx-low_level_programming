#include "main.h"

/**
 * print_last_digit - prints the last digit of a number.
 *
 * @n: input number as an integer.
 *
 * Return: last digit.
 */
int print_last_digit(int n)
{
	int q;

	q = n % 10;
	if (q < 0)
	{
		_putchar(-q + 48);
		return (-q);
	}
	else
	{
		_putchar(q + 48);
		return (q);
	}
}
