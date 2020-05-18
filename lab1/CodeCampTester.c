#include<stdio.h>
#include<stdbool.h>


// CodeCampTester.c -- EE 312 Project 1 -- Tester class

/* Student information for assignment:
 * 
 * Name: Simoni Maniar
 * email address: s.imoni@utexas.edu
 * UTEID: ssm3256
 * Section 5 digit ID: 16085
 *  
 */

//function prototypes. These will be completed in CodeCamp.c
int hammingDistance(int aList[], int bList[], int len);
int sum3or5Multiples();
bool lastDigit(int num1, int num2);
int reverseInt(int num); 
//****************************

int main() {
  
  // test 1, hammingDistance
  int h1[] = {9, 7, 5, 3, 0, 2, 2, 2, 2};
  int h2[] = {2, 2, 2, 2, 2, 2, 2, 2, 2};
  int expected = 5;
  int actual = hammingDistance(h1, h2, 9);
  printf("Test 1 hamming distance: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf("passed test 1, hamming distance\n\n");
  else 
     printf("**** FAILED **** test 1, hamming distance\n\n");

  // test 3, hamming distance
  int h3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int h4[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  expected = 0;
  actual = hammingDistance(h3, h4, 10);
  printf("Test 2 hamming distance: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)
      printf("passed test 2, hamming distance\n\n");
  else
      printf("**** FAILED **** test 2, hamming distance\n\n");

  // test 3, hamming distance
  int h5[5] = {9,9,9,0,8};
  int h6[5] = {8,0,8,8,8};
  expected = 4;
  actual = hammingDistance(h5, h6, 5);
  printf("Test 3 hamming distance: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf("passed test 3, hamming distance\n\n");
  else 
     printf("**** FAILED **** test 3, hamming distance\n\n");

  // test 4, last digit
  int n1 = 50;
  int n2 = 0;
  expected = true;
  actual = lastDigit(n1, n2);
  printf("Test 4 last digit: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf("passed test 4, last digit\n\n");
  else 
     printf("**** FAILED **** test 4, last digit\n\n");

  // test 5, last digit
  n1 = -44;
  n2 = -994;
  expected = true;
  actual = lastDigit(n1, n2);
  printf("Test 4 last digit: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
    printf("passed test 5, last digit\n\n");
  else 
     printf("**** FAILED **** test 5, last digit\n\n");

  // test 6, last digit
  n1 = -22;
  n2 = 15;
  expected = false;
  actual = lastDigit(n1, n2);
  printf("Test 6 last digit: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)   
    printf("passed test 6, last digit\n\n");
  else 
     printf("**** FAILED **** test 6, last digit\n\n");

  // test 7, sum of multiples of 3 or 5
  expected = 233168;
  actual = sum3or5Multiples();
  printf("Test 7 sum of multiples: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf("passed test 7, sum of multiples of 3 or 5\n\n");
  else 
     printf("**** FAILED **** test 7, sum of multiples of 3 or 5\n\n");

  // test 8, reverse int
  n1 = -6001;
  expected = -1006;
  actual = reverseInt(n1);
  printf("Test 8 reverse int: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf("passed test 8, reverse int\n\n");
  else 
     printf("**** FAILED **** test 8, reverse int\n\n");

  // test 9, reverse int
  n1 = 9000;
  expected = 9;
  actual = reverseInt(n1); 
  printf("Test 9 reverse int: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf("passed test 9, reverse int\n\n");
  else 
     printf("**** FAILED **** test 9, reverse int\n\n");

  // test 10, reverse int
  n1 = 1;
  expected = 1;
  actual = reverseInt(n1); 
  printf("Test 10 reverse int: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf("passed test 10, reverse int\n");
  else 
     printf("**** FAILED **** test 10, reverse int\n");

}

