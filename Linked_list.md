```cpp
/*
链表的相关操作
---2020.08.19
*/
#include<iostream>
using namespace std;
typedef struct Link{
	int elem;
	struct Link * next;
}link;
link * initLink()    //初始化链表
{
	link* p = (link*)malloc(sizeof(link));
	link *temp = p;
	//生成链表
	for (int i = 1; i < 5; i++)
	{
		link *a = (link*)malloc(sizeof(link));
		a->elem = i;
		a->next = NULL;
		temp->next = a;
		temp = temp->next;
	}
	return p;
}
//链表中插入元素
link* insertLink(link *p, int elem, int pos)
{
	link *temp = p;
	for (int i = 1; i < pos; i++)
	{
		temp = temp->next;
		if (temp == NULL){
			cout << "插入位置无效" << endl;
			return p;
		}
	}
	link *c = (link*)malloc(sizeof(link));
	c->elem = elem;
	c->next = temp->next;
	temp->next = c;
	return p;
}
//删除指定位置上的节点
link * deleteLink(link* p, int pos)
{
	link* temp = p;
	for (int i = 1; i < pos; i++)
	{
		temp = temp->next;
		if (temp->next == NULL)
		{
			cout << "没有该节点" << endl;
			return p;
		}
	}
	link* del = temp->next;
	temp->next = temp->next->next;
	free(del);
	return p;
}
//查找链表中的元素
int selectElem(link *p, int num)
{
	link* temp = p;
	int i = 1;
	while (temp->next)
	{
		temp = temp->next;
		if (temp->elem == num)
			return i;
		i++;
	}
	return -1;
}
//链表更新元素
link* updateElem(link* p, int pos, int newelem)
{
	link* temp = p;
	for (int i = 1; i <= pos; i++)
	{
		temp = temp->next;
		if (temp == NULL)
		{
			cout << "不存在该节点" << endl;
		}
	}
	temp->elem = newelem;
	return p;
}
//反转带头结点的链表
link* reverseLink(link* head)
{
	link * p = head->next;
	link * aa = NULL;
	link * newhead = (link*)malloc(sizeof(link));
	while (p!= NULL)
	{
		link* temp = p->next;
		p->next = aa;
		aa = p;
		p = temp;
	}
	newhead->next = aa;
	return newhead;
}
/*
//反转不带头结点的链表
link* reverseLink(link* head)
{
	link * p = head;
	link * newhead = NULL;
	while (p!= NULL)
	{
		link* temp = p->next;
		p->next = newhead;
		newhead = p;
		p = temp;
	}
	return newhead;
}
*/
//打印链表
void display(Link *p)
{
	link* temp = p;
	while (temp->next)
	{
		temp = temp->next;
		cout << temp->elem << " ";
	}
	cout << endl;
}
int main()
{
	link* pp = (link*)malloc(sizeof(link));
	pp = initLink();
	display(pp);
	pp = insertLink(pp, 10, 3);
	display(pp);
	pp = deleteLink(pp, 3);
	display(pp);
	int pos = selectElem(pp, 4);
	cout << pos << endl;
	pp = updateElem(pp, 3, 10);
	display(pp);
	pp = reverseLink(pp);
	display(pp);
	system("pause");
	return 0;
}
```