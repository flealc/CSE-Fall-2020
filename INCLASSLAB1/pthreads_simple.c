#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
void *Thread1 (void *arg) { 
    //nt* argm1;
	sleep(1);
	char* argm;
	argm = (void *) arg; 
	strcat(argm, " Example");
	printf("%s", argm);
    	return NULL; 
} 


int main (int argc, char* argv[]) {
	pthread_t thread;
	pthread_create(&thread, NULL, Thread1, argv[1]);
	pthread_join(thread, NULL);
	exit(0);
}

