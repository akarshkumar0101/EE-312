#include<stdio.h>
#include<stdbool.h>


// CodeCampTester.c -- EE 312 Project 1 -- Tester class

/* Student information for assignment:
 * 
 * Name: Akarsh Kumar
 * email address: akarshkumar0101@utexas.edu
 * UTEID: ak39969
 * Section 5 digit ID: 16015
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
  int h1[] = {5,3,2,212,3,213890,1};
  int h2[] = {5,3,5,212,3,213891,45};
  int expected = 3;
  int actual = hammingDistance(h1, h2, 7);
  printf("Test 1 hamming distance: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf("passed test 1, hamming distance\n\n");
  else 
     printf("**** FAILED **** test 1, hamming distance\n\n");

  // test 2, hamming distance
  int h3[] = {-4,1,2,-6,-1,321,-9999,-1,-10,-42};
  int h4[] = {-4,9000000,2,-56,-1000,322,-9999,-1,-10,-42}; 
  expected = 4;
  actual = hammingDistance(h3, h4, 10);
  printf("Test 2 hamming distance: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf("passed test 2, hamming distance\n\n");
  else 
     printf("**** FAILED **** test 2, hamming distance\n\n");

  // test 3, hamming distance
  int h5[50000] = {0};
  int h6[50000] = {0};

  for(int i=0; i <50000; i++){
    h6[i] = i%2;
  }

  expected = 25000;
  actual = hammingDistance(h5, h6, 50000);
  printf("Test 3 hamming distance: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf("passed test 3, hamming distance\n\n");
  else 
     printf("**** FAILED **** test 3, hamming distance\n\n");

  // test 4, last digit
  int n1 = 98324320;
  int n2 = 80;
  expected = true;
  actual = lastDigit(n1, n2);
  printf("Test 4 last digit: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf("passed test 4, last digit\n\n");
  else 
     printf("**** FAILED **** test 4, last digit\n\n");

  // test 5, last digit
  n1 = -299349;
  n2 = -82349;
  expected = true;
  actual = lastDigit(n1, n2);
  printf("Test 4 last digit: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
    printf("passed test 5, last digit\n\n");
  else 
     printf("**** FAILED **** test 5, last digit\n\n");

  // test 6, last digit
  n1 = 72;
  n2 = -3823;
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
  n1 = -12345678;
  expected = -87654321;
  actual = reverseInt(n1);
  printf("Test 8 reverse int: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf("passed test 8, reverse int\n\n");
  else 
     printf("**** FAILED **** test 8, reverse int\n\n");

  // test 9, reverse int
  n1 = -1;
  expected = -1;
  actual = reverseInt(n1); 
  printf("Test 9 reverse int: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf("passed test 9, reverse int\n\n");
  else 
     printf("**** FAILED **** test 9, reverse int\n\n");

  // test 10, reverse int
  n1 = 1000000009;
  expected = 0;
  actual = reverseInt(n1); 
  printf("Test 10 reverse int: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf("passed test 10, reverse int\n");
  else 
     printf("**** FAILED **** test 10, reverse int\n");

}

