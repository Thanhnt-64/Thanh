#include <stdio.h>
struct linkList
{
    int data;
    struct linkList *next;
};

typedef struct  linkList *node;

node CreateNote(int value)
{
    node temp;
    temp = (node)malloc(sizeof(node));//tý thay thử bằng node
    temp->next = NULL;
    temp->data = value;
    return temp;
}

//Thêm node vào đầu danh sách liên kết
node AddHead(node head, int value)
{
    node temp = CreateNote(value);
    if(head == NULL)
        head = temp;
    else{
        temp->next = head;
        head = temp;
    }
    return head;
}
//Thêm node vào cuối danh sách liên kết đơn
node AddTail(node head, int value)
{
    node temp, p;
    temp = CreateNote(value);
    if(head == NULL)
        head = temp;
    else {
        p = head; // Khởi tạo p trỏ tới head
        while(p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
    return head;
}
node AddAt(node head, int value, int position)
{
    if(position == 0 || head == NULL)
    {
        head = AddHead(head, value);
    }
    else{
        int k = 1;
        node p = head;
        while(p!=NULL && k!= position)
        {
            p = p->next;
            ++k;
        }
        if (k != position)
        {
            head = AddTail(head, value);
        }
        else{
            node temp = CreateNote(value);
            temp->next = p->next;
            p->next = temp;
        }
    }
    return head;
}
node DelHead(node head)
{
    if(head == NULL)
        printf("Co cm j ma xoa");
    else{
        head = head->next;
    }
    return head;
}
node DelTail(node head)
{
    if(head == NULL || head->next == NULL)
        return DelHead(head);
    node p = head;
    while(p->next->next != NULL)
    {
        p = p->next;
    }
    p->next = NULL;
    return head;
}
node DelAt(node head, int position)
{
    if (position = 0 || head ==NULL || head->next == NULL){
        head = DelHead(head);
    }
    else{
        int k = 1;
        node p = head;
        while(p->next->next != NULL && k!= position){
            p = p->next;
            ++k;
        }
        if(k != position){
            head = DelTail(head);
        }
        else{
            p->next = p->next->next;
        }
    }
    return head;
}

int Get(node head, int index)
{
    int k = 0;
    node p= head;
    while(p->next != NULL && k!= index)
    {
        k++;
        p = p->next;
    }
    return p->data;
}

int Search(node head, int value)
{
    int position;
    for(node p = head; p != NULL; p = p->next)
    {
        if(p->data = value){
            return position;
        }
        ++position;
    }
    return -1;
}

void Traverser(node head){
    printf("\n");
    for(node p = head; p != NULL; p = p->next)
    {
        printf("%5d", p->data);
    }
}
node InitHead(){
    node head;
    head = NULL;
    return head;
}
int Length(node head){
    int length = 0;
    for(node p = head; p != NULL; p = p->next){
        ++length;
    }
    return length;
}
node Input(){
    node head = InitHead();
    int n, value;
    do{
        printf("\nNhap so luong phan tu n = ");
        scanf("%d", &n);
    }while(n <= 0);
 
    for(int i = 0; i < n; ++i){
        printf("\nNhap gia tri can them: ");
        scanf("%d", &value);
        head = AddTail(head, value);
    }
    return head;
}
int main(){
    printf("\n==Tao 1 danh sach lien ket==");
    node head = Input();
    Traverser(head);
 
    printf("\n==Thu them 1 phan tu vao linked list==");
    head = AddAt(head, 100, 2);
    Traverser(head);
 
    printf("\n==Thu xoa 1 phan tu khoi linked list==");
    head = DelAt(head, 1);
    Traverser(head);
 
    printf("\n==Thu tim kiem 1 phan tu trong linked list==");
    int index = Search(head, 9);
    printf("\nTim thay tai chi so %d", index);
 
    printf("\nBan co the thu them nhe!");
 
}