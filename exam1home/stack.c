#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
	char word[5];
	int num;
	struct node *next;
}node;

struct node* push(struct node* p, char* str, int value){//either case handles taking the parameter info and inserting in into a freshly "malloc'd" node

	if(p ==  NULL){//handles push to stack in the case of an empty stack
		p = (struct node*) malloc(sizeof(struct node));
		p -> num = value;

		for(int i = 0; i < 5; i++){
			if(str[i] == 0){
				p -> word[i] = 0;
				break;
			}

			p -> word[i] = str[i];
		}

		p -> next = NULL;
		return p;
	}else{//handles push for any other amount of  nodes in the stack
		struct node* create = (struct node*) malloc(sizeof(struct node));
		create -> num = value;

		for(int i = 0; i < 5; i++){
			if(str[i] == 0){
				create -> word[i] = 0;
				break;
			}

			create -> word[i] = str[i];
		}

		create -> next = p;
		return create;
	}
}

void print_stack(struct node* p){

	if(p == NULL){
		printf("[empty stack]\n");
	}else{//the overall structure is to start at the end of an arbitrarily long array, "build", and iterate forward grabbing the information
		//from the current node and dropping the proper characters in each spot of the array, while formatting properly, iterating toward the beginning of the array
		//after build is done, then there is a character array called out that build will be copied into and then out is printf'd

		struct node* current = p;
		char build[255];
		build[254] = 0;
		int index = 253;

		while(current != NULL){
			build[index--] = ')';	//formatting of the right parenthesis

			//This next section converts the number field into a string
			//the end of that string is then found
			//and from there you iterate through the number backwards to drop each character into the build array
			char temp[5];
			sprintf(temp, "%d", current -> num);
			int numcount = 0;

			for(int i = 0; i < 5; i++){
				if(temp[i] == 0){
					break;
				}

				numcount = i;
			}

			while(numcount >= 0){
				build[index--] = temp[numcount--];
			}

			//Formatting for the fields of each node
			build[index--] = ' ';
			build[index--] = ',';

			//This section  finds the end of string of the word field
			//and from there you iterate through the word backwards to drop each character into the build array
			int wordcount = 0;

			for(int i = 0; i < 5; i++){
				if(current -> word[i] == 0){
					break;
				}

				wordcount = i;
			}

			while(wordcount >= 0){
				build[index--] = current -> word[wordcount--];
			}

			//formatting of the left parenthesis
			build[index--] = '(';

			//formatting for between each node and it only happens if there is going to be a node that is found next
			if(current ->next != NULL){
				build[index--] = ' ';
				build[index--] = ',';
			}

			//iterator for while loop
			current = current -> next;
		}

		//this section copies the contents of build into out and then null - terminates
		char out[255];
		index ++;

		for(int i = 0; i < 255; i++){

			if(build[index] == 0){
				out[i]  = 0;
				break;
			}

			out[i] = build[index++];
		}

		//The thing the method is supposed to do lol
		printf("%s\n", out);
	}
}

struct node* pop(struct node* p){

	struct node* grabNext = p -> next;	//grabs the pointer to the next node in the list
	free(p);				//frees the malloc of the  current head

	return grabNext;			//returns the next node in the list as that is the new head
}

int main(){

	struct node *head = NULL;

	print_stack(head);	//empty test

	char test1[] = "main";	//insert cases
	char* t1 = test1;
	head = push(head, t1, 0);

	print_stack(head);

	char test2[] = "fun";
	char* t2 = test2;
	head = push(head, t2, 13);

	print_stack(head);

	char test3[] = "sqrt";
	char* t3 = test3;
	head = push(head, t3, 64);

	print_stack(head);

	head = pop(head);	//remove case

	print_stack(head);

	char test4[] = "sim";
	char* t4 = test4;
	head = push(head, t4, -3);

	print_stack(head);
}
