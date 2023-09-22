#include "sort.h"

void swap(int *array, size_t i, size_t j);
size_t partition(int *array, size_t low, size_t high);
void quick_sort_hoare(int *array, size_t low, size_t high);
void quick_sort(int *array, size_t size);

void swap(int *array, size_t i, size_t j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

size_t partition(int *array, size_t low, size_t high)
{
    int pivot = array[high];
    size_t i = low - 1;
    size_t j = high + 1;

    while (1)
    {
        do
        {
            i++;
        } while (array[i] < pivot);

        do
        {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        swap(array, i, j);
    }
}

void quick_sort_hoare(int *array, size_t low, size_t high)
{
    if (low < high)
    {
        size_t partition_index = partition(array, low, high);
        quick_sort_hoare(array, low, partition_index);
        quick_sort_hoare(array, partition_index + 1, high);
    }
}

void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_hoare(array, 0, size - 1);
}
