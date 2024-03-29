#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {


	if (argc < 3) {
		printf("Error: Too few arguments\n");
		return (-1);
	}

	if (argc > 3) {
		printf("Error: Too many arguments\n");
		return (-1);
	}
        
	int pip[2];
//	char arg1[50];
//      char arg2[50];
//	char buf[100];
	pid_t p;
	int status;

	/* Create pipe */
	pipe(pip);
	
	if (pipe(pip) == -1) {
                fprintf(stderr, "Pipe error");
                return 1;
	}

	/* Create fork */
	

	 if ((p = fork()) < 0) {
		fprintf(stderr, "fork error: %s\n", strerror(errno));
		exit(1);
	}

	else if (p > 0) {
		close(pip[0]);
		
//		strcpy(arg1, argv[1]);
//		strcpy(arg2, argv[2]);
//		strcat(arg1, ",");
//		strcat(arg1,arg2);
		write(pip[1], argv[1], strlen(argv[1]) + 1);
		write(pip[1], argv[2], strlen(argv[2]) + 1);
		p = wait(&status);
		if (wait(&status) != 0) {
			exit(EXIT_FAILURE);
		}
		else {
			exit(EXIT_SUCCESS);
		}	

	} 

	else if (p == 0) { 
                
		char arg21[50];
		char arg22[50];
		close(pip[1]);
		read(pip[0], arg21, strlen(argv[1]) + 1);
		read(pip[0], arg22, strlen(argv[2]) + 1);
		close(pip[0]);
		char path[50];
		
		
		if (strncmp("/bin/", arg21, 5) == 0) {
			execl(arg21, arg21,arg22, NULL);
			exit(0); 
		}
	
		else { 		 
		strcpy(path, "/bin/");
		strcat(path, arg21);
		}
               	
		execl(path, arg21, arg22, NULL);
		exit(0);
	}
	return 0;
}
