#include <stdio.h>

//Write recursive function sum which adds up the first n numbers recursively

int sumRecur(int n, int currentNum);

int sum(int n){
	return sumRecur(n, 1);
}
int sumRecur(int n, int currentNum){
	if(currentNum == n){
		return n;
	}
	else if(currentNum > n){
		return 0;
	}

	return currentNum + sumRecur(n, currentNum+1);
}


int main() {
    printf("Enter Number \n");
    int number;
    scanf("%d",&number);
    int result = sum(number);
    printf("Sum of first %d numbers is : %d",number,result);
    return 0;
}