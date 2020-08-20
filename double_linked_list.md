```cpp
/*
  不含头结点的双向链表
*/
#include<iostream>
using namespace std;

typedef struct Link{
	Link* prior;
	int elem;
	Link* next;
}link;
//创建一个双向链表
link* InitLink()
{
	link* head = (link*)malloc(sizeof(link));
	head->prior = NULL;
	head->next = NULL;
	head->elem = 1;
	link* list = head;
	for (int i = 2; i < 5; i++)
	{
		link* temp = (link*)malloc(sizeof(link));
		temp->prior = NULL;
		temp->next = NULL;
		temp->elem = i;
		list->next = temp;
		temp->prior = list;
		list = list->next;
	}
	return head;
}
//给双向链表添加节点
link* insertlink(link* head,int data,int pos)
{
	link* temp = (link*)malloc(sizeof(link));
	temp->elem = data;
	temp->prior = NULL;
	temp->prior = NULL;
	if (pos == 1)  //插入到链表头
	{
		temp->next = head;
		head->prior = temp;
		head = temp;
	}
	else
	{
		link* body = head;
		for (int i = 1; i < pos-1; i++)
		{
			body = body->next;
		}
		if (body->next == NULL)
		{
			body->next = temp;
			temp->prior = body;
		}
		else
		{
			temp->next = body->next;
			body->next->prior = temp;
			body->next = temp;
			temp->prior = body;
		}
	}
	return head;
}
//删除双向链表指定位置的节点
link* deleteLink(link* head,int pos)
{
	link* temp = head;
	for (int i = 1; i < pos - 1; i++)
	{
		if (temp == NULL)
		{
			cout << "没有此节点" << endl;
		}
		temp = temp->next;
	}
	temp->next = temp->next->next;
	temp->next->next->prior = temp;
	return head;
}
//双向链表查找结点
int selectElem(link* head, int data)
{
	link* temp = head;
	int i = 1;
	while (temp)
	{
		if (temp->elem == data)
		{
			return i;
		}
		temp = temp->next;
		i++;
	}
}
//双向链表更给节点
link* updateElem(link* head,int pos,int newElem)
{
	link* temp = head;
	for (int i = 1; i < pos; i++)
	{
		temp = temp->next;
	}
	temp->elem = newElem;
	return head;
}
void display(link* head)
{
	link *p = head;
	while (p)
	{
		if (p->next != NULL)
		{
			cout << p->elem << " <-> ";
		}
		else
		{
			cout << p->elem;
		}
		p = p->next;
	}
	cout << endl;
}
int main()
{
	link* pp = (link*)malloc(sizeof(link));
	pp = InitLink();
	display(pp);
	pp = insertlink(pp, 10, 3);
	display(pp);
	pp = deleteLink(pp, 3);
	display(pp);
	int pos = selectElem(pp,4);
	cout << pos << endl;
	pp = updateElem(pp, 3, 10);
	display(pp);
	system("pause");
	return 0;
}
```