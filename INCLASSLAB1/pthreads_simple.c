#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#ifndef NUMBER
 #define NUMBER 1000
#endif

void *Thread1 (void *arg) { 
    //nt* argm1;
//	sleep(1);
	char* argm;
	argm = (void *) arg; 
	strcat(argm, " Example");
	printf("Concat String: %s", argm);
    	return NULL; 
} 
void *Thread2 (void *arg) {
	
	int *i = (int*) arg;
//	i =  &arg;
//	printf("%d", NUMBER);
//	printf("%d", &i);
	printf("Count: %d", *i);
	return NULL;
}

int main (int argc, char* argv[]) {
//	int *a = NULL;
//	a = (int *) argv[2];
//	void* b = (void*) &a;
	pthread_t thread1;
	pthread_t thread2;
	pthread_create(&thread1, NULL, Thread1, argv[1]);
	pthread_create(&thread2, NULL, Thread2, argv[2]);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	exit(0);
}

