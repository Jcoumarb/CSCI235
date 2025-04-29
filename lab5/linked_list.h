#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node{
	int data;
	struct node *next;
}Node;

Node* insert(Node *p, int value);
void print_list(Node *p);
Node* free_list(Node *p);
Node* delete_node(Node * p, int value);

#endif
