#include <stdlib.h>
#include <stdio.h>

#include "ADT_List.h"

void list_initialize(List *l)
{
	l->head.next = NULL;
}

void list_uninitialize(List *l)
{
	Node *node = l->head.next;
	while (node != NULL)
	{
		Node *tmp = node->next;
		free(node);
		node = tmp;
	}
}

Node *list_first(List *l)
{
	return &l->head;
}

Node *list_end(List *l)
{
	Node *node = &l->head;
	while (node->next != NULL)
	{
		node = node->next;
	}
	return node;
}

uint8_t list_is_end(Node *node)
{
	return node->next == NULL;
}

uint8_t list_is_beginning(List *l, Node *node)
{
	return node == NULL;
}

Node *list_next(Node *node)
{
	return node->next;
}

Node *list_previous(List *l, Node *node)
{
	if (node == &l->head)
	{
		return NULL;
	}

	Node *curr = &l->head;
	while (curr->next != node)
	{
		curr = curr->next;
	}

	return curr;
}

Node *list_locate(List *l, int value)
{
	Node *node = &l->head;
	while (node->next != NULL && node->next->value != value)
	{
		node = node->next;
	}

	return node;
}

void list_insert(int value, Node *node)
{
	Node *new_node = malloc(sizeof *new_node);
	new_node->value = value;
	new_node->next = node->next;
	node->next = new_node;
}

void list_delete(Node *node)
{
	Node *tmp = node->next;
	node->next = tmp->next;
	free(tmp);
}

int list_retrieve(Node *node)
{
	return node->next->value;
}

void list_print(List *l)
{
	Node *node;
	for (node = list_first(l); !list_is_end(node); node = list_next(node))
	{
		printf("%d\n", list_retrieve(node));
	}
}
