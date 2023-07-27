#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly-linked list in ascending order
 * using insertion sort algorithm
 * @list: A doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *temp1, *prevs, *temp_next, *temp_prev_prev;

	/*Nothing to sort or only one element*/
	if (list == NULL || (*list)->next == NULL)
		return;

	temp = *list;
	while (temp != NULL)
	{
		if (temp->prev && temp->prev->n > temp->n)
		{
			/*Prepare pointers for swapping*/
			temp_prev_prev = temp->prev->prev;
			prevs = temp->prev;
			temp1 = temp;
			temp_next = temp->next;

			/*Swap nodes*/
			prevs->next = temp_next;

			if (temp_next)
				temp_next->prev = prevs;
			temp->prev = temp_prev_prev;
			temp->next = prevs;

			if (temp_prev_prev)
				temp_prev_prev->next = temp1;
			else
				*list = temp1;
			prevs->prev = temp1;
			temp = *list;
			print_list(*list);
			continue;
		}
		else
			temp = temp->next;
	}
}
