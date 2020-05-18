#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include "stack_ll.h"

void populateWorld(char fname[], char *grid[], int *numRows, int *numCols);

void floodFill(char *grid[], int numRows, int numCols, StackEntry startLoc);

void showWorld(char *grid[], int numRows, int numCols);

int main(int argc, char *argv[]){
    char file[80];
    strcpy(file, argv[1]);
    const int MAX_ROWS = 25;
    char *world[MAX_ROWS];
    int numRows;
    int numCols;
    populateWorld(file, world, &numRows, &numCols);
    showWorld(world, numRows, numCols);

    int col = 0;
    int row = 0;
    char color;
    while(row != -1 && col != -1) {
        printf("\nEnter a row:");
        scanf("%d", &row);
        printf("Enter a column:");
        scanf("%d", &col);
        printf("Enter a color:");
        scanf(" %c", &color);
        if(row >= numRows || row < -1 || col >= numCols || col < -1){
            printf("Row or column out of bounds\n");
            exit(-1);
        }
        if(row != -1 && col != -1) {
            StackEntry entry;
            entry.row = row;
            entry.col = col;
            entry.color = color;
	    if(color != world[row][col]){
           	 floodFill(world, numRows, numCols, entry);
            }
            printf("\n");
            showWorld(world, numRows, numCols);
        }
    }

    for(int i = 0; i < numRows; i++){
        free(world[i]);
    }

    return 0;
}

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
	    if(strlen(currentRow) == 1){
            	*numCols = *numCols + 1;
            }
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
 * Takes a 2D character array and replaces all neighboring pixels with the same
 * color as the pixel location provided in startLoc and replaces it with the color
 * provided in startLoc
 *
 * Preconditions: startLoc has a row, col, color. grid[] is filled and no greater than 25x25
 * Postconditions: grid[] has been floodFilled by the color in startLoc
 */
void floodFill(char *grid[], int numRows, int numCols, StackEntry startLoc){
    char value = grid[startLoc.row][startLoc.col];
    Stack312 *s = (Stack312 *) malloc(sizeof(Stack312));
    makeStack(s);
    push(startLoc, s);
    while(!isEmpty(*s)){
        StackEntry currentLoc = pop(s);
        StackEntry neighborLoc;
        grid[currentLoc.row][currentLoc.col] = startLoc.color;
        // Excludes leftmost column, as they have no left neighbor
        if(currentLoc.col > 0){
            // Checks for matching value to the left
            if(grid[currentLoc.row][currentLoc.col - 1] == value){
                neighborLoc.row = currentLoc.row;
                neighborLoc.col = currentLoc.col - 1;
                neighborLoc.color = value;
                push(neighborLoc, s);
            }
        }
        // Excludes rightmost column
        if(currentLoc.col < numCols - 1){
            // Checks for matching value to the right
            if(grid[currentLoc.row][currentLoc.col + 1] == value){
                neighborLoc.row = currentLoc.row;
                neighborLoc.col = currentLoc.col + 1;
                neighborLoc.color = value;
                push(neighborLoc, s);
            }
        }
        // Excludes top row
        if(currentLoc.row > 0){
            // Checks for matching value on top
            if(grid[currentLoc.row - 1][currentLoc.col] == value){
                neighborLoc.row = currentLoc.row - 1;
                neighborLoc.col = currentLoc.col;
                neighborLoc.color = value;
                push(neighborLoc, s);
            }
        }
        // Excludes bottom row
        if(currentLoc.row < numRows - 1) {
            // Checks for matching value on bottom
            if(grid[currentLoc.row + 1][currentLoc.col] == value){
                neighborLoc.row = currentLoc.row + 1;
                neighborLoc.col = currentLoc.col;
                neighborLoc.color = value;
                push(neighborLoc, s);
            }
        }
        // Excludes left column and top row
        if((currentLoc.row > 0) && (currentLoc.col > 0)){
            // Checks for matching value top left
            if(grid[currentLoc.row - 1][currentLoc.col - 1] == value){
                neighborLoc.row = currentLoc.row - 1;
                neighborLoc.col = currentLoc.col - 1;
                neighborLoc.color = value;
                push(neighborLoc, s);
            }
        }
        // Excludes right column and top row
        if((currentLoc.row > 0) && (currentLoc.col < numCols - 1)){
            // Checks for matching value top right
            if(grid[currentLoc.row - 1][currentLoc.col + 1] == value){
                neighborLoc.row = currentLoc.row - 1;
                neighborLoc.col = currentLoc.col + 1;
                neighborLoc.color = value;
                push(neighborLoc, s);
            }
        }
        // Excludes left column and bottom row
        if((currentLoc.row < numRows - 1) && (currentLoc.col > 0)){
            // Checks for matching value bottom left
            if(grid[currentLoc.row + 1][currentLoc.col - 1] == value){
                neighborLoc.row = currentLoc.row + 1;
                neighborLoc.col = currentLoc.col - 1;
                neighborLoc.color = value;
                push(neighborLoc, s);
            }
        }
        // Excludes right column and bottom row
        if((currentLoc.row < numRows - 1) && (currentLoc.col < numCols - 1)){
            // Checks for matching value bottom right
            if(grid[currentLoc.row + 1][currentLoc.col + 1] == value){
                neighborLoc.row = currentLoc.row + 1;
                neighborLoc.col = currentLoc.col + 1;
                neighborLoc.color = value;
                push(neighborLoc, s);
            }
        }
    }
}

/*
 * Takes a 2D character array (grid), and the number of rows (numRows) and
 * columns (numCols) and outputs it the the screen.
 *
 * Preconditions: 2D character array (grid)
 * Postconditions: 2D array output to console
 */
void showWorld(char *grid[], int numRows, int numCols){
    for(int row = 0; row < numRows; row++){
        for(int col = 0; col < numCols; col++) {
            printf("%c", grid[row][col]);
        }
        printf("\n");
    }
}
