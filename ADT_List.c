#include <stdlib.h>
#include <stdio.h>

#include "ADT_List.h"

void INITIALIZE(List *l)
{
	l->head.next = NULL;
}

void FREE_LIST(List *l)
{
	Node *node = l->head.next;
	while (node != NULL)
	{
		Node *tmp = node->next;
		free(node);
		node = tmp;
	}
}

Node *FIRST(List *l)
{
	return &l->head;
}

Node *END(List *l)
{
	Node *node = &l->head;
	while (node->next != NULL)
	{
		node = node->next;
	}
	return node;
}

int IS_END(Node *node)
{
	return node->next == NULL;
}

Node *NEXT(Node *node)
{
	return node->next;
}

void INSERT(int value, Node *node)
{
	Node *new = malloc(sizeof(Node));
	new->value = value;
	new->next = node->next;
	node->next = new;
}

void REMOVE(Node *node)
{
	Node *to_remove = node->next;
	node->next = to_remove->next;
	free(to_remove);
}

int RETRIEVE(Node *node)
{
	return node->next->value;
}

void PRINTLIST(List *l)
{
	Node *node;
	for (node = FIRST(l); !IS_END(node); node = NEXT(node))
	{
		printf("%d\n", RETRIEVE(node));
	}
}
