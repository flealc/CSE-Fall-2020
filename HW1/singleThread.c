#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (int argc, char* argv[]) {

	if (argc != 5) {
                printf("Error: incorrect number of arguments\n");
                return -1;
        }



        FILE * fp;
        int str_count = 0;
        char *buf = NULL;
        size_t size = 0;
        char *str;
	

	FILE * fp1;
        int str_count1 = 0;
        char *buf1 = NULL;
        size_t size1 = 0;
        char *str1;



        if ((fp = fopen (argv[1], "r:")) == NULL) {
                printf("Error opening file");
                return(-1);
        }


        while(getline(&buf, &size, fp) != -1){
		char *lp = buf;
              while ((lp=(strstr(lp,argv[2]))) != NULL) {
                        str_count++;
			++lp;
	       }
        }



       if ((fp1 = fopen (argv[3], "r:")) == NULL) {
             	 printf("Error opening file");
                return(-1);
       }

       while(getline(&buf1, &size1, fp1) != -1){
		char *lp1 = buf1;
                while ((lp1=(strstr(lp1,argv[4]))) != NULL) {
                        str_count1++;
			++lp1;
               }
        }
       
	printf("football Count: %d\n", str_count);
	printf("username Count: %d\n", str_count1);
	
	fclose(fp);
	fclose(fp1);
	return 0;


}



