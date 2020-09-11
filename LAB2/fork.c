#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {


	if (argc != 2) {
                printf("Error: Incorrect number of arguments\n");
                return (-1);
       	}

	int number;
	number = atoi(argv[1]);
	pid_t p;
	
	p = fork();
	

	if (p < 0) {
		fprintf(stderr, "fork error: %s\n", strerror(errno));
		exit(0);
	}

	printf("Hello World\n");

	if (p > 0) {
		printf("Parent: %d\n", number + 1);
		exit (0);
	}
	else if (p == 0) {
		printf("Child: %d\n", number - 1);
		exit (0);
	} 
	return (0);
}

