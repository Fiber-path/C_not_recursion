#pragma once
/*
带双亲指针的二叉树链式存储的头文件
*/

typedef char datatype;   /*二叉树值的类型*/

typedef struct node {   /*二叉树结点的类型*/
	datatype data;
	struct node* lchild, * rchild;
} bintnode;

typedef bintnode* bintree;
bintree root;   /*指向二叉树根结点的指针*/