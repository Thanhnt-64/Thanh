#include <stdlib.h>

typedef struct Node{
    int data;
    Node left;
    Node right;
    int height;
}*Node;
int getHeight(Node root){
    if(root == NULL){
        return 0;
    }
    return 1+ max(getHeight(root->left,root->right));
}
//Các kỹ thuật quay cây AVL
//Kỹ thuật quay phải-áp dụng khi cây bị lệch trái
Node rightRotate(Node root){
    Node x = root->left;
    //Bất đầu quay phải
    root->left = x->right;
    x->right = root;

    //Thiết lập chiều cao
    root->height = 1 + max(getHeight(root->left),getHeight(root->right));
    x->height = 1 + max(getHeight(x->left),getHeight(x->right));
    //Return x trả về root mới
    return x;
}
//Kỹ thuật quay trái-áp dụng khi cây bị lệch phải