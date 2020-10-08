#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>

// Global Variables //
sem_t control1;

// Functions to print A, B, and C //
void* print1(void* srg) {
	sem_wait(&control1);
	printf("A\n");
	return NULL;
}

void* print2(void* arg) {
	sem_wait(&control1);
	printf("B\n");
	sem_post(&control1); // FIX for code issue
	return NULL;
}

void* print3(void* arg) {
	sem_wait(&control1);
	printf("C\n");
	return NULL;
}



int main (int argc, char* argv[]) {
	
	if (argc != 1) {
		printf("Error: Incorrect number of arguments\n");
		exit(1);
	}

	pthread_t tid[3];
	
	sem_init(&control1, 0, 2);
	// Create Threads //
	pthread_create(&tid[0], NULL, print1, NULL);
	pthread_create(&tid[1], NULL, print2, NULL);
	pthread_create(&tid[2], NULL, print3, NULL);
	
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	pthread_join(tid[2], NULL);
		
return 0;

}




 
