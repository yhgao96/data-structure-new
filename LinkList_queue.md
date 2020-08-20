```cpp
/*
    链表实现队列  
              ---2020.08.20
*/
#include<iostream>
using namespace std;

typedef struct QNode{
	int elem;
	QNode* next;
}qnode;
//带有头结点的链表
qnode* initNode()
{
	qnode* head = (qnode*)malloc(sizeof(qnode));
	head->next = NULL;
	return head;
}
//数据元素进入链式队列
qnode* enQueue(qnode* rear, int data)
{
	qnode* temp = (qnode*)malloc(sizeof(qnode));
	temp->elem = data;
	temp->next = NULL;
	//新节点与reae建立联系
	rear->next = temp;
	rear = temp;
	return rear;
}
//数据元素出链式队列
qnode* Dequeue(qnode* top, qnode* rear)
{
	if (top->next == NULL)
	{
		cout << "队列为空" << endl;
		return top;
	}
	qnode *p = top->next;
	cout << p->elem<<" ";
	top->next = p->next;
	if (rear == p)
	{
		rear = top;
	}
	free(p);
	return rear;
}
int main()
{
	qnode *queue, *top, *rear;
	//创建头结点
	queue = top = rear = initNode();
	//向链表中添加元素
	rear = enQueue(rear, 1);
	rear = enQueue(rear, 2);
	rear = enQueue(rear, 3);
	rear = enQueue(rear, 4);
	//出队
	rear = Dequeue(top, rear);
	rear = Dequeue(top, rear);
	rear = Dequeue(top, rear);
	rear = Dequeue(top, rear);
	rear = Dequeue(top, rear);
	system("pause");
	return 0;
}


```