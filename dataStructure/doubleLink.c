/*Struct of a node in double linklist data Structure
*   prev pointer
*   Data
*   Next pointer   */

/*  -----------------------------------------------------
    |                 |                 |               |
    |        prev     |   Data          |    Next       |
    |                 |                 |               |
    -----------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
    struct Node *pre;
}Node;
Node *head, *tail;
int lengthList = 0;
/* Initialize a new node*/ 
Node *initNewNode(int x){
    Node *newNode = (Node *)malloc(sizeof(*newNode));
    newNode->data = x;
    newNode->next = NULL;
    newNode->pre = NULL;
    return newNode;
}

void addToHead(int x){
    Node *newNode = initNewNode(x);
    if (head == NULL){
        head = newNode;
        tail = newNode;
        lengthList ++;
    }
    else{
        head->pre = newNode;
        newNode->next = head;
        head = newNode;
        lengthList ++;
    }
}

void addToTail(int x){
    Node *newNode = initNewNode(x);
    if (head == NULL){
        head = newNode;
        tail = newNode;
        lengthList ++;
    }
    else{
        tail->next = newNode;
        newNode->pre = tail;
        tail = newNode;
        lengthList ++;
    }
}

void addToPosition(int x, int k){
    if(k < 1 || k > lengthList){
        printf("Location is Fail\n");
        return;
    }
    if (1 == k){
        addToHead(x);
        return;
    }
    if (k == lengthList){
        addToTail(x);
        return;
    }
    Node *ptr = head;
    Node *newNode = initNewNode(x);
    int count = 1;
    while(count != k){
        ptr = ptr->next;
        count ++;
    }
    newNode->pre = ptr->pre;
    newNode->next = ptr;
    ptr->pre->next = newNode;
    ptr->pre = newNode;
    lengthList ++;
}

void deleteAtHead(){
    if (head == NULL) return;
    Node *ptr = head->next;
    free(head);
    head = ptr;
    head->pre = NULL;
    lengthList --;
}

void deleteAtTail(){
    if (head == NULL) return;
    Node *ptr = tail->pre;
    free(tail);
    tail = ptr;
    tail->next = NULL;
    lengthList --;
}

void deleteAtPosition(int k){
    if(k < 1 || k > lengthList){
        printf("Location is Fail\n");
        return;
    }
    if (k == 1){
        deleteAtHead();
        return;
    }
    if (k == lengthList){
        deleteAtTail();
        return;
    }
    if (head == NULL){
        printf("Linklist is empty!\n");
        return;
    }
    Node *ptr = head;
    int count = 1;
    while(count != k){
        ptr = ptr->next;
        count ++;
    }
    ptr->pre->next = ptr->next;
    ptr->next->pre = ptr->pre;
    free(ptr);
    ptr = NULL;
    lengthList --;
}

//Duyệt danh sách linklist: head to tail
void print(){
    Node *ptr = head;
    while(ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

//Tail to head
void printReverse(){
    Node *ptr = tail;
    while(ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->pre;
    }
}

void search(int k){
    if (head == NULL){
        printf("Linklist is empty!\n");
        return;
    }
    Node *ptr = head;
    int count = 1;
    while (count != k){
        count++;
        ptr = ptr->next;
    }
    printf("Node %d have value: %d\n", k, ptr->data);
}

int main(){
    head = NULL;
    addToHead(2);
    addToTail(3);
    addToHead(5);
    addToHead(6);
    addToPosition(3, 3);
    search(3);
    print();
}