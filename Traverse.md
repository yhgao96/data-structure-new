```cpp
/*
树的链式存储结构
一个简单的例子:
	        1
                      /   \
	     2     3
	    / \   / \
	   4   5 6   7
*/
#include<iostream>
using namespace std;

typedef struct BiTNode{
	int elem;
	BiTNode *lchild;
	BiTNode *rchild;
}bitnode,*bitree;
//创建一个二叉树
void CreateBiTree(bitnode* T)
{
	T->elem = 1;
	T->lchild = (bitnode*)malloc(sizeof(bitnode));
	T->rchild = (bitnode*)malloc(sizeof(bitnode));
	T->lchild->elem = 2;
	T->lchild->lchild = (bitnode*)malloc(sizeof(bitnode));
	T->lchild->rchild = (bitnode*)malloc(sizeof(bitnode));
	T->rchild->elem = 3;
	T->rchild->lchild = (bitnode*)malloc(sizeof(bitnode));
	T->rchild->rchild = (bitnode*)malloc(sizeof(bitnode));
	T->lchild->lchild->elem = 4;
	T->lchild->lchild->lchild = NULL;
	T->lchild->lchild->rchild = NULL;
	T->lchild->rchild->elem = 5;
	T->lchild->rchild->lchild = NULL;
	T->lchild->rchild->rchild = NULL;
	T->rchild->lchild->elem = 6;
	T->rchild->lchild->lchild = NULL;
	T->rchild->lchild->rchild = NULL;
	T->rchild->rchild->elem = 7;
	T->rchild->rchild->lchild = NULL;
	T->rchild->rchild->rchild = NULL;
}
//输出结点的值
void display(bitnode *pp)
{
	cout << pp->elem << " ";
}
//先序遍历
void PreOrderTraverse(bitnode* T)
{
	if (T!=NULL)
	{
		//display(T);  //前序遍历
		PreOrderTraverse(T->lchild);
		//display(T);   //中序遍历
		PreOrderTraverse(T->rchild);
		display(T);    //后序遍历
	}
}
int main()
{
	bitnode *T = (bitnode*)malloc(sizeof(bitnode));
	CreateBiTree(T);
	cout << "先序遍历： " << endl;
	PreOrderTraverse(T);
	system("pause");
	return 0;
}
```