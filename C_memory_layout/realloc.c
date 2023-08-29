#include <stdio.h>
#include <stdlib.h>
int main(){
    int *ptr = (int *)malloc(5*sizeof(int));
    printf("%d\n", &ptr);
    ptr = (int *)realloc(ptr,100*sizeof(int));
    printf("%d\n", &ptr);
    free(ptr);
    return 0;
}