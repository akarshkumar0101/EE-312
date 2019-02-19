#include <stdio.h>

int divint(int x, int y);

int main() {
    int x = 5;
    int y = 2;

    int result = divint(x,y);
    printf("%d",result);

    x = 4;
    y = 0;
    result = divint(x,y);
    printf("%d",result);
    return 0;
}

int divint(int x, int y) {
    return x/y;
}