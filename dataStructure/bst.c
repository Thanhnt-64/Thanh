#include <stdio.h>

typedef struct Node{
    int data;
    Node *left;
    Node *right;
}Node;



int main(){
    Node s1 = {1, NULL, NULL};
    printf("%d", s1.data);
    return 0;
}