#pragma once
#include <assert.h>

#define MAX 100

typedef int SDataType;

//利用静态顺序表实现栈
typedef struct Stack{
    SDataType val;
    SDataType array[MAX];
    int top;
}   Stack;

//初始化
void  StackInit(Stack *stack){
    stack->top = 0;
}

//销毁
void StackDestroy(Stack *stack){
    stack->top = 0;
}

//增删改查
//只能从栈顶插入
void StackPush(Stack *stack, SDataType val){
    assert(stack);
    assert(stack->top < MAX);
    stack->array[stack->top] = val;
    ++stack->top;
}

//只能从栈顶删除
void StackPop(Stack *stack){
    assert(stack);
    assert(stack->top > 0);
    --stack->top;
}

//返回栈顶元素
SDataType StackTop(Stack *stack){
    assert(stack);
    assert(stack->top > 1);
    return stack->array[stack->top - 1];
}

//判断是否为空
int StackEmpty(Stack *stack){
    return stack->top > 0 ? 0 : 1;
}

//返回栈内元素个数
void StackSize(Stack *stack){
    return stack->top;
}
