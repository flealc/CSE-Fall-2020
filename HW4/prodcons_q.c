#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <time.h>


// Global vars //
char array[5];
sem_t aphore1, aphore2;
sem_t mutex;

// Function 1 //
void* funct1 (void* arg) {
	srand((unsigned int)time(NULL));
        char *lower = "abcdefghijklmnopqrstuvwxyz";
        int i0;
	int* thrID0 = (int*) arg;	 
        
	for (i0 = 0; i0 < 5; i0++) {
		sem_wait(&aphore1);
		char to_buffer0 = (char) lower[rand() % 26]; 
        	sem_wait(&mutex);
		array[i0] = to_buffer0;
		printf("writer ID: %d, char written: %c\n", *thrID0, to_buffer0);
		sem_post(&mutex);
		sem_post(&aphore2);
	}
	return 0;
}

// Function 2 //
void* funct2 (void* arg) {
	srand((unsigned int)time(NULL));
        char *upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int i1;
        int* thrID1 = (int*) arg;

        for (i1 = 0; i1 < 5; i1++) {
        	sem_wait(&aphore2);
		char to_buffer1 = upper[rand() % 26];
        	sem_wait(&mutex);
		array[i1] = to_buffer1;
        	printf("writer ID: %d, char written: %c\n", *thrID1, to_buffer1);
		sem_post(&mutex);
		sem_post(&aphore1);
	}

	return 0;
}


// Function 3 //
void* funct3 (void* arg) {
	int i2;
        int* thrID2 = (int*) arg;

	for (i2 = 0; i2 < 5; i2++) {
		sem_wait(&mutex);
		printf("reader ID: %d, char read: %c\n", *thrID2, array[i2]);
		sem_post(&mutex);
	}	
	return 0;
}

int main(int argc, char* argv[]) {

	if (argc != 1) {
		printf("Error: Incorrect number of arguments\n");
		exit(1);
	}

	int i;
	pthread_t tid[8];
	sem_init(&mutex, 0, 1);
	sem_init(&aphore1, 0, 5);
	sem_init(&aphore2, 0, 0);

	for (i = 0; i < 2; i ++) {
		int toth = i;
		pthread_create(&tid[i], NULL, funct1, (void*) &toth);
	}
  
	for (i = 2; i < 4; i ++) {
		int toth = i;	
		pthread_create(&tid[i], NULL, funct2, (void*) &toth);
	}

	for (i = 0; i < 4; i ++) {
		int toth = i;
		pthread_create(&tid[(i + 4)], NULL, funct3, (void*) &toth);
	}

	for (i = 0; i < 8; i ++) {
		pthread_join(tid[i], NULL);
	}

	return 0;
}

