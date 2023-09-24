#include "sort.h"
#include <stdlib.h>

/**
 * bubble_sort - sort an array using the bubble sort algorithm
 * @array: the array
 * @size: the size of the array
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	if (size <= 1)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}

		print_array(array, size);
	}
}
