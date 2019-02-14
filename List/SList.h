#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//单向+不循环+不带头
typedef int SLDataType

typedef struct SListNode
{
    SLDataType data;
    struct SListNode *next;
}   SListNode;

typedef struct SList
{
    struct SListNode *first;
}   SList;

//初始化
void SListInit(SList *list){
    assert(list);
    list->first = NULL;
}

//销毁
void SListDestroy(SList *list){
    assert(list);
    SListNode *next;
    for(SListNode *cur = list->first, cur != NULL, cur = next){
	next = cur->next;
	free(cur);
    }
    list->first = NULL;
}

//开辟结点
static SListNode* SListBuyNode(SLDataType data){
    SListNode *node = (SListNode*)malloc(sizeof(SListNode));
    assert(node);
    node->data = data;
    node->next = NULL;
    return node;
}

//增删改查
//头插
void SListPushFront(SList *list, SLDataType data){
    assert(list);
    SListNode *node = SlistBuyNode(data);
    node->next = list->first;
    list->first = node;
}

//尾插
void SListPushBack(SList *list, SLDataType data){
    assert(list);
    SListNode *node = SListBuyNode(data);
    if(list->first == NULL){
	list->first = node;
    }
    SListNode *cur = list->first;
    while(cur->next != NULL){
	cur = cur->next;
    }
    cur->next = node;
}

//在pos结点后面插入
void SListPopFront(SList *pos, SLDataType data){
    assert(pos);
    SListNode *node = SListBuyNode(data);
    node->next = pos->next;

}

//头删
void SListPopFront(SList *list){
    assert(list);
    assert(list->first);
    SListNode *cur = list->first;
    list->first = list->first->next;
    free(cur);
}

//尾删
void SListPopBack(SList *list){
    assert(list);
    assert(list->first);
    if(list->first->next == NULL){
	SListPopFront(list);
	return;
    }
    SListNode *cur = list->first;
    while(cur->next->next != NULL){
	cur = cur->next;
    }
    free(cur->next);
    cur->next = NULL;
}

//删除pos结点后的结点
//pos不是最后一个结点
void SListEraseAfter(SList *pos){
    assert(pos);
    if(pos->next == NULL){
	return;
    }
    SListNode *cur = pos->next;
    pos->next = cur->next;
    free(cur);
}

//删除第一个遇到的data结点
void SListRemove(SList *list, SLDataType data){
    assert(list);
    SListNdoe *cur = list->first;
    SListNode *prev = NULL;
    while(cur != NULL && cur->data != data){
	prev = cur;
	cur = cur->next;
    }
    if(cur == NULL){
	return;
    }
    if(prev == NULL){
	SListPopFront(list);
	return;
    }
    prev->next = cur->next;
    free(cur);
}

//查找
SListNode* SListFind(SList *list, SLDataType data){
    assert(list);
    for(SListNode *cur = list->first; cur != NULL; cur = cur ->next){
	if(cur->data == data){
	    return cur;
	}
    }
    return NULL;
}

//打印
void SListPrint(SList *list){
    assert(list);
    for(SListNode *cur = listfirst; cur != NULL; cur = cur->next){
	printf("%d-->", cur->data);
    }
    printf("NULL\n");
}
