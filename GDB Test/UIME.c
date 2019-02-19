#include <stdio.h>


void set(int *pInt, int i);

int main(){
    int *a ;

    set(a,10);
    printf("%d \n ",a);


    return 0;
}

void set(int *pInt, int i) {
    *pInt = i;
}
