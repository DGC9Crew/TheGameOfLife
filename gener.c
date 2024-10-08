/*
* Created by Dgames_Crew (DGC9Crew)
* Conway's Game of Life in C - gener.c
* Generates the initial setup, randomly.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

int DIMi = 48; //rows
int DIMj = 1880; //columns
int randRate = 10; //random rate -> 1/randRate chance for each tile.
int main(int argc, char *argv[]) {
  	// read arguments
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
    //write file
	FILE *file;
	file = fopen("gen.txt", "w");
    srand(time(NULL));

	for(int i = 0; i < DIMi; i++) {
		for(int j = 0; j < DIMj; j++) {
            // make chance be 1/randRate
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
