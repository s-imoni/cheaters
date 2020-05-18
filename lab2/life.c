/* Student information for project:
 *
 *
 * On my honor, Simoni Maniar, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Simoni Maniar
 * email address: s.imoni@utexas.edu
 * UTEID: ssm3256
 * Section 5 digit ID: 16115
 *
 */

#include "life.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Takes a string that consists of a file name (fname) and stores the values
 * from the file in a 2D character array (grid). Also calculates number of
 * rows (numRows) and columns (numCols) in grid.
 *
 * Preconditions: fname[] will have a should length of 80
 * Postconditions: grid will store the contents of fname[]
 */
void populateWorld(char fname[], char *grid[], int *numRows, int *numCols) {
    *numRows = 0;
    *numCols = 0;
    const int MAX_LEN = 80;
    char currentRow[MAX_LEN];
    FILE *inputFile = fopen(fname, "r");

    // Exit on error
    if(inputFile == NULL){
        printf("Error in Opening File");
        exit(-1);
    }

    // Read each row and store in grid
    while (fgets(currentRow, MAX_LEN, inputFile) != NULL) {
        // Calculate numCols, exclude '\n'
        if(*numRows == 0) {
            *numCols = strlen(currentRow) - 1;
        }
        //Replace '\n' with NULL at the end of string
        currentRow[*numCols] = '\0';
        grid[*numRows] = malloc((*numCols) * sizeof(char));
        strncpy(grid[*numRows], currentRow, *numCols);
        // Increment row to calculate row
        *numRows = *numRows + 1;
    }
    fclose(inputFile);
}

/*
 * Takes a 2D character array (grid), and the number of rows (numRows) and
 * columns (numCols) and outputs it the the screen.
 *
 * Preconditions: 2D character array (grid) of '0' and '1'
 * Postconditions: 2D array output to console, with '1' represented as '*'
 * and '0' represented as '.'
 */
void showWorld(char *grid[], int numRows, int numCols){
    for(int row = 0; row < numRows; row++){
        for(int col = 0; col < numCols; col++){
            // If '1' print '*'
            if(grid[row][col] == '1'){
                printf("*");
            }
            // If '0' print '.'
            if(grid[row][col] == '0'){
                printf(".");
            }
        }
        printf("\n");
    }
}

/*
 * Takes 2D character array (grid), number of rows (numRows),
 * and number of columns (numCols) and updates grid to next
 * generation based on the rules for the game of life.
 *
 * Postconditions: grid contains values for next generation
 */
void iterateGeneration(char *grid[], int numRows, int numCols){
    char newGen[numRows][numCols];
    for(int row = 0; row < numRows; row++){
        for(int col = 0; col < numCols; col++){
            int livingNeighbors = 0;
            // Excludes leftmost column, as they have no left neighbor
            if(col > 0){
                // Checks for living neighbor to the left
                if(grid[row][col - 1] == '1'){
                    livingNeighbors++;
                }
            }
            // Excludes rightmost column
            if(col < numCols - 1){
                // Checks for living neighbor to the right
                if(grid[row][col + 1] == '1'){
                    livingNeighbors++;
                }
            }
            // Excludes top row
            if(row > 0){
                // Checks for living neighbor on top
                if(grid[row - 1][col] == '1'){
                    livingNeighbors++;
                }
            }
            // Excludes bottom row
            if(row < numRows - 1) {
                // Checks for living neighbor on bottom
                if(grid[row + 1][col] == '1'){
                    livingNeighbors++;
                }
            }
            // Excludes left column and top row
            if((row > 0) && (col > 0)){
                // Checks for living neighbor top left
                if(grid[row - 1][col - 1] == '1'){
                    livingNeighbors++;
                }
            }
            // Excludes right column and top row
            if((row > 0) && (col < numCols - 1)){
                // Checks for living neighbor top right
                if(grid[row - 1][col + 1] == '1'){
                    livingNeighbors++;
                }
            }
            // Excludes left column and bottom row
            if((row < numRows - 1) && (col > 0)){
                // Checks for living neighbor bottom left
                if(grid[row + 1][col - 1] == '1'){
                    livingNeighbors++;
                }
            }
            // Excludes right column and bottom row
            if((row < numRows - 1) && (col < numCols - 1)){
                // Checks for living neighbor bottom right
                if(grid[row + 1][col + 1] == '1'){
                    livingNeighbors++;
                }
            }

            char nextGenStatus = '0';
            // Game rules: If currently dead and 3 living neighbors,
            // alive in next generation
            if(grid[row][col] == '0') {
                if (livingNeighbors == 3) {
                    nextGenStatus = '1';
                }
            }
            if(grid[row][col] == '1'){
                // Game rules, cont.: If currently alive and 3 or 2
                // living neighbors, alive in next generation
                if((livingNeighbors == 3) || (livingNeighbors == 2)){
                    nextGenStatus = '1';
                }
            }
            // Game rules, cont.: Otherwise, dead
            newGen[row][col] = nextGenStatus;
        }
    }

    // Copy newGen into grid
    for(int row = 0; row < numRows; row++){
        for(int col = 0; col < numCols; col++){
            grid[row][col] = newGen[row][col];
        }
    }
}
