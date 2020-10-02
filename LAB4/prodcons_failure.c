#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

// Global Variable //

int random_nr;

// Thread routine //
void *prod_thread(void *arg) {
	int i;   // for counter
	int *value = (int*) arg; // obtains value of n from main
//	printf("%d\n", *value);
	// Seed rand()	
	srand((unsigned int)time(NULL));
	// Generate random values lower than n //
	for (i = 0; i < *value; i++) {
		printf("writer wrote: %d\n", rand() % *value);
		random_nr = *value;		
	}
	return 0;
}


int main (int argc, char* argv[]) {
	// Check for right number of args //
	if (argc != 2) {
                printf("Error: incorrect number of arguments\n");
                exit(-1);
        }
	int i;
	
//	printf("%d\n", atoi(argv[1]));
	pthread_t tid;
	int to_thread_arg = atoi(argv[1]);

	if (to_thread_arg < 1) {
		printf("Usage: argument must be a positive integer\n");
		EXIT_FAILURE;
	}	

	// Create thread //
	pthread_create(&tid, NULL, prod_thread, (void*) &to_thread_arg);
	
	// Read and print the value of global variable random_nr //
	for (i = 0; i < to_thread_arg; i++) {
		printf("main read: %d\n", random_nr);
	}

	pthread_join(tid, NULL);
	
	return 0;
}

