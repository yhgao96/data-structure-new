```cpp
/*
  树的链式存储结构
  一个简单的例子:
        1
      /   \
    2     3
   /
  4
*/
#include<iostream>
using namespace std;

typedef struct BiTNode{
	int elem;
	BiTNode *lchild;
	BiTNode *rchild;
}bitnode;
//创建一个二叉树
void CreateBiTree(bitnode* T)
{
	T->elem = 1;
	T->lchild = (bitnode*)malloc(sizeof(bitnode));
	T->rchild = (bitnode*)malloc(sizeof(bitnode));
	T->lchild->elem = 2;
	T->rchild->elem = 3;
	T->rchild->lchild = NULL;
	T->rchild->rchild = NULL;
	T->lchild->lchild = (bitnode*)malloc(sizeof(bitnode));
	T->lchild->rchild = NULL;
	T->lchild->lchild->elem = 4;
	T->lchild->lchild->lchild = NULL;
	T->lchild->lchild->rchild = NULL;
}
int main()
{
	bitnode *Tree = (bitnode*)malloc(sizeof(bitnode));
	CreateBiTree(Tree);
	cout << Tree->lchild->lchild->elem << endl;
	system("pause");
	return 0;
}
```