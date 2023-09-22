#include "sort.h"


void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int lomuto_partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;

	for (int j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);

			// Print the array after each swap
			for (int k = low; k <= high; k++)
			{
				printf("%d", array[k]);
				if (k < high)
					printf(", ");
			}
			printf("\n");
		}
	}

	swap(&array[i + 1], &array[high]);
	return i + 1;
}

void quick_sort_helper(int *array, int low, int high)
{
	if (low < high)
	{
		int pi = lomuto_partition(array, low, high);
		quick_sort_helper(array, low, pi - 1);
		quick_sort_helper(array, pi + 1, high);
	}
}

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	quick_sort_helper(array, 0, size - 1);
}
