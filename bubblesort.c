#include <stdio.h>
#include <stdlib.h>

void Swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void Bubble(int *array, int size)
{
    int i = 0;
    int j = 0;
    for (i = 1; i < size; i++){
	int count = 0;
	for(j = 0; j < size - i; j++){
	    if(array[j] > array[j + 1]){
		Swap(array + j, array + j + 1);
		count++;
	    }
	}
	if(count == 0){
	    break;
	}
    }
    for(i = 0; i < size; i++){
	printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int i = 0;
    int array[10] = { 0 };
    int n = sizeof(array) / sizeof(array[0]);
    for(i = 0; i < n; i++){
	scanf("%d", &array[i]);
    }
    Bubble(array, n);
    return 0;
}
