#include<stdio.h>
#include<stdlib.h>
int main(){
    int *ptr = (int*)malloc(10*sizeof(int));
    if (ptr == NULL){
        printf("Fall allocation\n");
        exit(0);
    }
    else{
        printf("Sucessfully\n");
        for (int i = 0; i < 10; i++){
            ptr[i] = i+1;
        }
        for (int i = 0; i < 10; i++){
            printf("%d\n", ptr[i]);
        }
        printf("Final 1\n\n");
        ptr = realloc(ptr, 5*sizeof(int));
    
        for (int i = 0; i < 10; i++){
            printf("%d\n", ptr[i]);
        }
        printf("Final 2\n\n");
        free(ptr);
    }
    printf("%d",ptr);
    if (ptr == NULL){
        
            printf("deallocation Ok\n");
    }
    return 0;
}