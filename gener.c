/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

int DIMi = 48;
int DIMj = 1880;
int randRate = 10;
int main(int argc, char *argv[]) {
	for(int i = 0; i < argc; i++) {
		char* tok = strtok(argv[i], "=");
		char* end = strtok(NULL, "=");
		if(strcmp(tok, "X") == 0) {
			DIMi = atoi(end);
		} else if(strcmp(tok, "Y") == 0) {
			DIMj = atoi(end);
		} else if(strcmp(tok, "R") == 0) {
			randRate = atoi(end);
		}
	}
	FILE *file;
	file = fopen("gen.txt", "w");
    srand(time(NULL));

	for(int i = 0; i < DIMi; i++) {
		for(int j = 0; j < DIMj; j++) {
            int r = rand() % randRate;
            if(r == 0) {
              fprintf(file, "1");
            } else {
              fprintf(file, "0");
            }
		}
        fprintf(file, "\n");
	}
	fclose(file);

	return 0;
}
