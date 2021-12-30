#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

// Global Variable //

int random_nr;
sem_t r_mutex; 
sem_t w_mutex;

// Thread routine //
void *prod_thread(void *arg) {
	int i;   // for counter
	int *value = (int*) arg; // obtains value of n from main
//	printf("%d\n", *value);
	// Seed rand()	
	srand((unsigned int)time(NULL));
	// Generate random values lower than n //
	for (i = 0; i < *value; i++) {
		sem_wait(&w_mutex);
		random_nr = rand() % *value;
		printf("writer wrote: %d\n", random_nr);
		sem_post(&r_mutex);		
	}
	return 0;
}


int main (int argc, char* argv[]) {
	// Check for right number of args //
	if (argc != 2) {
                printf("Error: incorrect number of arguments\n");
                exit(1);
        }
	int i;
	sem_init(&r_mutex, 0, 0);
	sem_init(&w_mutex, 0, 1);	
//	printf("%d\n", atoi(argv[1]));
	pthread_t tid;
	int to_thread_arg = atoi(argv[1]);

	if (to_thread_arg < 1) {
		printf("Usage: argument must be a positive integer\n");
		exit(1);
	}	

	// Create thread //
	pthread_create(&tid, NULL, prod_thread, (void*) &to_thread_arg);
	
	// Read and print the value of global variable random_nr //
	for (i = 0; i < to_thread_arg; i++) {
		sem_wait(&r_mutex);
		printf("main read: %d\n", random_nr);
		sem_post(&w_mutex);
	}

	pthread_join(tid, NULL);
	
	return 0;
}

