#include <stdio.h>
#include <stdlib.h>
#include "data.c"

int main(void) {
	ANNE_LIST *leest = NULL;
	int *data = malloc(sizeof(int));
	*data = 42;
	int *data2 = malloc(sizeof(int));
	*data2 = 69;
	int *data3 = malloc(sizeof(int));
	*data3 = 74;
	leest = anne_list_append(leest, data);
	leest = anne_list_append(leest, data2);
	leest = anne_list_prepend(leest, data3);
	printf("wat1\n");
	//leest = anne_list_swap(leest, leest->next);
	printf("no\n");
	for (
			leest = anne_list_first(leest);
			leest != NULL;
			leest = leest->next
	) {
		printf(
			"fdata: %i\n",
			*((int *) leest->data)
		);
	}

	return 0;
}
