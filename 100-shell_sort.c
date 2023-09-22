#include "sort.h"


void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shell_sort(int *array, size_t size)
{
    if (array == NULL || size <= 1)
        return;

    int gap = 1;
    while (gap < size / 3)
        gap = gap * 3 + 1;

    while (gap > 0)
    {
        for (int i = gap; i < size; i++)
        {
            int temp = array[i];
            int j = i;

            while (j >= gap && array[j - gap] > temp)
            {
                array[j] = array[j - gap];
                j -= gap;
            }

            array[j] = temp;
        }

        // Print the array each time the interval decreases
        printf("Array with gap %d: ", gap);
        for (size_t i = 0; i < size; i++)
        {
            printf("%d", array[i]);
            if (i < size - 1)
                printf(", ");
        }
        printf("\n");

        gap = (gap - 1) / 3;
    }
}
