#include<stdio.h>
#include<stdbool.h>
#include "header.h"

#ifndef SPEED_INIT
#define SPEED_INIT 0
#endif

int spd = SPEED_INIT;
 int main(){
    int x =1;
    while(x<11){
        spd = SPEED_UP(spd);
        x++;
        printf("%d",spd);
    }
    printf("\n");
 }
