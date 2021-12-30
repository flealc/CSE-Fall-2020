#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (int argc, char *argv[]) {

	//Check for incorrect number of arguments
	if (argc != 2) {
	printf("Error: Incorrect number of arguments\n");
	exit(1);
	}

	//Declare variables
	int array[ASIZE];
	int i;
	pid_t p;
	int status;
	int pip[2];
	int finalsum;
	

	//Initialize array of values from argv[1]
	for (i = 0; i < ASIZE; i++) {
		array[i] = i*atoi(argv[1]);
	//	printf("%d\n", array [i]);
	}
	
	int sum1 = array[ASIZE / 2];
	
	// Create pipe //
	
	if (pipe(pip) == -1) {
		fprintf(stderr, "Pipe error");
		return 1;
	}

	// Create fork //
	p = fork();

	if (p < 0) {
		fprintf(stderr, "Fork error: %s\n", strerror(errno));
		exit(0);
	}



	// Perform sum in child process //
	else if (p == 0) {

		int sum = array[0];
	
		for (i = 0; i < (ASIZE / 2); i++) {
			sum = (sum + array[i]);
		}
	//	printf("Child sum: %d\n", sum); 
		close(pip[0]);
		char topipe[20];
		sprintf(topipe, "%d", sum); 
		write(pip[1], topipe, 20);
		exit (0);
	} 

	// Perform sum in parent process //
	
	else if (p > 0) {
			
		for (i = ((ASIZE / 2) + 1); i < ASIZE; i++) {
			sum1 = (sum1 + array[i]);
		}
	
	//	printf("Parent sum: %d\n", sum1);
		
		close(pip[1]);
		char buf[20];
		read(pip[0], buf, 20);
		finalsum = (sum1 + atoi(buf));
		printf("%d\n", finalsum);	

		
		p = wait(&status);
	
		if (wait(&status) != 0) {
			exit(EXIT_FAILURE);
		}

		else {
		exit(EXIT_SUCCESS);
		}	

	
	}
		
	return 0;
}
	
