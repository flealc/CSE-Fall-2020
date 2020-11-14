#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main (int argc, char * argv[]){
	

	// Check for incorrect input //
	if (argc != 2) {
		printf("Error: incorrect number of arguments\n");
		return 1;
	}
	
	if (strlen(argv[1]) != 32) {
		printf("Error: Binary string must contain 32 digits\n");
		return 1;
	}
	

	int k;
	for (k = 0; k < 32; k ++) {
		if ((argv[1][k] > '1')) {	
			printf("Error: Enter only binary strings\n");
			return 1;
		}
	}	


	// Print sign //

	printf("Sign: %c\n", argv[1][0]);
	

	// Exponent operations //	
	int normcheck = 0;
	int exp = 0;
	double mant1 = 0;
	int i;
	for (i = 1; i < 9; i++) { 	
		if (argv[1][i] == '1') {
			normcheck++;
			exp = exp + pow(2, (8 -i));
		}
	}

	if (normcheck == 0) {
		printf("Exponent: 0\n");
	}
	else {
		printf("Exponent: %d\n", (exp));
	}
	
	// Mantissa operations //	
	int j;	
	for (j = 9; j < 32; j++) { 	
		if (argv[1][j] == '1') {
			mant1 = mant1 + pow(2, -(j - 8));
		}
	}
	
	if (normcheck == 0) {
		printf("Mantissa: %.17g\n", mant1);
	}
	else {
		printf("Mantissa: %.17g\n", mant1 + 1);
	}

	// Set sign //
	int sign;
	if (argv[1][0] == '0') {
		sign = 1;
	}
	else if (argv[1][0] == '1') {
		sign = -1;
	}


	// Print number //
	
	if (normcheck == 0) {
		printf("Number: %.7g\n", (sign * mant1 * pow(2, -126)));
	}
	else {
		printf("Number: %.7g\n", (sign * (mant1 + 1) * pow(2, (exp-127))));

	}

	return 0;

}
