#ifndef _GENERIC_LIST_H_
#define _GENERIC_LIST_H_

#include <stdlib.h>
#include <stdio.h>
#define MAKE_LIST_TYPE(type) \
typedef struct type##ListNode\
{\
	type value;\
	struct type##ListNode *next;\
} type##Node;\
\
typedef struct\
{\
	type##Node head;\
} type##List;\
\
typedef type##Node* type##_list_position;\
\
void type##_list_initialize(type##List *l)\
{\
	l->head.next = NULL;\
}\
\
void type##_list_uninitialize(type##List *l)\
{\
	type##Node *node = l->head.next;\
	while (node != NULL)\
	{\
		type##Node *tmp = node->next;\
		free(node);\
		node = tmp;\
	}\
}\
\
type##Node *type##_list_first(type##List *l)\
{\
	return &l->head;\
}\
\
type##Node *type##_list_end(type##List *l)\
{\
	type##Node *node = &l->head;\
	while (node->next != NULL)\
	{\
		node = node->next;\
	}\
	return node;\
}\
\
uint8_t type##_list_is_end(type##Node *node)\
{\
	return node->next == NULL;\
}\
\
uint8_t type##_list_is_beginning(type##List *l, type##Node *node)\
{\
	return node == NULL;\
}\
\
type##Node *type##_list_next(type##Node *node)\
{\
	return node->next;\
}\
\
type##Node *type##_list_previous(type##List *l, type##Node *node)\
{\
	if (node == &l->head)\
	{\
		return NULL;\
	}\
\
	type##Node *curr = &l->head;\
	while (curr->next != node)\
	{\
		curr = curr->next;\
	}\
\
	return curr;\
}\
\
type##Node *type##_list_locate(type##List *l, type value)\
{\
	type##Node *node = &l->head;\
	while (node->next != NULL && node->next->value != value)\
	{\
		node = node->next;\
	}\
\
	return node;\
}\
\
void type##_list_insert(type value, type##Node *node)\
{\
	type##Node *new_node = malloc(sizeof *new_node);\
	new_node->value = value;\
	new_node->next = node->next;\
	node->next = new_node;\
}\
\
void type##_list_delete(type##Node *node)\
{\
	type##Node *tmp = node->next;\
	node->next = tmp->next;\
	free(tmp);\
}\
\
type type##_list_retrieve(type##Node *node)\
{\
	return node->next->value;\
}

#endif
