#include <stdio.h>

void swap(int*, int*);	//helper swap function delcaration

void selection_sort(int array[], int size){

	for(int i = 0; i < size; i++){	//this loop progresses through the array putting the lowest int in the lowest available position

		int indexLowest = i;	//this keeps track of the position  of the lowest integer in whatever pass the  loop is in
		int indexInput = i;	//this does not get updated like indexLowest does, it retains the index of the spot for the next lowest int found

		for(int j = i; j < size; j++){	//this loop interates through the array from not the beginning but from the first open spot

			if(array[j] < array[indexLowest]){	//checks if the current int is lower than the int stored as lowest and swaps pointer if necessary
				indexLowest = j;
			}
		}

		swap(&array[indexInput], &array[indexLowest]);	//swaps ints to proper position after the lowest int in the subset has been found
	}
}

void swap(int *a, int *b){	//helper swap function defintion
	int temp = *b;
	*b = *a;
	*a = temp;
}

void print(int array[], int size){

	for(int i = 0; i< size; i++){
		printf("%d ", array[i]);
	}

	printf("\n");
}

int main(){

	int test[] = {5, 4, 3, 2, 1};
	int test2[] = {3,7,2,9, 12345, 3456, 789, 3, 5, 726};	//I had my friend select all of the numbers for this second one just cuz lol

	printf("Test 1:\n");
	print(test, 5);
	selection_sort(test, 5);
	print(test, 5);

	printf("Test 2:\n");
	print(test2, 10);
	selection_sort(test2, 10);
	print(test2, 10);
}
