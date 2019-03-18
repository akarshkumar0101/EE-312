#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//Write a function which checks if given string is palindrome or not recursively
//returns true if its a palindrome and false if its not.
bool isPalindromeRecur(char *str, int checkingIndex, int strLen);

bool isPalindrome(char *str){

}
bool isPalindromeRecur(char *str, int checkingIndex, int strLen){
    if(checkingIndex > strLen / 2){
        return true;
    }
    return (str[checkingIndex] == str[strLen-checkingIndex-1]) && (isPalindromeRecur(str, checkingIndex+1, strLen));
}

int main()
{
    char wordPal[25];
    printf("\n\n Recursion : Check a given string is Palindrome or not :\n");
    printf("----------------------------------------------------------\n");

    printf(" Input  a word to check for palindrome : ");
    scanf("%s", wordPal);
    bool result;
    //call the function

    if(result){
        printf("%s is a Palindrome \n",wordPal);
    } else {
        printf("%s is not a Palindrome \n",wordPal);
    }

    return 0;
}
