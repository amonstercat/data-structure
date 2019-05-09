#include "pch.h"
#include <iostream>
using namespace std;
int const max = 10;
//因为是顺序栈，所以定义一个int型变量来记录栈顶位置，如果是链表栈则要用指针来表示栈顶位置
typedef struct stack{
	int   data[max];
   int top;  //栈顶指针
   int base;  //栈底指针

}stack;

//栈的初始化，栈顶指针指向-1处
void initstack(stack &sqstack)  //传入一个stack结构体的引用
{
	sqstack.top = -1;
}

void stackempty(stack &sqstack)

{
	if (sqstack.top == -1)
		cout << "栈空" << endl;
	else
		cout << "栈非空" << endl;

}

void  pushstack(stack &sqstack,int element)
{
	if (sqstack.top == max-1)
		cout << "栈已经满了" << endl;
	
	sqstack.top++;  //先让栈顶指针上移
	sqstack.data[sqstack.top] = element;

}
void popstack(stack *sqstack)
{

	int popelement;
	sqstack->top--;
	popelement = sqstack->data[sqstack->top];
	
}
int gettop(stack *sqstack)
{
	int element = 0;

	element = sqstack->data[sqstack->top];      //top永远指向栈顶，因此直接用sqstack指针访问结构体里的top元素
	return element;
}
/*
int main()
{
	int topelement;
	stack sqstack;
	initstack(sqstack);
	stackempty(sqstack);
	pushstack(sqstack, 97);
	pushstack(sqstack, 96);
	pushstack(sqstack, 95);
	stackempty(sqstack);
	topelement = gettop(&sqstack);
	cout << "栈顶元素值为" << topelement << endl;
	popstack(&sqstack);
	topelement = gettop(&sqstack);
	cout << "栈顶元素值为" << topelement << endl;
	return 0;
  
}
*/
