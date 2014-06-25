/**
 *	Data management libs
 */
#include <stdio.h>
#include "data.h"

/**
 *	Get the next element in the list. Accepts the list's current item as
 *	argument, returns a pointer to the next item.
 */
ANNE_LIST *anne_list_next(ANNE_LIST *list) {
		if (list->next != NULL) return list->next; else return list;
}

ANNE_LIST *anne_list_prev(ANNE_LIST *list) {
		if (list->prev != NULL) return list->prev; else return list;
}

ANNE_LIST *anne_list_first(ANNE_LIST *list) {
	if (!list) return list;
	while (list->prev) {
		list = list->prev;
		printf("data: %i\n", *((int *) list->data));
	}

	return list;
}

ANNE_LIST *anne_list_last(ANNE_LIST *list) {
	if (!list) return list;
	while (list->next){
			list = list->next;
	}

	return list;
}

/**
 *	Adds an item to the end of the list. Shibe.
 */
ANNE_LIST *anne_list_append(ANNE_LIST *list, void *data) {
	ANNE_LIST *new_item = malloc(sizeof(*new_item));
	new_item->data = data;

	if (list) {
		list = anne_list_last(list);
		list->next = new_item;
		list->next->prev = list;
	} else {
		list = new_item;
	}

	return anne_list_first(list);
}

ANNE_LIST *anne_list_prepend(ANNE_LIST *list, void *data) {
	ANNE_LIST *new_item = malloc(sizeof(*new_item));
	new_item->data = data;
	if (list) {
		if (list->prev) {
			list = anne_list_first(list);
		}
		list->prev = new_item;
		list->prev->next = list;
	} else list = new_item;

	return list;
}

ANNE_LIST *anne_list_swap(ANNE_LIST *a, ANNE_LIST *b) {
	printf("wat %i\n", *((int *) a->data));
	void *temp;
	temp = a->data;
	a->data = b->data;
	b->data = temp;

	return anne_list_first(a);
}

/**
 *	Performs an insert sort operation on the list. The second argument
 *	is for a sort function, which should accept two units of data and
 *	return true if the first is higher.
 */
ANNE_LIST *anne_list_sort_insertion(ANNE_LIST *list, void (*compare_func)()) {

	return list;
}
