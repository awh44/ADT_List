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

void INITIALIZE(List *l);
void FREE_LIST(List *l);
Node *FIRST(List *l);
Node *END(List *l);
Node *NEXT(Node *node);
void INSERT(int value, Node *node);
int RETRIEVE(Node *node);
void PRINTLIST(List *l);

#endif
