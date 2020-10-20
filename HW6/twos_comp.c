#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int powerof(int num, int exp) {
	int result = 1;
	int index = 1;
	while(index <= exp) {
		result = result * num;
		index++;
	}
	return result;
}

//int bin_conv(char *bin) {
//h
	

int main (int argc, char* argv[]) {

	if (argc != 3) {
		printf("Error: Incorrect number of arguments\n");
		return 1;
	}
	
	
	int i;
	int result = 0;
	char buff[8];	
	for (i = 0; i < 8; i++) {
		if ((argv[1])[i] > '1' ||  (argv[1])[i] < '0' ) {
		printf("Error: Only binary strings accepted\n");
		return 1;
		}
	}
	

	// For Unsigned //
	if (strcmp(argv[2], "unsigned") == 0 ) {
		for (i = 0; i < 8; i++) {
			if ((argv[1])[i] == '1') {
			result = (result + (powerof(2,(7-i))));
			}
		}

	}
	
	// For Signed //
	else if (strcmp(argv[2], "signed") == 0 ) {
		// If positive //
		if ((argv[1])[0] == '0') {
			for (i = 0; i < 8; i++) {
				if ((argv[1])[i] == '1') {
				result = (result + (powerof(2,(7-i))));
				}
			}
		}
		// If negative //
		else if ((argv[1])[0] == '1') {
			// Invert //
			for (i = 0; i < 8; i++) {
				if ((argv[1])[i] == '1') {
					buff[i] = '0';
				}
				if ((argv[1])[i] == '0') {
					buff[i] = '1';
				}
			printf("%c\n", buff[i]);
			}
			for (i = 0; i < 8; i++) {
					if (buff[i] == '1') {
					result = (result + (powerof(2,(7-i))));
					}

			}
			result = result + 1;
			result = (result - (2 * result));		
		}
		
			
	}

	else {
		printf("Error: must specify signed or unsigned\n");
		return 1;
	}	
	
	
printf("%d\n", result);
return 0;
}

