#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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
	char arg1[50];
        char arg2[50];
	char buf[100];
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

	else if (p > 0) {
		close(pip[0]);
		
		strcpy(arg1, argv[1]);
		strcpy(arg2, argv[2]);
		strcat(arg1, ",");
		strcat(arg1,arg2);
		write(pip[1], arg1, 100);
	} 

	else if (p == 0) { 
                
		close(pip[1]);
		read(pip[0], buf, 100);
		close(pip[0]);
		char arg21[50];
		char arg22[50];
		int i;
		char path[50];
		
		for (i = 0; i < strlen(argv[1]); i++) {
			arg21[i] = buf[i];		
		}

		
		for (i = 0; i < strlen(argv[2]); i++) {
			arg22[i] = buf[i + (strlen(argv[1]) + 1)];		
		}
		
		if (strncmp("/bin/", arg21, 5) == 0) {
			strcpy(path,arg21); 
		}
	
		else { 		 
		strcpy(path, "/bin/");
		strcat(path, arg21);
		
		}
               execl(path, arg21, arg22, NULL);
	}
	return 0;
}
