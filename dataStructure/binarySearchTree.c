#include <stdio.h>
#include <stdlib.h>
//Định nghĩa
typedef struct Node
{
    int data;
    node_t left;
    node_t right;
}*node_t;

//Hàm giải phóng dữ liệu
void Free( node_t root)
{
    if(root == NULL)
        return;
    Free(root->left);
    Free(root->right);
    free(root); // giải phóng vùng nhớ cho con trở hiện tại
}
//Hàm điều hướng cây;
int LeftOf(const int value, const node_t root)
{
    return value < root->data;
}
int RightOf(const int value, const node_t root)
{
    return value > root->data;
}
//Thêm phần tử vào BST
node_t Insert(node_t root, const int value)
{
    if(root == NULL)
    {
        node_t node = (node_t)malloc(sizeof(node));
        node->left = NULL;
        node->right = NULL;
        node->data = value;
        return node;
    }
    if(LeftOf(value, root))
    {
        root->left = Insert(root->left,value);
    }
    else if(RightOf(value, root))
    {
        root->right = Insert(root->right, value);
    }
    return root;
}
//Tìm kiếm trên BST
int Search(const node_t root, int value)
{
    if(root == NULL) return 0;
    if(root->data == value){
        return 1;
    }
    else if(LeftOf(value, root)){
        return Search(root->left, value);
    }
    else if(RightOf(value, root))
    {
        return Search(root->right, value);
    }
}