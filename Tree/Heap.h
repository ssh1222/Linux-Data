#pragma once
#include <stdlib.h>
#include <assert.h>

//向下调整
//array[size]表示数组的大小
//root表示要调整的节点的下标
//前提是[root]所在结点左右子树满足堆的性质
void AdjustDown(int array[], int size, int root)
{
    int min = 2 * root + 1;
    if(min >= size)
    {
	//越界
	return;
    }
    //确定那个是最小的孩子
    if(min +1 < size && array[min+1] < array[min])
    {
	min = min + 1;
    }
    if(array[root] <= array[min])
    {
	return;
    }
    //交换值
    int tmp = array[root];
    array[root] = array[min];
    array[min] = tmp;
    AdjustDown(array, size, min);
}

//建堆
void CteateHeap(int array[], int size)
{
    //从最后一个非叶子结点开始，调整到0结点
    //最后一个非叶子结点就是最后一个结点的双亲结点
    for(int i = (size - 1 - 1)/2; i >= 0; --i)
    {
	AdjustDown(array, size, i);
    }
}

typedef int HPDataType;

typedef struct Heap
{
    HPDataType* array;
    int size;
    int capacity;
}   Heap;

//初始化
void HeapCreateHeap(Heap* heap, int array[], int size)
{
    heap->size = size;
    heap->capacity = size*2;
    heap->array = (HPDataType*)malloc(sizeof(HPDataType) * size)
    for(int i = 0; i < size; ++i)
    {
	heap->array[i] = array[i];
    }
    
    //建堆
    CreateHeap(heap->array, heap->size);
}

//小堆
void AdjustUp(int array[], int size, int child)
{
    while(child != 0 )
    {
	int parent = (child - 1)/2;
	if(array[child] >= array[parent])
	{
	    return;
	}
	int tmp = array[parent];
	array[parent] = array[child];
	array[child] = tmp;
	child = parent;
    }
}

//增加
void HeapInsert(Heap* heap, int val)
{
    Heap->array[heap->size] = val;
    ++Heap->size;
    AdjustUp(heap->array, heap->size; heap->size - 1);
}

//删除（只能删除堆顶元素）
void HeapPop(Heap* heap)
{
    assert(heap->size > 0);
    heap->array[0] = heap->array[heap->size - 1];
    --heap->size;
    AdjustDown(heap->array, heap->size, 0);
}

//返回堆顶元素，返回最值
HPDataType HeapTop(Heap* heap)
{
    assert(heap->size > 0);
    return heap->array[0];
}
