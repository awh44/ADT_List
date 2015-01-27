#include <stdio.h>

#include "ADT_List.h"
#include "Generic_ADT_List.h"

MAKE_LIST_TYPE(int)

void int_list_print(intList *l)
{
	int_list_position p;
	for (p = int_list_first(l); !int_list_is_end(p); p = int_list_next(p))
	{
		printf("%d\n", int_list_retrieve(p));
	}
}

int main(int argc, char *argv[])
{
	intList l;

	size_t i;
	for (i = 0; i < 25; i++)
	{
		int_list_insert(i, int_list_first(&l));
	}

	int_list_print(&l);

	int_list_position p = int_list_locate(&l, 10);
	printf("The located p = %d\n", int_list_retrieve(p));

	printf("Deleting p. List is now:\n");
	int_list_delete(p);
	int_list_print(&l);


	for (p = int_list_previous(&l, int_list_end(&l)); !int_list_is_beginning(&l, p); p = int_list_previous(&l, p))
	{
		printf("%d\n", int_list_retrieve(p));
	}
	
	int_list_uninitialize(&l);

	return 0;
}
