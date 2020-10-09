#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <time.h>


// Global vars //
char array[5];
sem_t go1, go2;
sem_t r_mutex, w_mutex;

// Function 1 //
void* funct1 (void* arg) {
	srand((unsigned int)time(NULL));
        char *lower = "abcdefghijklmnopqrstuvwxyz";
        int i0;
	int* thrID0 = (int*) arg;	 
		sem_wait(&go1);
		sem_wait(&w_mutex);
	for (i0 = 0; i0 < 5; i0++) {
		char to_buffer0 = (char) lower[rand() % 26]; 
		array[i0] = to_buffer0;
		printf("writer ID: %d, char written: %c\n", *thrID0, to_buffer0);
	}
		sem_post(&r_mutex);
		sem_post(&go2);
	return 0;
}

// Function 2 //
void* funct2 (void* arg) {
	srand((unsigned int)time(NULL));
        char *upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int i1;
        int* thrID1 = (int*) arg;
		sem_wait(&go2);
		sem_wait(&w_mutex);
        for (i1 = 0; i1 < 5; i1++) {
		char to_buffer1 = upper[rand() % 26];
		array[i1] = to_buffer1;
        	printf("writer ID: %d, char written: %c\n", *thrID1, to_buffer1);
	}
		sem_post(&r_mutex);
		sem_post(&go1);
	return 0;
}


// Function 3 //
void* funct3 (void* arg) {
	int i2;
        int* thrID2 = (int*) arg;
		sem_wait(&r_mutex);
	for (i2 = 0; i2 < 5; i2++) {
		printf("reader ID: %d, char read: %c\n", (*thrID2), array[i2]);
	}
		sem_post(&w_mutex);
	return 0;
}

int main(int argc, char* argv[]) {

	if (argc != 1) {
		printf("Error: Incorrect number of arguments\n");
		exit(1);
	}

	int i;
	pthread_t tid[8];
	sem_init(&w_mutex, 0, 1);
	sem_init(&r_mutex, 0, 0);
	sem_init(&go1, 0, 1);
	sem_init(&go2, 0, 0);
	int toth;
	for (i = 0; i < 2; i++) {
		toth = i;
		pthread_create(&tid[i], NULL, funct1, (void*) &toth);
	}
  	int toth1;
	for (i = 2; i < 4; i++) {
		toth1 = i;
		pthread_create(&tid[i], NULL, funct2, (void*) &toth1);
	}
	int toth2=0;
	int toth3=1;
	int toth4=2;
	int toth5=3;
	pthread_create(&tid[4], NULL, funct3, (void*) &toth2);
	pthread_create(&tid[5], NULL, funct3, (void*) &toth3);
	pthread_create(&tid[6], NULL, funct3, (void*) &toth4);
	pthread_create(&tid[7], NULL, funct3, (void*) &toth5);
	//for (i = 2; i < 4; i++) {
	//	toth2 = i ;
//		pthread_create(&tid[i], NULL, funct3, (void*) &toth2);
		//printf("Looooopin\");
//	}

	for (i = 0; i < 8; i ++) {
		pthread_join(tid[i], NULL);
	}

	return 0;
}

