#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

// CodeCamp.c -- EE 312 Project 1

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

/* The usual largest value an integer type can store
*/
int const MAX_INT_VALUE = 2147483647;

/* Calculates the magnitude of a positive input number. The magnitude is highest power of 10 inside the number. ex: 145 has magnitude 2.
*/
int magnitude(int num){
  int magnitude = 0;
  
  while (num != 0){
    num /= 10;
    magnitude++;
  }
  return magnitude - 1;
}

/* Calculates the power of ten according to the input exp: return 10^(exp). Only input positive int inputs.
*/
long power10(int exp){
  long answer = 1;
  for(int i = 0; i < exp; i++){
    answer *= 10l;
  }
  return answer;
}


/* Determine the hamming distance between two int arrays.
   pre: aList != null, bList != null, aList.length == bList.length == len
   post: return hamming distance between the two arrays of ints.
   Neither parameter should be altered by this function.
*/

int hammingDistance(int aList[], int bList[], int len) {

  // EE 312 Students: put your code here

  int numDifferences = 0;
  
  for(int i = 0; i < len; i++){
    if(aList[i] != bList[i]){
      numDifferences++;
    }
  }
  return numDifferences;
}


/* Determine if two ints have the same last digit.
   Note that the last digit of 0 is 0 and the last digit of -12 is 2. 
   post: return true if num1 and num2 have the same last digit, false otherwise.
*/

bool lastDigit(int num1, int num2) {

  // EE 312 Students: put your code here

  // make num1 positive
  if(num1 < 0){
    num1 *= -1;
  }
  // make num2 positive
  if(num2 < 0){
    num2 *= -1;
  }

  return num1 % 10 == num2 % 10;
}

/* Determine the sum of the positive integers less than 1000 that are multiples of 3 or 5 (or both).
   post: return the sum of the integers from 1 to 1000 that are multiples of 3 or 5 or both.
*/

int sum3or5Multiples() {

  // EE 312 Students: put your code here

  int sum = 0;

  for(int num = 1; num < 1000; num++){
    if(num % 3 ==0 || num % 5==0){
      sum += num;
    }
  }
  return sum;
}

/* Reverse the digits of an integer. Return the reversed number if it is in the range of type int, 0 otherwise.
   post: return num with digits reversed if the reverse can be stored as an int, 0 otherwise.
*/

int reverseInt(int num) {

  // EE 312 Students: put your code here

  bool negative = num < 0;
  if(negative){
    num *= -1;
  }

  int reversedInt = 0;

  for(int i = magnitude(num); i >= 0; i --){
    //get left most digit of num
    int digit = num % 10;
    //shift number left one
    num /= 10;

    long gain = (long) digit * power10(i);
    //check to see if reversedInt will overflow integer
    if((long)reversedInt+gain > (long)MAX_INT_VALUE){
      return 0;
    }
    else
      reversedInt += gain;
  }

  return negative? -reversedInt: reversedInt;
}




