#include "sort.h"

void swap(int *a, int *b);
void sift_down(int *array, size_t size, size_t root);
void heapify(int *array, size_t size);
void heap_sort(int *array, size_t size);

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void sift_down(int *array, size_t size, size_t root)
{
  size_t largest = root;
  size_t left = 2 * root + 1;
  size_t right = 2 * root + 2;

  if (left < size && array[left] > array[largest])
    largest = left;

  if (right < size && array[right] > array[largest])
    largest = right;

  if (largest != root)
  {
    swap(&array[root], &array[largest]);
    sift_down(array, size, largest);
  }
}

void heapify(int *array, size_t size)
{
  for (int i = size / 2 - 1; i >= 0; i--)
  {
    sift_down(array, size, i);
  }
}

void heap_sort(int *array, size_t size)
{
  if (array == NULL || size <= 1)
    return;

  heapify(array, size);

  for (int i = size - 1; i > 0; i--)
  {
    swap(&array[0], &array[i]);
    sift_down(array, i, 0);
  }
}
