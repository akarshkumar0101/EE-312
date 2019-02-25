// life.h
// -- EE 312 Project 2

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
 *///
// Created by priebe on 9/5/2018.
//

#ifndef UNTITLED1_LIFE_H
#define UNTITLED1_LIFE_H

#endif //UNTITLED1_LIFE_H

/*
	This method is used to populate the grid (local array of strings on the heap) using a specific file. 
	This method also sets the value of numRows and numCols when they are passed in as pointers.

	pre condition: fname is a valid and real file name, grid has enough rows to store all the rows from the file
*/
void populateWorld(char fname[], char *grid[], int *numRows, int *numCols);

/*
	This method displays the grid (array of strings) character by character onto the screen using printf.

	pre condition: numRows and numCols accurately represents dimension of grid
*/
void showWorld(char *grid[], int numRows, int numCols);

/*
	This method is used to iterate a generation of game of life by John Conway on the grid(array of strings) passed in. 

	pre condition: grid is an array of strings that all have the same length and are only composed of '0's and '1's,
	numRows and numCols accurately represents the grid dimensions
*/
void iterateGeneration(char *grid[], int numRows, int numCols);
