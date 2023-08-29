#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node*next;
    struct Node*prev;
};


typedef struct Node *node;
node head, tail;
node GetNewNode(int x){
    node newNode = (node)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
//add new node to head
void addToHead(int value){
    node temp = GetNewNode(value);
    if(head == NULL){
         head = temp;
         tail = temp;
         return;
    }
    else{
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
//add to tail
void addToTail(int value)
{
    node temp = GetNewNode(value);
    if(tail == NULL)
    {
        tail = temp;
        head = temp;
    }
    else{
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
}
//add to anywhere
void addTo(int value, int position){
    node temp= GetNewNode(value);
    node p;
    int k = 0;
    for(p = head->next; p != NULL; p = p->next)
    {
        if(k == position-1)
        {
           temp->next = p->next->next;
           p->next = temp;
           p->next->prev = temp;
           temp->prev = p; 
        }
        k++;
    }
}
//Delete at Head
void DelAtHead(){
    if(head == NULL)
        printf("Co cc j ma xoa");
    else{
        head = head->next;
        head->prev = NULL;
    }
}
void DelAtTail(){
    if(head == NULL)
        printf("ccc j ma xoa");
    else{
        tail = tail->prev;
        tail->next = NULL;
    }
}
void Print() {
    node temp = head;
    printf("\nForward: ");
    while(temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
 
//Prints all elements in linked list in reverse traversal order.
void ReversePrint() {
    node temp = tail;
    if(temp == NULL) return; // empty list, exit
    // Traversing backward using prev pointer
    printf("\nReverse: ");
    while(temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
int main(){
    head = NULL;
    tail = NULL;
    addToHead(3);
    addTo(5,0);
    addTo(6,1);
    Print();
    return 0;
}