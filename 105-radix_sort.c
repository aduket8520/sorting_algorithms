#include "sort.h"


int getMax(int *array, size_t size);
void countingSort(int *array, size_t size, int exp);
void radix_sort(int *array, size_t size);

int getMax(int *array, size_t size)
{
    int max = array[0];
    for (size_t i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}

void countingSort(int *array, size_t size, int exp)
{
    int output[size];
    int count[10] = {0};

    for (size_t i = 0; i < size; i++)
    {
        count[(array[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (size_t i = 0; i < size; i++)
    {
        array[i] = output[i];
    }
}

void radix_sort(int *array, size_t size)
{
    if (array == NULL || size <= 1)
        return;

    int max = getMax(array, size);

    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countingSort(array, size, exp);

        // Print the array after each increase in significant digit
        printf("Array after digit %d: ", exp);
        for (size_t i = 0; i < size; i++)
        {
            printf("%d", array[i]);
            if (i < size - 1)
                printf(", ");
        }
        printf("\n");
    }
}
