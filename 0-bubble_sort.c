#include "sort.h"
#include <stdlib.h>

/**
 * swap_integers - Swap two integers in an array.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 *
 * This function swaps the values of two integers pointed to by @a and @b.
 */
void swap_integers(int *a, int *b)
{
	int temp;

	if (a && b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
}



/**
 * bubble_sort - sort an array using the bubble sort algorithm
 * @array: the array
 * @size: the size of the array
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (size <= 1)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_integers(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}


	}
}

