/*
  顺序表实现栈操作
*/
#include<iostream>

using namespace std;
//压栈
int push(int *a, int top, int elem)
{
	a[++top] = elem;
	return top;
}
//出栈
int pop(int *a, int top)
{
	if (top == -1)
	{
		cout << "空栈" << endl;
		return -1;
	}
	cout << "弹栈元素:" << a[top] << endl;
	top--;
}
int main()
{
	int a[100];
	int top = -1;
	top = push(a, top, 1);
	top = push(a, top, 2);
	top = push(a, top, 3);
	top = push(a, top, 4);
	top = pop(a, top);
	top = pop(a, top);
	top = pop(a, top);
	top = pop(a, top);
	top = pop(a, top);
	system("pause");
	return 0;
}
