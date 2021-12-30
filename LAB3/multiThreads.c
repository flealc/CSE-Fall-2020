#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>


//Creation of struct to pass multiple arguments to threads
struct cmdline_args {
	char* arg1;
	char* arg2;
};
typedef struct cmdline_args CMDLARGS;


	//Variables for File 1
        FILE * fp;
        int str_count = 0;
        char *buf = NULL;
        size_t size = 0;
        char *str;


	//Variables for File 2
	FILE * fp1;
        int str_count1 = 0;
        char *buf1 = NULL;
        size_t size1 = 0;
        char *str1;

//Thread 1
void *Thread (void *arg) { 
//	sleep(1);
	CMDLARGS* th_args = (CMDLARGS*) arg;
//    	printf("1: %s 2: %s\n", th_args->arg1, th_args->arg2);
	
	//Open file error check
        if ((fp = fopen (th_args->arg1, "r:")) == NULL) {
                perror("Error opening file");
                exit(1);
        }

	//Go line by line and count words
        while(getline(&buf, &size, fp) != -1){
		char *lp = buf;
              while ((lp=(strstr(lp,th_args->arg2))) != NULL) {
                        str_count++;
			++lp;
	       }
	}
  	//Print count, close file and end thread
	printf("football Count: %d\n", str_count);
	fclose(fp);
  	return NULL; 
} 


//Thread 2
void *Thread1 (void *arg1) { 
//	sleep(1);
	CMDLARGS* th_args1 = (CMDLARGS*) arg1;
//    	printf("3: %s 4: %s\n", th_args1->arg1, th_args1->arg2);

	//Open file error check
        if ((fp1 = fopen (th_args1->arg1, "r:")) == NULL) {
                perror("Error opening file");
                exit(1);
        }

	//Go line by line and count words
        while(getline(&buf1, &size1, fp1) != -1){
		char *lp1 = buf1;
              while ((lp1=(strstr(lp1,th_args1->arg2))) != NULL) {
                        str_count1++;
			++lp1;
	       }
        }
  	//Print count, close file and end thread

	printf("username Count: %d\n", str_count1);
	fclose(fp1);
	return NULL; 
} 

int main (int argc, char* argv[]) {

	if (argc != 5) {
                printf("Error: incorrect number of arguments\n");
                return -1;
        }

	
	
	CMDLARGS args = {};
	args.arg1 = argv[1];
	args.arg2 = argv[2];

	CMDLARGS args1 = {};
	args1.arg1 = argv[3];
	args1.arg2 = argv[4];
	
//Creation of Threads 1 and 2

	pthread_t thread1;
	pthread_t thread2;
	pthread_create(&thread1, NULL, Thread, &args);
	pthread_create(&thread2, NULL, Thread1, &args1);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	exit(0);
}








