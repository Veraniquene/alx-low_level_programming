#include "main.h"

/**
 * _islower - checks if the character is lowercase
 * 0
 *
 * @c: a character argument
 *
 * Return: 1 for lowercase character. 0 for the rest.
 */
int _islower(int c)
{

	if (c >= 97 && c <= 122)
	{
		return (1);
	}
	else
	{
		return (0);
	}
	_putchar('\n');
}
