#ifndef __ADT_LIST__
#define __ADT_LIST__

#include <stdint.h>

typedef struct ListNode
{
	int value;
	struct ListNode *next;
} Node;

typedef struct
{
	Node head;
} List;

typedef Node* list_position;

void list_initialize(List *l);
void list_uninitialize(List *l);
Node *list_first(List *l);
Node *list_end(List *l);
uint8_t list_is_end(Node *node);
uint8_t list_is_beginning(List *l, Node *node);
Node *list_next(Node *node);
Node *list_previous(List *l, Node *node);
Node *list_locate(List *l, int value);
void list_insert(int value, Node *node);
void list_delete(Node *node);
int list_retrieve(Node *node);
void list_print(List *l);

#endif
