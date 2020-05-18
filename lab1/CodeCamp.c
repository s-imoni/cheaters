#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

// CodeCamp.c -- EE 312 Project 1

/* Student information for project:
 *
 * On my honor, Simoni Maniar, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Simoni Maniar
 * email address: s.imoni@utexas.edu
 * UTEID: ssm3256
 * Section 5 digit ID: 16085
 *
 * gcc -o Name -std=c99 Name.c Name2.c ...
 * ./Name
 */

/* Determine the hamming distance between two int arrays.
   pre: aList != null, bList != null, aList.length == bList.length == len
   post: return hamming distance between the two arrays of ints.
   Neither parameter should be altered by this function.
*/

int hammingDistance(int aList[], int bList[], int len) {
  int hammingCount = 0;
  for(int i = 0; i < len; i++){
      // If two values at the same index are not equal, add one to count
      if(aList[i] != bList[i]){
          hammingCount++;
      }
  }
  return hammingCount;
}

/* Determine if two ints have the same last digit.
   Note that the last digit of 0 is 0 and the last digit of -12 is 2. 
   post: return true if num1 and num2 have the same last digit, false otherwise.
*/

bool lastDigit(int num1, int num2) {
  const int TEN = 10;
  bool sameDigit = false;
  if((num1 % TEN) == (num2 % TEN)){
      sameDigit = true;
  }
  if((num1 % TEN) == -(num2 % TEN)){
      sameDigit = true;
  }
  return sameDigit;
}

/* Determine the sum of the positive integers less than 1000 that are multiples of 3 or 5 (or both).
   post: return the sum of the integers from 1 to 1000 that are multiples of 3 or 5 or both.
*/

int sum3or5Multiples() {
  int sum = 0;
  const int MAX = 1000;
  for(int i = 0; i < MAX; i++) {
      // If i is a multiple of 3 and/or 5, add to sum.
      if(i % 5 == 0 || i % 3 == 0){
         sum += i;
      }
  }
  return  sum;
}

/* Reverse the digits of an integer. Return the reversed number if it is in the range of type int, 0 otherwise.
   post: return num with digits reversed if the reverse can be stored as an int, 0 otherwise.
*/

int reverseInt(int num) {
  int reversedInt = 0;
  const int TEN = 10;
  while(num != 0){
      // Shift reversedInt over one place value and add last digit of initial integer
      reversedInt = (reversedInt * TEN) + (num % TEN);
      num = num / TEN;
  }
 return reversedInt;
}

  

