#include <stdio.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

        int pip[2];
	char buf[50];
	

	if (argc != 3) {
                printf("Error: Incorrect number of arguments\n");
                return (-1);
       	}
	
	pipe(pip);
	if (pipe(pip) == -1) {
                fprintf(stderr, "Pipe error");
                return 1;
	}

	write(pip[1], argv[1], strlen(argv[1]));
        write(pip[1], "\n", strlen("\n"));
	write(pip[1], argv[2], strlen(argv[2]));
	read(pip[0], buf, 50);
	printf("%s\n", buf);
}
