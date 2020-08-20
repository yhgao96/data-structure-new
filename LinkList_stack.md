```cpp
/*
  链表实现栈操作
*/
#include<iostream>

using namespace std;
typedef struct LinkStack{
	int elem;
	LinkStack * next;
}linkstack;
//压栈
linkstack* push(linkstack* stack, int data)
{
	linkstack* temp = (linkstack*)malloc(sizeof(linkstack));
	temp->elem = data;
	temp->next = stack;
	stack = temp;
	return stack;
}
//弹栈
linkstack* pop(linkstack* stack)
{
	if (stack != NULL)
	{
		linkstack* pp = stack;
		stack = stack->next;
		cout << "出栈元素为： " << pp->elem << endl;
		if (stack != NULL)
		{
			cout << "新栈顶元素： " << stack->elem << endl;
		}
		else
		{
			cout << "栈已空" << endl;
		}
		free(pp);
	}
	else
	{
		cout << "栈中没有元素" << endl;
		return stack;
	}
	return stack;
}
int main()
{
	linkstack *stack = NULL;
	stack = push(stack, 10);
	stack = push(stack, 20);
	stack = push(stack, 30);
	stack = push(stack, 40);
	stack = pop(stack);
	stack = pop(stack);
	stack = pop(stack);
	stack = pop(stack);
	system("pause");
	return 0;
}

```