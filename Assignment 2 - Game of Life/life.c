//life.c
//
//Life Implementation program
//Akarsh Kumar 2/5/2019
//EE 312


/* Student information for project:
 *
 * Replace <NAME> with your name.
 *
 * On my honor, Akarsh Kumar, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Akarsh Kumar
 * email address: akarshkumar0101@utexas.edu
 * UTEID: ak39969
 * Section 5 digit ID: 16015
 *
 */

//This file is the implementation of Conway's Game of Life
//This file is just a library of functions that should be run from the life_driver.c module.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
	This method is to spawn a cell in a specific row and column coordinate of the grid
	 if the necessary conditions of birth are met.
	This method should be called with the world as an array of strings (grid), the row and column coordinates,
	and the array of int arrays that specify the number of cells that are alive around each coordinate.

	pre condition: row and col are valid indexes for the grid, and numAliveCellsAround is the same dimension as grid
*/
void cellSpawn(char *grid[], int row, int col, int *numAliveCellsAroundGrid[]){
	if(numAliveCellsAroundGrid[row][col] == 3){
		grid[row][col] = '1';
	}
}
/*
	This method is to kill a cell in a specific row and column coordinate of the grid
	 if the necessary conditions of overcrowding are met.
	This method should be called with the world as an array of strings (grid), the row and column coordinates,
	and the array of int arrays that specify the number of cells that are alive around each coordinate.

	pre condition: row and col are valid indexes for the grid, and numAliveCellsAround is the same dimension as grid
*/
void cellDieFromOvercrowding(char *grid[], int row, int col, int *numAliveCellsAroundGrid[]){
	if(numAliveCellsAroundGrid[row][col] >= 4){
		grid[row][col] = '0';
	}
}
/*
	This method is to kill a cell in a specific row and column coordinate of the grid
	 if the necessary conditions of loneliness are met.
	This method should be called with the world as an array of strings (grid), the row and column coordinates,
	and the array of int arrays that specify the number of cells that are alive around each coordinate.

	pre condition: row and col are valid indexes for the grid, and numAliveCellsAround is the same dimension as grid
*/
void cellDieFromLoneliness(char *grid[], int row, int col, int *numAliveCellsAroundGrid[]){
	if(numAliveCellsAroundGrid[row][col] <= 1){
		grid[row][col] = '0';
	}
}
/*
	This method is used to calculate the number of cells that are alive around a cell.
	This method should be called with the world as an array of strings (grid), the row and column coordinates,
	and the total number of rows and columns in the grid.

	pre condition: row and col are valid indexes for the grid and numRows and numCols specify the correct dimensions
*/
int numAliveCellsAround(char *grid[], int row, int col, int numRows, int numCols){
	int numAlive = 0;

	for(int y = row - 1; y <= row + 1; y++){
		for(int x = col-1; x<= col+1;x++){
			if(y==row && x==col){
				continue;
			}
			if(x<0 || x>=numCols || y <0 || y>= numRows){
				continue;
			}
			if(grid[y][x]=='1'){
				numAlive ++;
			}
		}
	}

	return numAlive;
}

/*
	This method is used to populate the grid (local array of strings on the heap) using a specific file. 
	This method also sets the value of numRows and numCols when they are passed in as pointers.

	pre condition: fname is a valid and real file name, grid has enough rows to store all the rows from the file
*/
void populateWorld(char* fname, char *grid[], int *numRows, int *numCols){
	FILE *fp = fopen(fname, "r");

	*numCols = 0;
	*numRows = 0;

	const int MAX_COLS = 1000;
	char buffer[MAX_COLS];

	while(1) {
		char* ptr = fgets(buffer, MAX_COLS, fp);
		if(ptr == NULL) {
			break;
		}

		int readLenWithReturnChar = strlen(buffer);
		//crop the string to get rid of return;
		buffer[readLenWithReturnChar-1] = '\0';
		//new row length of just real data
		int rowlen = strlen(buffer);
		//rowlen+1 to include space for null terminating character
		char* gamestr = malloc((rowlen + 1) * sizeof(char));
		strcpy(gamestr, buffer);

		grid[*numRows] = gamestr;
		(*numRows)++;
		*numCols = rowlen;
	}
}
/*
	This method displays the grid (array of strings) character by character onto the screen using printf.

	pre condition: numRows and numCols accurately represents dimension of grid
*/
void showWorld(char *grid[], int numRows, int numCols){

	for(int row = 0; row < numRows; row ++) {
		for(int col = 0; col < numCols; col ++) {
			printf("%c", (grid[row][col] == '0'? '.' : '*'));
		}
		printf("\n");
	}
	printf("\n\n");
}
/*
	This method is used to iterate a generation of game of life by John Conway on the grid(array of strings) passed in. 

	pre condition: grid is an array of strings that all have the same length and are only composed of '0's and '1's,
	numRows and numCols accurately represents the grid dimensions
*/
void iterateGeneration(char *grid[], int numRows, int numCols){
	int* numAliveCellsAroundGrid[numRows];

	for(int row = 0; row < numRows; row ++) {
		numAliveCellsAroundGrid[row] = malloc(numCols * sizeof(int));
		for(int col = 0; col < numCols; col ++) {
			numAliveCellsAroundGrid[row][col] = numAliveCellsAround(grid, row, col, numRows, numCols);
		}
	}

	for(int row = 0; row < numRows; row ++) {
		for(int col = 0; col < numCols; col ++) {
			cellSpawn(grid, row, col, numAliveCellsAroundGrid);
			cellDieFromOvercrowding(grid, row, col, numAliveCellsAroundGrid);
			cellDieFromLoneliness(grid, row, col, numAliveCellsAroundGrid);
		}
	}
	for(int row = 0; row < numRows; row ++){
		free(numAliveCellsAroundGrid[row]);
	}
	
}


