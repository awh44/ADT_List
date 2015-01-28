#include <stdio.h>

#include "intList.h"
#include "uint64_tList.h"

typedef char* charptr;
MAKE_LIST_TYPE(charptr);

void int_list_print(intList *l)
{
	int_list_position p;
	for (p = int_list_first(l); !int_list_is_end(p); p = int_list_next(p))
	{
		printf("%d\n", int_list_retrieve(p));
	}
}

void uint64_t_print_list(uint64_tList *l)
{
	uint64_t_list_position p;
	for (p = uint64_t_list_first(l); !uint64_t_list_is_end(p); p = uint64_t_list_next(p))
	{
		printf("%lu\n", uint64_t_list_retrieve(p));
	}
}

int main(int argc, char *argv[])
{
	intList l;
	uint64_tList l64;

	int_list_initialize(&l);
	uint64_t_list_initialize(&l64);

	size_t i;
	for (i = 0; i < 25; i++)
	{
		int_list_insert(i, int_list_first(&l));
		uint64_t_list_insert(i, uint64_t_list_end(&l64));
	}

	printf("intList:\n");
	int_list_print(&l);
	
	printf("\nuint64_tList:\n");
	uint64_t_print_list(&l64);

	int_list_position p = int_list_locate(&l, 10);
	printf("\nThe located p = %d\n", int_list_retrieve(p));

	printf("\nDeleting p. List is now:\n");
	int_list_delete(p);
	int_list_print(&l);

	printf("\nPrinting list backwards:\n");
	for (p = int_list_previous(&l, int_list_end(&l)); !int_list_is_beginning(&l, p); p = int_list_previous(&l, p))
	{
		printf("%d\n", int_list_retrieve(p));
	}
	
	int_list_uninitialize(&l);
	uint64_t_list_uninitialize(&l64);

	return 0;
}
