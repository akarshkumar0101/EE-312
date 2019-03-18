//Flood Fill

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#define MAX_ROWS 30
#define MAX_COLS 30


//print the given picture onto the console
void printPicture(char *picture[], int numRows, int numCols);
//set the picture with values read in from the file and set the numRows and numCols variables
void setPicture(char *fName, char *picture[], int *numRows, int *numCols);
//free the picture's strings from memory and delete the picture
void delPicture(char *picture[], int numRows);
//flood fill a pixel at the given column and row with a given color
void floodFill(char *picture[], int numRows, int numCols, int row, int col, char color);
//a helper method that flood fills using recursion on itself
void floodFillRecur(char *picture[], int numRows, int numCols, int row, int col, char originalColor, char color);

int main(int argc, char *argv[]){
	char *fName = argv[1];

	char *picture[MAX_ROWS];
	int numRows;
	int numCols;

	setPicture(fName, picture, &numRows, &numCols);

	while(1){
		printf("\n");
		printPicture(picture, numRows, numCols);
		printf("\n");

		char rowInput[5];
		char colInput[5];
		char colorInput[2];

		printf("Enter a row: ");
		scanf("%5s", rowInput);

		int row = atoi(rowInput);

		printf("Enter a column: ");
		scanf("%5s", colInput);

		int col = atoi(colInput);

		if(row >= numRows || col >= numCols){
			printf("(%d, %d) is an invalid coordinate for this picture\n", row, col);
			continue;
		}

		printf("Enter a color: ");
		scanf("%2s", colorInput);
		
		char color = colorInput[0];

		if(row < 0 || col < 0){
			break;
		}

		floodFill(picture, numRows, numCols, row, col, color);

	}
	printf("\n");

	delPicture(picture, numRows);

	return 0;
}
void printPicture(char *picture[], int numRows, int numCols){
	for(int row = 0; row < numRows; row ++) {
		for(int col = 0; col < numCols; col ++) {
			printf("%c",picture[row][col]);
		}
		printf("\n");
	}
}
void setPicture(char *fName, char *picture[], int *numRows, int *numCols) {
	FILE *fp = fopen(fName, "r");
	*numRows = 0;
	*numCols = 0;

	char buffer[MAX_COLS];

	while(1){
		char* ptr = fgets(buffer, MAX_COLS, fp);
		if(ptr == NULL){
			break;
		}
		//int readLenWithReturnChar = strlen(buffer);

		//crop the string to get rid of return;
		//buffer[readLenWithReturnChar] = '\0';
		//new row length of just real data
		int rowlen = strlen(buffer);
		//rowlen+1 to include space for null terminating character
		char* picstr = malloc((rowlen + 1) * sizeof(char));
		strcpy(picstr, buffer);

		picture[*numRows] = picstr;
		(*numRows)++;

		//wont have length with \n because it is value of last line (that doesn't have \n)
		*numCols = rowlen;
	}
}
void delPicture(char *picture[], int numRows){
	for(int i=0; i < numRows; i ++){
		free(picture[i]);
	}
}

void floodFill(char *picture[], int numRows, int numCols, int row, int col, char color){
	if(picture[row][col] != color){
		floodFillRecur(picture,numRows, numCols, row, col, picture[row][col], color);
	}
}
void floodFillRecur(char *picture[], int numRows, int numCols, int row, int col, char originalColor, char color){
	picture[row][col] = color;
	for(int relx = -1; relx <= 1; relx++){
		for(int rely = -1; rely <= 1; rely++){
			int nextrow = row+rely;
			int nextcol = col+relx;
			if(nextrow >=0 && nextrow < numRows && nextcol >= 0 && nextcol < numCols && picture[nextrow][nextcol] == originalColor){
				floodFillRecur(picture, numRows, numCols, nextrow, nextcol, originalColor, color);
			}
		}
	}
}



