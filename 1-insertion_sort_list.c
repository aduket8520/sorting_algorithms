#include "sort.h"


void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *current = (*list)->next;

	while (current != NULL)
	{
		listint_t *insertion_point = current->prev;
		listint_t *next_node = current->next;

		while (insertion_point != NULL && insertion_point->n > current->n)
		{
			insertion_point = insertion_point->prev;
		}

		if (insertion_point == NULL)
		{
			// Move the current node to the front of the list
			current->prev->next = next_node;
			if (next_node != NULL)
				next_node->prev = current->prev;
			current->next = *list;
			current->prev = NULL;
			(*list)->prev = current;
			*list = current;
		}
		else
		{
			// Insert the current node after the insertion point
			current->prev->next = next_node;
			if (next_node != NULL)
				next_node->prev = current->prev;
			current->prev = insertion_point;
			current->next = insertion_point->next;
			insertion_point->next = current;
			if (current->next != NULL)
				current->next->prev = current;
		}

		// Print the list after each swap
		listint_t *temp = *list;
		while (temp != NULL)
		{
			printf("%d", temp->n);
			if (temp->next != NULL)
				printf(", ");
			temp = temp->next;
		}
		printf("\n");

		current = next_node;
	}
}
