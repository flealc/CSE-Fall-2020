#include <stdio.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
	
	char arg1[50];
	char arg2[50];

	if (argc > 3) {
                printf("Error: Incorrect number of arguments\n");
                return (-1);
       	}
	
	strcpy(arg1, "/bin/");
	strcpy(arg2,  argv[1]);
	strcat(arg1, arg2);	
	//printf("%s\n", arg1);
	execl(arg1, arg2, argv[2], NULL);
}
