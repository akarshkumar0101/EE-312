#include <stdio.h>

//Write a function to find the sum of digits of a number using recursion.

int sumDigits(int n){
	if(n == 0){
		return 0;
	}
	return (n % 10) + sumDigits(n / 10);
}

int main(){
    printf("Enter a number\n");
    int number;
    scanf("%d",&number);
    int result = sumDigits(number);
    printf("Sum of digits of number %d is %d \n",number,result);
    return 0;
}
