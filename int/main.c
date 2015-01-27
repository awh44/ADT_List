#include <stdio.h>

#include "ADT_List.h"

int main(int argc, char *argv[])
{
	List l;

	size_t i;
	for (i = 0; i < 25; i++)
	{
		list_insert(i, list_first(&l));
	}

	list_print(&l);

	list_position p = list_locate(&l, 10);
	printf("The located p = %d\n", list_retrieve(p));

	printf("Deleting p. List is now:\n");
	list_delete(p);
	list_print(&l);


	for (p = list_previous(&l, list_end(&l)); !list_is_beginning(&l, p); p = list_previous(&l, p))
	{
		printf("%d\n", list_retrieve(p));
	}
	
	list_uninitialize(&l);

	return 0;
}
