#include<stdio.h>

int main(){
    /*have to initialize the constant variables at declaration*/
    const int myAge = 20;
    /*uninitialize-> will store garbage value*/
    // const int my;
    
    printf("%c", myAge);
    return 0;
}