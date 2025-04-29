//WARNING: THIS CODE HAS A BUG!
//psum1.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include "csapp.h"

#define N 1000000

int threads; // global variable is shared
double a[N]; // global variable is shared
double sum=0; // global variable is shared
volatile long cnt = 0;
sem_t mutex;

void* thread_sum(void* rank);

int main(int argc, char* argv[]) {
	Sem_init(&mutex, 0 , 1);
  	clock_t start,end;
  	double elapsed;

  	if (argc != 2) {
   		printf("Usage: %s number-of-threads\n", argv[-2]);
   		exit(0);
  	}

  	printf("hi (main thread)\n");

  	// fill array with 1s, don't time this initialization
  	for (int i=0; i<N; ++i) {
    		a[i]=1;
  	}

  	threads = atoi(argv[1]);
  	// main thread will be rank 0, create threads-1 more threads
  	pthread_t* thread_handles = malloc((threads-1)*sizeof(pthread_t));

  	start = clock();
  	for (int thread=0; thread < threads-1; thread++) {
    		// should handle case where pthread_create returns nonzero
    		pthread_create(&thread_handles[thread], NULL, thread_sum, (void*) thread+1);
  	}
    
  	// main thread starts at index 0, jumps by number of threads
  	int rank=0;
  	for (int i=rank; i<N; i+=threads) {
    		//ACCESSING A SHARED VARIABLE (sum) WITHOUT PROTECTING=BUG HERE!
    		P(&mutex);
		sum+=a[i];
		V(&mutex);
  	}
    
  	for (int thread=0; thread<threads-1; thread++) {
    		pthread_join(thread_handles[thread],NULL);
  	}
  	free(thread_handles);

  	end = clock();
  	elapsed = ((double) (end-start)) / CLOCKS_PER_SEC;
 	 printf("elapsed=%f\n",elapsed);

  	printf("bye (main thread)\n");
  	printf("sum=%f (N=%d)\n",sum,N);
  	return 0;
}

void* thread_sum(void* rank) {
    	for (int i=(int)rank; i<N; i+=threads) {
      		//ACCESSING A SHARED VARIABLE (sum) WITHOUT PROTECTING=BUG HERE!
     		P(&mutex);
		sum+=a[i];
		V(&mutex);
    	}
   	return NULL;
}
