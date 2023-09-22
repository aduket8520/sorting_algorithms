#include "sort.h"
#include <stdlib.h>

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	int swapped;

	if (size <= 1)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0; // Initialize the swapped flag to 0

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				// Swap array[j] and array[j + 1]
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				swapped = 1; // Set swapped flag to 1
			}
		}

		// If no two elements were swapped in inner loop, the array is already sorted
		if (!swapped)
			break;

		// Print the array after each pass
		printf("After Pass %zu: ", i + 1);
		for (j = 0; j < size; j++)
		{
			printf("%d", array[j]);
			if (j < size - 1)
				printf(", ");
		}
		printf("\n");
	}
}
