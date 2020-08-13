/*
��Ҫ����˳���Ļ�������
*/
#include<iostream>
#include<cstring>
using namespace std;

const int Size = 5;
class Table{
public:
	int *head;  //������һ������
	int length;  //��ǰ˳���ĳ���
	int size;    //˳������Ĵ洢����
public:
	Table initTable();  //��ʼ��˳���
	Table AddElement(Table t, int elem, int pos);  //����Ԫ��,elemΪԪ�أ�posΪ�����λ��
	Table DeleteElement(Table t, int pos);  //ɾ��ָ��λ�õ�Ԫ��
	int selectElem(Table t, int elem);   //˳������Ԫ��
	Table AmendElem(Table t, int elem, int newelem);  //˳����и���Ԫ��
	void display(Table t);//���˳����е�Ԫ��
};
Table Table::initTable()  //��ʼ��˳���
{
	Table t;
	t.head = new int(Size);
	if (!t.head){
		cout << "��ʼ��ʧ�ܣ�" << endl;
		exit(0);
	}
	t.length = 0;
	t.size = Size;
	return t;
}
Table Table::AddElement(Table t, int elem, int pos)  //���Ԫ��
{
	if (pos > t.length + 1 || pos < 1){
		cout << "����λ�ô���";
		return t;
	}

	if (t.length == t.size){
		int tt[Size] = { 0 };
		memcpy(tt, t.head, t.length*sizeof(int));
		t.head = new int(t.size + 1);
		memcpy(t.head, tt, t.length*sizeof(int));
		if (!t.head){
			cout << "�洢����ʧ�ܣ�" << endl;
			return t;
		}
		t.size += 1;
	}
	for (int i = t.length - 1; i >= pos - 1; i--){
		t.head[i + 1] = t.head[i];
	}
	t.head[pos - 1] = elem;
	t.length++;
	return t;
}
Table Table::DeleteElement(Table t, int pos)  //ɾ��Ԫ��
{
	if (pos > t.length || pos < 1){
		cout << "��ɾ��Ԫ�ص�λ������" << endl;
		return t;
	}
	for (int i = pos; i < t.length; i++){
		t.head[i - 1] = t.head[i];
	}
	t.length--;
	return t;
}
int Table::selectElem(Table t, int elem)  //����Ԫ��
{
	for (int i = 0; i < t.length; i++)
	{
		if (t.head[i] == elem)
		{
			return i + 1;
		}
	}
	return (-1);
}
Table Table::AmendElem(Table t, int elem, int newelem)//˳����и���Ԫ��
{
	int pos = selectElem(t, elem);
	t.head[pos - 1] = newelem;
	return t;
}
void display(Table t)
{
	for (int i = 0; i < t.length; i++){
		cout << t.head[i] << " ";
	}
	cout << endl;
}
int main()
{
	Table t;
	t = t.initTable();
	//��˳��������Ԫ��
	for (int i = 1; i <= Size; i++)
	{
		t.head[i - 1] = i;
		t.length++;
	}
	cout << "˳����д洢��Ԫ�طֱ��ǣ�" << endl;
	display(t);
	t = t.AddElement(t, 20, 3);
	display(t);
	t = t.DeleteElement(t, 3);
	display(t);
	int p = t.selectElem(t, 4);
	cout << "˳�����Ԫ��4��λ��Ϊ��" << p << endl;
	t = t.AmendElem(t, 3, 8);
	display(t);
	system("pause");
	return 0;
}