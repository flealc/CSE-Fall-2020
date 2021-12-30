#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char* argv[]) {

        if (argc != 3) {
                printf("Error: incorrect number of arguments\n");
                exit(EXIT_FAILURE);
        }

        FILE * fp;
        int str_count = 0;
        char *buf= NULL;
        size_t size = 0;
        char *str;


        if ((fp = fopen (argv[1], "r:")) == NULL) {
                printf("Error opening file");
                return(-1);
        }


        while(getline(&buf, &size, fp) != -1) {
                if ((strstr(buf,argv[2]) != NULL)) {
                        str_count++;
                }
        }

        fclose(fp);
        printf("%d\n",str_count);
	return 0;
}
