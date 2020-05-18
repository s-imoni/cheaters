//life_driver.c
//
//Life Driver program
//Roger Priebe 9/5/2018
//EE 312


/* Student information for project:
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

//This file is a driver program for the life.c module.
//This program must work with your implementations life.h and life.c
//Do not change the function definitions for populateWorld, showWorld or
//iterateGeneration.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "life.h"

int main(int argc, char *argv[]) {

   //File name maximum size of 80
   char fName[80] = "world.txt";
   const int numGenerations = 250;

   // Read file name and number of generations from command line
   //strcpy(fName, argv[1]);
   //const int numGenerations = atoi(argv[2]);

   // Grid will not exceed 80 rows
   const int MAX_ROWS = 80;

   // Array of strings that will hold the grid
   char *world[MAX_ROWS];

   int numRows;
   int numCols;

   // Display initial world
   populateWorld(fName, world, &numRows, &numCols);
   showWorld(world, numRows, numCols);

   // Run iterations
   for (int iteration = 0; iteration < numGenerations; iteration++) {
     //system("clear");
     iterateGeneration(world, numRows, numCols);
     showWorld(world, numRows, numCols);
   }

   for(int i = 0; i < numRows; i++){
     free(world[i]);
   }

   return 0;

}



