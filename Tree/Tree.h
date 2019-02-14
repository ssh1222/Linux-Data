#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node{
    int val;
    struct Node *left;
    struct Node *right;
}   Node;

typedef struct Result{
    Node *node;     //创建好的树的根结点
    int used;	    //创建树的过程中用掉的val个数
}   Result;

//创建二叉树
//BC#DE#G#F###
//""
Result CreateTree(char preorder[], int size){
    if(size <= 0){
	Result result;
	result.node = NULL;
	result.used = 0;
	return result;
    }

    if(preorder[0] = '#'){
	Result result;
	result.node = NULL;
	result.used = 1;
	return result;
    }

    //创建根结点
    Node *root = (Node*)malloc(sizeof(Node));
    assert(root);
    root->val = preorder[0];

    //创建左子树
    Result left = CreateTree(preorder + 1, size - 1);
    //创建右子树
    Result right = CreateTree(preorder + 1 + left.used, size - 1 - left.used);

    root->left = left.node;
    root->right = right.node;

    Result result;
    result.node = root;
    //1是根用掉的，left.used是左子树用掉的
    //right.used是右子树用掉的
    result.used = 1 + left.used + right.used;

    return result;
}

//利用地推方式写二叉树
//前序遍历二叉树
void PreorderTraversal(Node *root){
    //终止条件
    if(root == NULL){
	return;
    }

    printf("%d ", root->val);
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
}

//中序遍历二叉树
void MiddleOrderTraversal(Node *root){
    if(root == NULL){
	return;
    }

    MiddleOrderTraversal(root->left);
    printf("%d ", root->val);
    MiddleOrderTraversal(root->right);
}

//后序遍历二叉树
void EpilogueTraversal(Node *root){
    if(root == NULL){
	return;
    } 

    EpilogueTraversal(root->left);
    EpilogueTraversal(root->right);
    printf("%d ", root->val);
}

//结点个数地推的思路
int GetNodeCount(Node *root){
    if(root == NULL){
	return 0;
    }

    return GetNodeCount(root->left) + GetNodeCount(root->right) + 1;
}

//遍历的思路
int n = 0;
void GetNodeCount2(Node *root){
    if(root == NULL){
	return;
    }

    GetNodeCount2(root->left);
    n++;
    GetNodeCount2(root->right);
}

//叶子结点的个数递推的思路
int GetLeafSize(Node *root){
    if(root == NULL){
	return 0;
    }

    if(root->left == NULL && root->right == NULL){
	return 1;
    }

    return GetLeafSize(root->left) + GetLeafSize(root->right);
}

//遍历的思路
int leaf_n = 0;
void GetLeafSize2(Node *root){
    if(root == NULL){
	return;
    }

    if(root->left == NULL && root->right == NULL){
	leaf_n++;
    }

    GetLeafSize2(root->left);
    GetLeafSize2(root->right);
}

//求第K层结点的个数
int LevelK(Node *root, int k){
    if(root == NULL){
	return 0;
    }

    if(k == 1){
	return 1;
    }

    return LevelK(root->left, k - 1) + LevelK(root->right, k - 1);
}

//在树中查找val的值，树的val一定不重复
//查找次序，有序判断根，根不是，去左子树找，左子树没找到，继续右子树
//返回包含val的结点地址，没有找到返回NULL
Node *Find(Node *root, char val){
    if(root == NULL){
	return;
    }

    //先判断根结点
    if(root->val == val){
	return root;
    }

    //左子树找
    Node *ret = Find(root->left, val);
    if(ret != NULL){
	return ret;
    }
    
    //右子树找到了返回地址，没有找到返回NULL
    return Find(root->right, val);
}

//求二叉树的高度
int GetHeight(Node *root){
    if(root == NULL){
	return;
    }

    int left = GetHeight(root->left);
    int right = GetHeight(root->right);

    return (left > right ? left :right) + 1;
}

//搜索树转化为有序链表
Node *prev = NULL;
void Func(Node *node){
    node->left = prev;
    if(prev != NULL){
	prev->right = node;
    }

    prev = node;
}

void Inorder(Node *root){
    if(root == NULL){
	return;
    }

    Inorder(root->left);
    Func(root);
    Inorder(root->right);
}

