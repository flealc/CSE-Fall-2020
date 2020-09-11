#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {


	if (argc != 2) {
                printf("Error: Incorrect number of arguments\n");
                return (-1);
       	}

        int pip[2];
	char buf[50];
	char * cmdlarg;
	pid_t p;

	/* Create pipe */
	pipe(pip);
	
	if (pipe(pip) == -1) {
                fprintf(stderr, "Pipe error");
                return 1;
	}

	/* Create fork */
	p = fork();
	

	if (p < 0) {
		fprintf(stderr, "fork error: %s\n", strerror(errno));
		exit(0);
	}

	if (p > 0) {
		write(pip[1], argv[1], sizeof(argv[1]));
	} 

	if (p == 0) {
		read(pip[0], buf, 50);
		printf("%s", buf);
	}
	return 0;
}

