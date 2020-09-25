#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#ifndef NTHREADS
	#define NTHREADS 2
#endif 
#ifndef ASIZE
	#define ASIZE 1000
#endif 


// Create array of size ASIZE //
int array[ASIZE];
int RATIO = (ASIZE/NTHREADS); // To assign a partition of the array to each thread //
int threadsum[NTHREADS]; //Store each thread's sum //


// Thread //
void *sum_thread(void *arg) {
	int *threadindex = (int*) arg;
	int i;
	long sum = 0;
	for (i= (*threadindex  * RATIO); i < ((*threadindex * RATIO) + RATIO); i++) {
		sum = (sum + array[i]);
	}
	threadsum[*threadindex] = sum;
//	printf("Thread %d sum: %ld\n", *threadindex, sum);  // Check printf //
	return NULL;
}


// Main function //
int main (int argc, char *argv[]) {

	int i;
	
	// Check for incorrect number of arguments //
	if ((argc =! 2)) {
		printf("Error: Incorrect number of arguments");
		exit(-1);
	}
	// Initialize array of size ASIZE //
	for (i = 0; i < ASIZE; i++) {
		array[i] = i*atoi(argv[1]);
	}

	// Declaration of Thread ID's array //
	pthread_t tid[NTHREADS];
	int threadnr[NTHREADS];

//	printf("%d\n", NTHREADS); // Printf check //

	// Loop for creation of NTHREADS number of threads //
	for (i = 0; i < NTHREADS; i++) {
		threadnr[i]= i;
		pthread_create(&tid[i], NULL, sum_thread, (void*) &threadnr[i]);
	}

	// Join Threads//	
	for (i = 0; i < NTHREADS; i++) {
		pthread_join(tid[i], NULL);
	}

	// Calculate and print sum //
	long finalsum = 0;
	
	for (i = 0; i < NTHREADS; i++) {
		finalsum = finalsum + threadsum[i];
	}
	
	printf("%ld\n", finalsum);
	
	return (0);
}	 
