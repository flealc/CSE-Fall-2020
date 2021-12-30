#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>




void uppercase() {

	srand((unsigned int)time(NULL));
	char *upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i;
	for (i = 0; i < 10; i++) {
		printf("%c\n", upper[rand() % 26]);
	}	
}


void lowercase() {

	srand((unsigned int)time(NULL));
	char *lower = "abcdefghijklmnopqrstuvwxyz";
	int i;
	for (i = 0; i < 10; i++) {
		printf("%c\n", lower[rand() % 26]);
	}	
}

int main (int argc, char *argv[]) {

	if (argc != 2) {
		printf("Incorrect number of arguments\n");
		exit(1);
	}

	if (strcmp(argv[1],"-u") == 0) {
		uppercase();
	}
	
	else if (strcmp(argv[1],"-l") == 0) {
		lowercase();
	}

	else {
		printf("Invalid argument\n");
		exit(1);
	}
return 0;

}

