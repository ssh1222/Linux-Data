#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int QDataType;

//用单链表实现队列
typedef struct QNode{
    QDataType val;
    struct QNode *next;
}   QNode;

typedef struct Queue{
    Queue *front;  //指向链表的第一个结点
    Queue *rear;   //指向链表中最后一个结点
    int size;      //队列中元素的个数
}   Queue;

//初始化
void QueueInit(Queue *queue){
    queue->front = queue->rear = NULL;
    queue->size = 0;
}

//销毁
void QueueDestory(Queue *queue){
    QNode *next;
    for(QNOde *cur = queue->front; cur != NULL; cur = next){
	next = cur->next;
	free(cur);
    }
    queue->front = queue->rear = NULL;
    queue->size = 0;
}

//增删改查
//只能在队尾插入
void QueuePush(Queue *queue, QDataType val){
    //申请新节点
    QNode *node = (QNode*)malloc(sizeof(QNode));
    assert(node);
    node->next = NULL;
    node->val = val;
    if(queue->rear == NULL){
	queue->front = queue->rear = node;
    }else{
	queue->rear->next = node;
	queue->rear = node;
    }
    queue->size++;
}

//只能从队首删除
void QueuePop(Queue *queue){
    assert(queue->size > 0);
    QNode *cur = queue->front;
    queue->front = cur->next;
    free(cur);
    if(queue->front == NULL){
	queue->rear = NULL;
    }
    queue->size--;
}

//返回队首元素
QDataType QueueFront(const Queue *queue){
    assert(queue->size > 0);
    return queue->front->val;
}

//判断队列是否为空
int QueueEmpty(const Queue *queue){
    return queue->size > 0 ? 0 : 1;
}

//队列的大小
int QueueSize(const Queue *queue){
    return queue->size;
}
