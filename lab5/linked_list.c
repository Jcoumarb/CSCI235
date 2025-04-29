#include "linked_list.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
Node* insert(Node *p, int value){

	if(p == NULL){
		p = (Node*) malloc(sizeof(Node));
		p->data = value;
		p->next = NULL;
		return p;
	}else{
		Node *create = (Node*) malloc(sizeof(Node));
		create->data = value;
		create->next = p;
		return create;
	}
}

void print_list(Node *p){

	Node *current = p;
	char out[255];
	out[0] = 0;
	char temp[10];

	while(current != NULL){

		sprintf(temp, "%d", current->data);
		strcat(out, temp);

		if(current->next != NULL){
			strcat(out, " ");
		}

		current = current->next;
	}

	printf("%s", out);
	printf("\n");
}

Node* free_list(Node *p){

	Node *current = p;

	while (current != NULL){

		Node *after = current->next;
		free(current);
		current = after;
	}

	return NULL;
}

Node* delete_node(Node* p, int value){

	Node *trailing = NULL;
	Node *current = p;
	Node *head = p;

	while(current != NULL){

		if(current->data == value){

			if(head == current){
				head = head->next;
			}

			trailing->next = current->next;
			free(current);
			break;
		}

		trailing = current;
		current = current->next;
	}

	return head;
}
