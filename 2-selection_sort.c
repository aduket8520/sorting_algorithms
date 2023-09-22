#include "sort.h"


void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;

	if (array == NULL || size <= 1)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
			{
				min_index = j;
			}
		}

		if (min_index != i)
		{
			swap(&array[i], &array[min_index]);

			// Print the array after each swap
			for (j = 0; j < size; j++)
			{
				printf("%d", array[j]);
				if (j < size - 1)
					printf(", ");
			}
			printf("\n");
		}
	}
}
