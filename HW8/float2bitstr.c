#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main (int argc, char * argv[]) {

	// Check for wrong input //
	
	if (argc == 1) {
		printf("No input given\n");
		return 1;
	}
	
	if (argc != 2) {
		printf("Error: Incorrect number of arguments\n");
		return 1;
	}

	// Count decimal places in input and check for sign//
	int i;
	int beforep = 0;
	int sign = 0;
	if (argv[1][0] == '-') {
		sign = 1;
		for (i = 0; i <= (strlen(argv[1])); i++) {
			if (argv[1][i] == '.') {
				beforep = i-1;
			}
		}
		int afterp = (strlen(argv[1]) - beforep) - 2;
//m		printf("%d\n", beforep);
//m		printf("%d\n", afterp);
	}
	else {
		for (i = 0; i <= (strlen(argv[1])); i++) {
			if (argv[1][i] == '.') {
				beforep = i;
			}
		}
	}

	// Separate integer and decimals //
	double f = atof(argv[1]);


	int integerp = (int) f;
	int reference = (int) f; 	
	int checkint = (int) f;
	double decimalp = f - integerp;
	
	if (integerp + decimalp == 0) {
		return 1;
	} 

//m	printf("%d\n", integerp);
//m	printf("%f\n", decimalp);
	
	if (sign == 1) {
		integerp = integerp * -1;
		reference = reference * -1;
		checkint = checkint * -1;
		decimalp = decimalp * -1;
	}
	
	//Create first part of Mantissa//
		
	//Convert integer part to binary//
	char bintlen = 0;
	
	for (i = 0; integerp >= 1; i++ ) {
		integerp = integerp / 2;
		bintlen = i + 1;
	}
	char intmantissa[bintlen + 1];
	intmantissa[bintlen] = '\0';
	int d;
	for (i = bintlen-1 ; i >= 0; i-- ) {
		d = reference >> i;
		if (d & 1) {
			intmantissa[(bintlen-1) - i] ='1';
			printf("1");
		}

		else {
			intmantissa[(bintlen- 1) -i] = '0';
			printf("0");
		}
	}
//m	printf("\n");
//m	printf("sign %i\n", bintlen);
	decimalp =  (decimalp * 100);
	int decimal = (int) decimalp;
	// Convert decimal part to binary //
	char decmantissa[48];
	for (i = 0; i < 48; i ++) {
		decimal = decimal * 2;
//m		printf("dec %d\n", decimal);
		if (decimal > 100) {
			decmantissa[i] = '1';
			decimal = decimal -100;
		}
		else {
			decmantissa[i] = '0';
		}
	}


	// Calculate exponent //
	int expo;
	int decexpoindex;
	if (checkint >= 1) {
		expo = (127 + (bintlen-1));
	}
	else if (checkint < 1) {
		for (i = 22; i >= 0; i --) {
	//		printf("check %i\n", i);
			if (decmantissa[i] == '1') {
				decexpoindex = i;
	//			printf("decexpind %i\n", decexpoindex);
			}
		}
		expo = 127 - (decexpoindex + 1);
	}

//m	printf("intmantissa %.*s\n", bintlen, intmantissa);
//m	printf("decmantissa %s\n", decmantissa);


	// Print string when checkint != 0//
	
	if (checkint != 0) {
		printf("%i", sign);
		for (i = 7 ; i >= 0; i-- ) {
			d = expo >> i;
			if (d & 1) {
				printf("1");
			}	

			else {
				printf("0");
			}

		}

		for (i = 0; i < (bintlen - 1); i++) {
			printf("%c", intmantissa[i + 1]);
		} 
		for (i = 0; i < (24 - bintlen); i++) {
			printf("%c", decmantissa[i]);
		} 
		printf("\n");	
	}
	// Print string when checkint == 0 //
	
	else if (checkint == 0) {
		
		printf("%i", sign);
		for (i = 7 ; i >= 0; i-- ) {
			d = expo >> i;
			if (d & 1) {
				printf("1");
			}	

			else {
				printf("0");
			}
		}
		
		for (i = 0; i < 23; i++) {
			printf("%c", decmantissa[i + (decexpoindex + 1)]);
		} 
		printf("\n");	
	}	
	return 0;
} 
