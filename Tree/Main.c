#include "Tree.h"
#include <stdio.h>

int main(){
    char array[]={'B','C','#','D','E','#','G','#','F','#','#','#'};
    int size = sizeof(array) / sizeof(char);
    printf("%d\n", size);
    Result result = CreateTree(array, size);
    printf("%d, %p\n", result.used,result.node);
    return 0;
}
