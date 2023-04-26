#include "sort.h"

/**
 * insertion_sort_list - sorts using insertion method of doubly liked lis
 *
 * @list: list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr = (*list)->next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (curr != NULL)
	{
		listint_t *tmp = curr->prev;

		while (tmp != NULL && tmp->n > curr->n)
		{
			tmp->next = curr->next;
			if (curr->next != NULL)
				curr->next->prev = tmp;
			curr->next = tmp;
			curr->prev = tmp->prev;
			tmp->prev = curr;
			if (curr->prev == NULL)
				*list = curr;
			else
				curr->prev->next = curr;
			print_list(*list);
			tmp = curr->prev;
		}
		curr = curr->next;
	}
}
