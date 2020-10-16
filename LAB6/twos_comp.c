#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int binaryConv (int val) {
int i;
int value1 = val;
char buff1[8];
buff1[0] = '0';
for (i = 7; i >= 0; i--) {
	if ( (value1 % 2) == 0) {
		buff1[i] = '0';
		value1 = value1 / 2;
	}
	else if ( (value1 % 2) == 1) {
		buff1[i] = '1';
		value1 = value1 / 2;
	}
}
printf("%s\n", buff1);
return 0;
}


int negbinaryConv (int val) {
int i;
int value = ((val + (val * -2)) -1) ;
char buff[8];
buff[0] = '1';
for (i = 7; i >= 0; i--) {
	if ( (value % 2) == 0) {
		buff[i] = '1';
		value = value / 2;
	}
	else if ( (value % 2) == 1) {
		buff[i] = '0';
		value = value / 2;
	}
}
//buff[7] = '1';
printf("%s\n", buff);
return 0;
}

int main (int argc, char* argv[]) {
	
	// Check number of arguments //
	if (argc != 2) {
		printf("Error: incorrect number of arguments\n");
		return 1;
	}
	
	if (strcmp(argv[1], "0") == 0) {
		printf("00000000\n");
		return 0;
	}
	
	if (strcmp(argv[1], "-0") == 0) {
		printf("10000001\n");
		return 0;
	}
	
	// Check for valid input //
	if (atoi(argv[1]) == 0) {
		printf("Error: incorrect input\n");
		return 1;
	}
	
	// Check for valid range //
	if ((atoi(argv[1])  < -127) || (atoi(argv[1]) > 128)) {
		printf("Error: integer is out of range\n");
		return 1;
	}

 	if (atoi(argv[1]) > 0) {
		binaryConv(atoi(argv[1]));
	}	
 	
	if (atoi(argv[1]) < 0) {
		negbinaryConv(atoi(argv[1]));
	}	

return 0;
}


 
  
