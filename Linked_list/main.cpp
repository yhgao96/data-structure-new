/*
 链表的基本操作
*/
#include<iostream>
using namespace std;

class Link{
public:
	int elem;
	Link *next;
public:
	Link* Initlink();   //创建一个链表
	Link* Insertelem(Link *p, int elem, int pos);//插入元素
	Link* Delelem(Link *p, int pos);  //删除元素
	int Selectelem(Link *p, int elem); //链表查找元素
	Link* Amendelem(Link* p, int pos, int newelem);  //链表更新元素
	Link* Iteration_reverse(Link* head);   //迭代反转法
	void display(Link *p);  
};
Link* Link::Initlink()
{
	Link *p = NULL;         //创建头指针
	Link *temp = new Link;  //创建首元节点
	temp->elem = 1;  
	temp->next = NULL;
	p = temp;              //头指针指向首元节点
	for (int i = 2; i < 5; i++){
		//创建节点并初始化
		Link *a = new Link;
		a->elem = i;
		a->next = NULL;

		temp->next = a;  //将temp节点与新建立的a节点建立逻辑关系
		temp = temp->next; //指针temp每次都指向新链表的最后一个节点，其实就是 a节点，这里写temp=a也对
	}
	return p;
}
Link* Link::Insertelem(Link *p, int elem, int pos)
{
	Link *temp = p;
	for (int i = 1; i < pos; i++){
		temp = temp->next;
		if (temp == NULL)
		{
			cout << "插入的位置无效" << endl;
			return p;
		}
	}
	//创建插入节点c
	Link * c = new Link;
	c->elem = elem;
	c->next = temp->next;
	temp->next = c;
	return p;
}
Link* Link::Delelem(Link *p, int pos)
{
	Link *temp = p;
	//遍历到被删除的节点的上一个节点
	for (int i = 1; i < pos; i++){
		temp = temp->next;
		if (temp->next == NULL){
			cout << "没有该节点！" << endl;
			return p;
		}
	}
	Link * del = temp->next;
	temp->next = temp->next->next;
	free(del);
	return p;
}
int Link::Selectelem(Link* p, int elem)
{
	Link *t = p;
	int i = 1;
	while (t->next){
		t = t->next;
		if (t->elem == elem){
			return i+1;
		}
		i++;
	}
	return -1;
}
Link* Link::Amendelem(Link *p, int pos, int newelem)
{
	Link *temp = p;
	temp = temp->next;
	//遍历到待更新节点
	for (int i = 1; i < pos; i++){
		temp = temp->next;
	}
	temp->elem = newelem;
	return p;
}
Link* Link::Iteration_reverse(Link* head)
{
	if (head == NULL || head->next == NULL){
		return head;
	}
	else{
		Link * beg = NULL;
		Link * mid = head;
		Link * end = head->next;
		//一直遍历
		while (1)
		{
			mid->next = beg;
			if (end == NULL){
				break;
			}
			//整体向后移动3个指针
			beg = mid;
			mid = end;
			end = end->next;
		}
		//最后修改head头指针的指向
		head = mid;
		return head;
	}
}
void Link::display(Link *p)
{
	Link *temp = p;
	while (temp){
		cout << temp->elem<<" ";
		temp = temp->next;
	}
	cout << endl;
}
int main()
{
	cout << "初始化链表为：" << endl;
	Link *p = new Link;
	p = p->Initlink();
	p->display(p);
	p->Insertelem(p, 20, 3);
	p->display(p);
	p->Delelem(p, 3);
	p->display(p);
	int pos = p->Selectelem(p, 3);
	cout << "元素3在链表中的位置是" << pos << endl;
	p->Amendelem(p, 2, 8);
	p->display(p);
	p->Iteration_reverse(p);
	p->display(p);
	system("pause");
	return 0;
}