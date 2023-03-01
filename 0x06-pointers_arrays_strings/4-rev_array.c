#include "main.h"
/**
 * reverse_array - reverses the content of an array
 * of integers.
 * @a: array.
 * @n: number of elements of the array.
 * Return: no return.
 */

void reverse_array(int *a, int n)
{
	int p, q, temp;

	for (p = 0; p < n - 1; p++)
	{
		for (q = p + 1; q > 0; q--)
		{
			temp = *(a + q);
			*(a + q) = *(a + (q - 1));
			*(a + (q - 1)) = temp;
		}
	}
}
