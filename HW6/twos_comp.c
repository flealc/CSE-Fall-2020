#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main (int argc, char* argv[]) {

	if (argc != 3) {
		printf("Error: Incorrect number of arguments\n");
		return 1;
	}
	
	
	int i;
	int result = 0;
	
	for (i = 0; i < 8; i++) {
		if ((argv[1])[i] > '1' ||  (argv[1])[i] < '0' ) {
		printf("Error: Only binary strings accepted\n");
		return 1;
		}
	}
	

	
	if (strcmp(argv[2], "unsigned") == 0 ) {
		for (i = 0; i < 8; i++) {
			if ((argv[1])[i] == '1') {
			result = (result + (pow(2,(7-i))));
			}
		}

	}
	
		

	
	
printf("%d\n", result);
return 0;
}

