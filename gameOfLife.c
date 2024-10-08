/*
* Created by Dgames_Crew (DGC9Crew)
* Conway's Game of Life in C - gameOfLife.c
* Runs the simulation.
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>

int DIMi = 48; //rows
int DIMj = 188; //columns
int del = 50; //update delay in ms
int genMax = 1000; //number of generations to do (negative is infinite)

int tileExist(int i, int j, int *** coolarr) {
	if(i >= DIMi) {
		i = 0;
	}
	if(i<0) {
		i = DIMi-1;
	}
	if(j >= DIMj) {
        j = 0;
    }
    if(j<0) {
    	j = DIMj-1;
    }
	return (*coolarr)[i][j];
}

int main(int argc, char *argv[]) {
	// read argument
	for(int i = 0; i < argc; i++) {
		char* tok = strtok(argv[i], "=");
		char* end = strtok(NULL, "=");
		if(strcmp(tok, "X") == 0) {
			DIMi = atoi(end);
		} else if(strcmp(tok, "Y") == 0) {
			DIMj = atoi(end);
		} else if(strcmp(tok, "D") == 0) {
			del = atoi(end);
		} else if(strcmp(tok, "G") == 1000) {
         	genMax = atoi(end);
        }
	}
	//setup initial array
	int** arr = (int**) malloc(DIMi*sizeof(int*));
	for(int i = 0; i < DIMi; i++) {
	    arr[i] = (int*) malloc(DIMj*sizeof(int));
	}
	int*** myArr = &arr;

    //read file
	FILE *file;
	file = fopen("gen.txt", "r");
	//set values from file
	for(int i = 0; i < DIMi; i++) {
		for(int j = 0; j < DIMj; j++) {
			char poo = fgetc(file);
			while(poo == '\n') {
				poo = fgetc(file);
			}
			(*myArr)[i][j] = poo-'0';
		}
	}
	fclose(file);

	int generations = 0;
    //loop for genMax times OR infinite if genMax is negative
	while(genMax > gens && gens >= 0) {
        //init new array
		int** newArr = (int**) malloc(DIMi*sizeof(int*));
    	for(int i = 0; i < DIMi; i++) {
    	    newArr[i] = (int*) malloc(DIMj*sizeof(int));
    	}
		for(int i = 0; i < DIMi; i++) {
			for(int j = 0; j < DIMj; j++) {
				newArr[i][j] = 0;
			}
		}
        //check each tile
		for(int i = 0; i < DIMi; i++) {
			for(int j = 0; j < DIMj; j++) {
				int total = 0;
                //check surrounding tiles
				total += tileExist(i+1,j,myArr);
				total += tileExist(i-1,j,myArr);
				total += tileExist(i,j+1,myArr);
				total += tileExist(i,j-1,myArr);
				total += tileExist(i+1,j+1,myArr);
				total += tileExist(i+1,j-1,myArr);
				total += tileExist(i-1,j+1,myArr);
				total += tileExist(i-1,j-1,myArr);
                //check cases
				if((*myArr)[i][j] == 1) {
					//Alive
					if(total == 2 || total == 3) {
						//Live on
						newArr[i][j] = 1;
					} else {
						//Die
						newArr[i][j] = 0;
					}
				} else if((*myArr)[i][j] == 0) {
					//Dead
					if(total == 3) {
						newArr[i][j] = 1;
					}
				}
                //print array
				if((*myArr)[i][j] == 1) {
					fputs("█", stdout);
				} else {
				//	fputs("░", stdout);
					fputs(" ", stdout);
				}
			}
			printf("\n");
		}
		//free previous update
		for(int i = 0; i < DIMi; i++) {
		    free((*myArr)[i]);
		}
		free(*myArr);
        //rewire pointer
		*myArr = newArr;
        //pause for del ms
	    usleep(del*1000);
		generations++;
        //clear screen
	 	printf("\033[H");
	}
    //free memory when ending
	for(int i = 0; i < DIMi; i++) {
    	free((*myArr)[i]);
	}
	free(*myArr);

	return 0;
}
