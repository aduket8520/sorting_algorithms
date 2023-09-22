#include "sort.h"


void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	if (!a || !b || a == b)
		return;

	if (a->prev)
		a->prev->next = b;
	if (b->prev)
		b->prev->next = a;

	if (a->next)
		a->next->prev = b;
	if (b->next)
		b->next->prev = a;

	listint_t *temp = a->prev;
	a->prev = b->prev;
	b->prev = temp;

	temp = a->next;
	a->next = b->next;
	b->next = temp;

	if (!a->prev)
		*list = a;
	if (!b->prev)
		*list = b;
}

listint_t *cocktail_sort_list(listint_t **list)
{
	if (!list || !*list || !(*list)->next)
		return *list;

	int swapped;
	listint_t *start = *list;
	listint_t *end = NULL;

	do
	{
		swapped = 0;

		listint_t *current = start;

		while (current->next != end)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				swapped = 1;
				print_list(*list);
			}
			else
			{
				current = current->next;
			}
		}

		if (!swapped)
			break;

		end = current;

		swapped = 0;

		while (current->prev != start)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				swapped = 1;
				print_list(*list);
			}
			else
			{
				current = current->prev;
			}
		}

		start = current;
	} while (swapped);

	return *list;
}

/* Print the linked list */
void print_list(listint_t *list)
{
	listint_t *current = list;
	while (current)
	{
		printf("%d", current->n);
		if (current->next)
			printf(", ");
		current = current->next;
	}
	printf("\n");
}
