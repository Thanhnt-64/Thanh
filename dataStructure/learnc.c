#include <stdio.h>
#include <math.h>
// cài đặt stack với các phương thức: pop, push, top, IsEmpty, Isfull, Size
// Push: thêm 1 phần từ
// Pop: xóa phần tử ở đỉnh ngăn xếp
// Top: Lấy gtri phần tử đầu tiên
// Size: lấy số lượng phần tử đang có
// Isfull, IsEmpty: ktra
// Stack: last in-first out, chỉ có thể xóa phần tử ở đỉnh
// Cách 1: cài đặt bằng mảng:
int top = -1;
int IsFull(int capacity)
{
    if (top >= capacity -1)
        return 1;
    else
        return 0;
}
int IsEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
void Push(int stack[], int value, int capacity)
{
    if(IsFull(capacity))
    {
        printf("Stack is full !!");
    }
    else{
        ++top;
        stack[top] = value;
    }
}
void Pop()
{
    if (IsEmpty())
    {
        printf("Stack is Empty");
    }
    else
        --top;
}
int Top(int stack[]){
    return stack[top];
}
int Size(){
    return top+1;
}

int main()
{
    int capacity  = 5;
    int stack[capacity];
    Push(stack, 5, capacity);


    Push(stack, 3, capacity);
    printf("Size now is %d\n", Size());
    printf("Top now is %d", Top(stack));
    return 0;
}