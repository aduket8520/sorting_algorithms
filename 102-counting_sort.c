#include "sort.h"
#include <stdlib.h>

void counting_sort(int *array, size_t size)
{
    if (array == NULL || size <= 1)
        return;

    // Find the maximum value in the array
    int max = array[0];
    for (size_t i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    // Create a counting array of size (max + 1)
    int *count_array = (int *)malloc((max + 1) * sizeof(int));
    if (count_array == NULL)
        return;

    // Initialize the counting array with zeros
    for (int i = 0; i <= max; i++)
    {
        count_array[i] = 0;
    }

    // Count the occurrences of each element in the original array
    for (size_t i = 0; i < size; i++)
    {
        count_array[array[i]]++;
    }

    // Print the counting array
    printf("Counting array: ");
    for (int i = 0; i <= max; i++)
    {
        printf("%d", count_array[i]);
        if (i < max)
            printf(", ");
    }
    printf("\n");

    // Reconstruct the sorted array from the counting array
    size_t index = 0;
    for (int i = 0; i <= max; i++)
    {
        while (count_array[i] > 0)
        {
            array[index] = i;
            index++;
            count_array[i]--;
        }
    }

    // Free the counting array
    free(count_array);
}
