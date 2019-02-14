#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DLDataType;

typedef struct DListNode{
    DLDataType val;
    struct DListNode *next;
    struct DListNode *prev;
}   DListNode;

typedef struct DList{
    DListNode *head;
}   DList;

//内部接口
DListNode *DListBuyNode(DLDataType val){
    DListNdoe *node = (DListNode*)malloc(sizeof(DListNdoe));
    assert(node);
    node->val = val;
    node->next = node->prev = NULL;
    return node;
}

//初始化
void DListInit(DList *dlist){
    DListNode *head = DListBuyNode(0);
    head->next = head;
    head->prev = head;
    dlist->head = head;
}

//清除、不清楚头结点
void DListClear(DList *dlist){
    DListNode *cur = dlist->head->next;
    DListNode *next;
    for(; cur != dlist->head; cur = next){
	next = cur->next;
	free(cur);
    }
    dlist->head->next = dlist->head;
    dlist->head->prev = dlist->head;
}

//销毁
void DListDestroy(DList *dlist){
    DListCLear(dlist);
    free(dlist->head);
    dlist->head = NULL;
}

//增删改查
//头插
void DListPushFront(DList *dlsit, DLDataType val){
    DListInsert(dlist->head, val); 
}

//尾插
void DListPushBack(DList *dlist, DLDataType val){
    DListInsert(dlist->head->prev, val);
}

//在pos结点前面插入
void DListInsert(DListNode *pos, DLDataType val){
    DListNode *node = DListBuyNode(val);
    assert(node);
    node->next = pos;
    node->prve = pos->prev;
    pos->prev->next = node;
    pos->prev = node;
}

//头删
void DListPopFront(DList *dlist){
    assert(dlist->head->next != dlist->head);//链表不为空
    DListErase(dlist->head);
}

//尾删
void DListPopBack(DList *dlist){
    assert(dlist->head->next != dlist->head);//链表不为空
    DListErase(dlist->head->prev);
}

//删除pos结点，pos不是头结点
void DListErase(DListNode *pos){
    pos->prev->next = pos->next;
    pos->next->prev = pos ->prev;
    free(pos);
}

//查找
DListNode *DListFind(DList *dlist, DLDataType val){
    DListNode *cur = dlist->head->next;
    for(;cur != dlist->head; cur = cur->next){
	if(cur->val = val){
	    return cur;
	}
    }
    return NULL;
}

//打印
void DListPrint(DList *dlist){
    DListNode *cur dlist->head->next;
    for(;cur != dlist->head; cur = cur->next){
	printf("%d-->", cur->val);
    }
    printf("\n");
}
