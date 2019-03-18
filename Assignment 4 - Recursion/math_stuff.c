/* mathStuff_ak39969.c

Roger Priebe and Akarsh Kumar
cs1428 10/15/2007 (updated 3/24/09)
EE312  10/3/2018

Finish comments here
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

//**********  Function Prototypes  ******************

//function isPrime
//input parameter - positive integer
//returns true if the number is prime, otherwise false
//
// Complexity: O(sqrt(n))
bool isPrime (int number);

//a helper function for isPrime that uses recursion to check if number is prime
bool isPrimeRecur(int number, int currentlyChecking);

//function printPrimes
//input parameter - positive integer
//Uses the isPrime method to print a list of prime numbers between 1 and n. 

// Complexity: O(n*sqrt(n))
void printPrimes (int n);

// a helper function for printPrimes that uses recursion to print all primes up to a number
void printPrimesRecur(int n, int currentlyChecking);


//function findFibo
//input parameter - positive integer
//returns the nth fibonacci number where
//Fib(0) -> 0 
//Fib(1) -> 1 
//Fib(N) -> Fib(N-2) + Fib(N-1)
// Complexity: O(n)
int findFibo (int n);

// a helper function for findFibo that uses recursion on itself to find F(n) and F(n-1) (stored in a 2D array).
// This function returns a heap allocated 2D array in order to reduce the algorithm from O(2^n) to O(n)

int* findFiboRecur(int n);


//function findFactors
//input parameter - positive integer
//prints the prime factors of the given number to standard output (cout)
//example output: 52=2*2*13 (or 52=1*2*2*13) or 13=prime

// Complexity: O(sqrt(n)) or O(n) depending on whether n is prime or not
void findFactors (int number);

// a helper function that prints the factors of a number that uses recursion on itself.
void printFactorsRecur(int number, int currentlyChecking, const int START_DIVISOR);

//******************  MAIN  *****************************

int main () {
    
    
    int testNum;
    
    //test for the isPrime function
    printf("Enter a test number - ");
    scanf("%d",&testNum);
    
    if (isPrime(testNum))  
       printf("%d is prime.\n",testNum);
    else
       printf("%d is not prime.\n", testNum);
    
    //test for printing primes
    printf("Enter n to print the prime numbers between 1 and n: ");
    scanf("%d",&testNum);
    
    printPrimes(testNum);
    
    printf("\n");
    
    //test for Fibonacci number finder
    printf("Which Fibonacci number? ");
    scanf("%d",&testNum);

    printf("The %d Fibonacci number is : %d \n", testNum, findFibo(testNum)); 
    
    printf("\n");
    
    //test for prime factors
    printf("Factor what number? ");
    scanf("%d",&testNum);
    
    findFactors(testNum);
    
    return 0;
}




//function isPrime
//input parameter - positive integer
//returns true if the number is prime, otherwise false
//

bool isPrime (int number) {
   const int START_DIVISOR = 2; //HINT: You may want a helper function

   //YOUR CODE GOES HERE
   if(number < 2){
     return false;
   }
   return isPrimeRecur(number, START_DIVISOR);
}
bool isPrimeRecur(int number, int currentlyChecking){
  if(currentlyChecking >= sqrt(number)){
    return true;
  }
  if(number % currentlyChecking == 0){
    return false;
  }
  return isPrimeRecur(number, currentlyChecking + 1);
}


//function printPrimes
//input parameter - positive integer
//Uses the isPrime method to print a list of prime numbers between 1 and n. 

void printPrimes (int n) {

   //YOUR CODE GOES HERE
  const int START_PRIME_CHECKING = 2;

  printPrimesRecur(n, START_PRIME_CHECKING);
} 

void printPrimesRecur(int n, int currentlyChecking){
  if(currentlyChecking <= n){
    if(isPrime(currentlyChecking)){
      printf("%d is prime\n", currentlyChecking);
    }
    printPrimesRecur(n, currentlyChecking+1);
  }
}


//function findFibo
//input parameter - positive integer
//returns the nth fibonacci number where
//Fib(0) -> 0 
//Fib(1) -> 1 
//Fib(N) -> Fib(N-2) + Fib(N-1)

int findFibo (int n) {
    
   //YOUR CODE GOES HERE

  //base case
  if(n < 2){
    return n;
  }
  //return findFibo(n-2) + findFibo(n-1);

  int* arr2D = findFiboRecur(n);
  int ans = arr2D[1];
  free(arr2D);
  return ans;
}

int* findFiboRecur(int n){
  //base case
  if(n == 1){
    int *arr2D = (int *) malloc(2 * sizeof(int));
    arr2D[0] = 0;
    arr2D[1] = 1;
    return arr2D;
  }
  else{
    int *arr2D = findFiboRecur(n-1);
    int a = arr2D[0], b = arr2D[1];
    arr2D[0] = b;
    arr2D[1] = a+b;
    return arr2D;
  }
}


//function findFactors
//input parameter - positive integer
//prints the prime factors of the given number to standard output (cout)
//example output: 52=2*2*13 (or 52=1*2*2*13) or 13=prime

void findFactors (int number) {
    const int START_DIVISOR = 2; //HINT: You may want a helper function
     
   //YOUR CODE GOES HERE

    printf("%d=", number);
    if(isPrime(number)){
      printf("prime");
    }
    else{
      printFactorsRecur(number, START_DIVISOR, START_DIVISOR);
    }
    printf("\n");
}

void printFactorsRecur(int number, int currentlyChecking, const int START_DIVISOR) {
  //base case
  if(currentlyChecking>=number){
    printf("%d",number);
  }
  else if(number % currentlyChecking == 0){
    printf("%d*", currentlyChecking);
    printFactorsRecur(number/currentlyChecking, START_DIVISOR, START_DIVISOR);
  }
  else{
    printFactorsRecur(number, currentlyChecking+1, START_DIVISOR);
  }
}


