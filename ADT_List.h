#ifndef __ADT_LIST__
#define __ADT_LIST__

typedef struct ListNode
{
	int value;
	struct ListNode *next;
} Node;

typedef struct
{
	Node head;
} List;

void list_initialize(List *l);
void list_uninitialize(List *l);
Node *list_first(List *l);
Node *list_end(List *l);
Node *list_next(Node *node);
void list_insert(int value, Node *node);
int list_retrieve(Node *node);
void list_print(List *l);

#endif
