#include <stdio.h>
#include <stdlib.h>

#define MEMORY_CAPACITY_WORDS 64
int memory[MEMORY_CAPACITY_WORDS];//the memory we can allocate
int* end;//a pointer to the last element of memory

int mymalloc_calls=0;

/* Begin editing the code here! */

void fillCopy(int* a, int size, int val) {
    for (int i=0; i<size; i++) {
        *(a+i)=val;
    }
}


void mymalloc_init() {
	memory[0] = 256;

	for(int i = 1; i < 256; i++){
		memory[i] = 0;
	}
}

void print_memory() {
    //uncomment this to print contents of memory
    for (int i=0; i<MEMORY_CAPACITY_WORDS; i++) {
        printf("memory[%d]=%d\n",i,memory[i]);
    }
}

void *mymalloc(int bytes_requested) {
    mymalloc_calls++;
    printf("mymalloc_call %d, bytes=%d\n",mymalloc_calls,bytes_requested);

	/* Enforce the blocks begin at multiples of 4 bytes */
	int bytes_used;

	if(bytes_requested % 4 == 0){
		bytes_used = bytes_requested;
	}else{
		int add = 4 - (bytes_requested % 4);
		bytes_used = bytes_requested + add;
	}

	bytes_used += 4;	//this increases to account for the header

	/* Traverse the implicit list until you find the first fit */

	int traversal = 0;	//using this to keep track of and read the headers. each iteration of the loop should be inspecting the header  at memory[traversal]

	while(1){
		if(traversal > 255 || memory[traversal] < bytes_used && memory[traversal] % 2 != 0){	//this covers the case of out of bounds or we have not found an open 'slot' 
			fprintf(stderr, "The is no space for this allocation\n");
			return 0;
		}

		if(memory[traversal] < bytes_used || memory[traversal] % 2 != 0){	//if the current header indicates occupied or too small, we continue the loop with a properly updated 'traversal'
			int bytesToJump;

			if(memory[traversal] % 2 != 0){			//finds the amount to jump
				bytesToJump = memory[traversal] - 1;
			}else{
				bytesToJump = memory[traversal];
			}

			traversal = traversal + bytesToJump/4;	//jumps that found amount
		}else{									//else handles header naming & filling of the requested malloc then returns the pointer to the header
			int sizeleft = memory[traversal] - bytes_used; //grabs info so we can know what to write for the next header fpr the free space after this allocation before ovewrite
			memory[traversal] = bytes_used + 1;	//header

			int* fillStart = &memory[traversal + 1];//this  fills the allocation with the order number that this malloc is
			int size = bytes_used / 4;
			fillCopy(fillStart, size, mymalloc_calls);

			memory[traversal + size] = sizeleft;	//assigns header for the next open section

			int* p = &memory[traversal];

			return p;
		}


	}

	/* If there are no available blocks, print an error and return 0 */

	/* If you found a block:
       - update the header
       - if necessary, split the block */

	/* Return the pointer to the header + 1 */
}

void myfree(int* p) {
    *p = *p - 1;
}

/* End editing the code here */

void fill(int* a, int size, int val) {
    for (int i=0; i<size; i++) {
        *(a+i)=val;
    }
}

int main() {
	mymalloc_init();
	//tests

	int* call1 = mymalloc(20);
	print_memory();
	int* call2 = mymalloc(15);
	print_memory();

	myfree(call1);
	print_memory();

	int* call3 = mymalloc(10);
	print_memory();

}
