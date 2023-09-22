#include "sort.h"

void exchange(int *array, size_t i, size_t j);
void bitonicMerge(int *array, size_t low, size_t count, int direction);
void bitonicSort(int *array, size_t low, size_t count, int direction);
void bitonic_sort(int *array, size_t size);


void exchange(int *array, size_t i, size_t j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void bitonicMerge(int *array, size_t low, size_t count, int direction) {
    if (count > 1) {
        size_t k = count / 2;
        for (size_t i = low; i < low + k; i++) {
            if ((array[i] > array[i + k]) == direction) {
                exchange(array, i, i + k);
            }
        }
        bitonicMerge(array, low, k, direction);
        bitonicMerge(array, low + k, k, direction);
    }
}

void bitonicSort(int *array, size_t low, size_t count, int direction) {
    if (count > 1) {
        size_t k = count / 2;
        bitonicSort(array, low, k, 1);
        bitonicSort(array, low + k, k, 0);
        bitonicMerge(array, low, count, direction);
    }
}

void bitonic_sort(int *array, size_t size) {
    if (array == NULL || size < 2)
        return;

    int direction = 1; // 1 for ascending, 0 for descending

    bitonicSort(array, 0, size, direction);
}
