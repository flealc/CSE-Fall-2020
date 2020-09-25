#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Create array of size ASIZE //
int array[ASIZE];
long i;
int RATIO = (ASIZE/NTHREADS);
int threadsum[NTHREADS];
int sum[NTHREADS];

// Thread //
void *sum_thread(void *arg) {
	int *threadindex = (int*) arg;
//	printf("Thread %d working on: %d\n", *threadindex, array[*threadindex]);
//	int sum = 0;
	for (i= (*threadindex  * RATIO); i < ((*threadindex * RATIO) + RATIO); i++) {
		sum[*threadindex] = (sum[*threadindex] + array[i]);
	}
//	threadsum[*threadindex] = sum;
//	printf("Thread %d sum: %d\n", *threadindex, sum[*threadindex]);
	return NULL;
}

// Main function //
int main (int argc, char *argv[]) {

	
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

	// Loop for creation of NTHREADS number of threads //
	for (i = 0; i < NTHREADS; i++) {
		threadnr[i]= i;
		pthread_create(&tid[i], NULL, sum_thread, (void*) &threadnr[i]);
	}

	for (i = 0; i < NTHREADS; i++) {
		pthread_join(tid[i], NULL);
	}
	
	long finalsum = 0;
	for (i = 0; i < NTHREADS; i++) {
		finalsum = finalsum + sum[i];
	}
	printf("%ld", finalsum);
	return (0);
}	 
