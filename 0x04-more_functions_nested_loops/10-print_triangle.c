#include "main.h"

/**
 * print_triangle - prints a triangle.
 * @size: numbers of lines.
 * Return: no return.
 */
void print_triangle(int size)
{
	int p, q;

	for (p = 0; p < size; p++)
	{
		for (q = 1; q < (size - p); q++)
			_putchar(' ');
		for (q--; q < size; q++)
			_putchar(35);
		if (p < (size - 1))
			_putchar('\n');
	}
	_putchar('\n');
}
