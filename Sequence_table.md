```cpp
/*
主要包含顺序表的基本操作
*/
#include<iostream>
#include<cstring>
using namespace std;

const int Size = 5;
class Table{
public:
	int *head;  //定义了一个数组
	int length;  //当前顺序表的长度
	int size;    //顺序表分配的存储容量
public:
	Table initTable();  //初始化顺序表
	Table AddElement(Table t, int elem, int pos);  //插入元素,elem为元素，pos为插入的位置
	Table DeleteElement(Table t, int pos);  //删除指定位置的元素
	int selectElem(Table t, int elem);   //顺序表查找元素
	Table AmendElem(Table t, int elem, int newelem);  //顺序表中更改元素
	void display(Table t);//输出顺序表中的元素
};
Table Table::initTable()  //初始化顺序表
{
	Table t;
	t.head = new int(Size);
	if (!t.head){
		cout << "初始化失败！" << endl;
		exit(0);
	}
	t.length = 0;
	t.size = Size;
	return t;
}
Table Table::AddElement(Table t, int elem, int pos)  //添加元素
{
	if (pos > t.length + 1 || pos < 1){
		cout << "插入位置错误！";
		return t;
	}

	if (t.length == t.size){
		int tt[Size] = { 0 };
		memcpy(tt, t.head, t.length*sizeof(int));
		t.head = new int(t.size + 1);
		memcpy(t.head, tt, t.length*sizeof(int));
		if (!t.head){
			cout << "存储分配失败！" << endl;
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
Table Table::DeleteElement(Table t, int pos)  //删除元素
{
	if (pos > t.length || pos < 1){
		cout << "被删除元素的位置有误！" << endl;
		return t;
	}
	for (int i = pos; i < t.length; i++){
		t.head[i - 1] = t.head[i];
	}
	t.length--;
	return t;
}
int Table::selectElem(Table t, int elem)  //查找元素
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
Table Table::AmendElem(Table t, int elem, int newelem)//顺序表中更改元素
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
	//向顺序表中添加元素
	for (int i = 1; i <= Size; i++)
	{
		t.head[i - 1] = i;
		t.length++;
	}
	cout << "顺序表中存储的元素分别是：" << endl;
	display(t);
	t = t.AddElement(t, 20, 3);
	display(t);
	t = t.DeleteElement(t, 3);
	display(t);
	int p = t.selectElem(t, 4);
	cout << "顺序表中元素4的位置为：" << p << endl;
	t = t.AmendElem(t, 3, 8);
	display(t);
	system("pause");
	return 0;
}
```