/*
 ����Ļ�������
*/
#include<iostream>
using namespace std;

class Link{
public:
	int elem;
	Link *next;
public:
	Link* Initlink();   //����һ������
	Link* Insertelem(Link *p, int elem, int pos);//����Ԫ��
	Link* Delelem(Link *p, int pos);  //ɾ��Ԫ��
	int Selectelem(Link *p, int elem); //�������Ԫ��
	Link* Amendelem(Link* p, int pos, int newelem);  //�������Ԫ��
	Link* Iteration_reverse(Link* head);   //������ת��
	void display(Link *p);  
};
Link* Link::Initlink()
{
	Link *p = NULL;         //����ͷָ��
	Link *temp = new Link;  //������Ԫ�ڵ�
	temp->elem = 1;  
	temp->next = NULL;
	p = temp;              //ͷָ��ָ����Ԫ�ڵ�
	for (int i = 2; i < 5; i++){
		//�����ڵ㲢��ʼ��
		Link *a = new Link;
		a->elem = i;
		a->next = NULL;

		temp->next = a;  //��temp�ڵ����½�����a�ڵ㽨���߼���ϵ
		temp = temp->next; //ָ��tempÿ�ζ�ָ������������һ���ڵ㣬��ʵ���� a�ڵ㣬����дtemp=aҲ��
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
			cout << "�����λ����Ч" << endl;
			return p;
		}
	}
	//��������ڵ�c
	Link * c = new Link;
	c->elem = elem;
	c->next = temp->next;
	temp->next = c;
	return p;
}
Link* Link::Delelem(Link *p, int pos)
{
	Link *temp = p;
	//��������ɾ���Ľڵ����һ���ڵ�
	for (int i = 1; i < pos; i++){
		temp = temp->next;
		if (temp->next == NULL){
			cout << "û�иýڵ㣡" << endl;
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
	//�����������½ڵ�
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
		//һֱ����
		while (1)
		{
			mid->next = beg;
			if (end == NULL){
				break;
			}
			//��������ƶ�3��ָ��
			beg = mid;
			mid = end;
			end = end->next;
		}
		//����޸�headͷָ���ָ��
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
	cout << "��ʼ������Ϊ��" << endl;
	Link *p = new Link;
	p = p->Initlink();
	p->display(p);
	p->Insertelem(p, 20, 3);
	p->display(p);
	p->Delelem(p, 3);
	p->display(p);
	int pos = p->Selectelem(p, 3);
	cout << "Ԫ��3�������е�λ����" << pos << endl;
	p->Amendelem(p, 2, 8);
	p->display(p);
	p->Iteration_reverse(p);
	p->display(p);
	system("pause");
	return 0;
}