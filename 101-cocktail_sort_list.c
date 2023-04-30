#include "sort.h"

/**
 * swap_nodes - swap two nodes in a linked list
 *
 * @list: pointer to a pointer
 * @node1: node to be swaped
 * @node2: node to be swaped
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *prev_node1 = node1->prev;
	listint_t *next_node2 = node2->next;

	if (prev_node1 == NULL)
		*list = node2;
	else
		prev_node1->next = node2;

	if (next_node2 == NULL)
		(*list)->prev = node1;
	else
		next_node2->prev = node1;


	node1->next = next_node2;
	node2->prev = prev_node1;
	node2->next = node1;
	node1->prev = node2;
}

/**
 * forward_pass - Perform a single pass of cocktail
 *
 * @list: pointer to pointer
 * @end: end of list
 *
 * Return: swapped list
 */
int forward_pass(listint_t **list, listint_t *end)
{
	int swapped = 0;
	listint_t *curr = *list;

	while (curr != end)
	{
		if (curr->n > curr->next->n)
		{
			swap_nodes(list, curr, curr->next);
			swapped = 1;
			print_list(*list);
		}
		else
			curr = curr->next;
	}
	return (swapped);
}
/**
 * backward_pass - reverse single pass of cocktail
 * @list: pointer to pointer
 * @end: end of list
 *
 * Return: swapped list
 */
int backward_pass(listint_t **list, listint_t *end)
{
	int swapped = 0;
	listint_t *curr = end;

	while (curr != *list)
	{
		if (curr->n < curr->prev->n)
		{
			swap_nodes(list, curr->prev, curr);
			swapped = 1;
			print_list(*list);
		}
		else
			curr = curr->prev;
	}
	return (swapped);
}

/**
 * coctail_sort_list - sort linked list using cocktail sort algorithm
 *
 * @list: pointer to pointer list to be listed
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *start = NULL, *end = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swapped)
	{
		swapped = 0;
		swapped |= forward_pass(list, end);
		if (!swapped)
			break;

		end = end == NULL ? *list : end->prev;
		swapped |= backward_pass(list, start);
		start = start == NULL ? (*list)->next : start->next;
	}
}
