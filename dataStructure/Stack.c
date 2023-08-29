#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Stack
{
    int top;
    unsigned capacity;
    int *array;
}Stack;

Stack* createStack(unsigned capacity)
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int IsFull(Stack *stack)
{
    return (stack->top == stack->capacity -1);
}
int IsEmpty(Stack *stack)
{
    return (stack->top ==-1);
}
void Push(Stack *stack, int newValue)
{
    if (IsFull(stack)) printf("Đầy rồi e trai");
    else
    {
        ++stack->top;
        stack->array[stack->top] = newValue;
    }
}
int Pop(Stack *stack)
{
    if (IsEmpty(stack)) printf("Còn j đâu mà xóa");
    
        return (stack->array[stack->top --]);  
}
int Peek(Stack *stack)
{
    if(IsEmpty(stack)) printf("Còn cái nịt");
   
        return stack->array[stack->top];
}
