#include <iostream>
#include<cstring>
using namespace std;
 typedef struct lnode {
  	char  data[10];       //定义结点的数据域
  struct	 lnode *next;    //定义结点的指针域,指向下一个结点
} lnode;        //定义一个结构体类型 lnode


 //尾插法动态创建链表，函数返回类型为结构体指针
 lnode* TailcreateList( int  length)
{
	lnode * headnode = new lnode; // 动态生成头结点，head类型为struct node类型
	lnode *prenode= headnode;
	cout << "开始尾插法创建链表" << endl;
	 for (int i = 0; i < length; i++)
	 {
		 cout << "请输入第"<<i+1<<"个学生的姓名"<< endl;
		 lnode *node = new lnode;//创建新结点
		 cin >> node->data;
		 prenode->next = node; //每插入一个新node,让之前的prednode指向新建的node
		  prenode = node;
		  node->next = NULL;
	 }
	 return headnode;
 }


 //头插法动态创建链表，函数返回类型为结构体指针
 lnode * HeadcreateList(int length)
 {
	 
	 lnode * headnode = new lnode;
	 lnode * prenode = headnode;
	 cout << "开始头插法创建链表" << endl;
	
	 for (int i = 0; i < length; i++)
	 {
		 cout << "请输入第" << i + 1 << "个学生的姓名" << endl;
		 lnode *node = new lnode;//创建新结点
		 cin >> node->data;
		 if (i == 0)
		 {
			 headnode->next = node;
			 prenode = node;
		 }
		 else
		 {
			 headnode->next = node;
			 node->next = prenode;
			 prenode = node;
		 }
	 }
	 return headnode;
 }

 //显示链表元素
 void show(lnode *head)
 {
	 lnode *first = head->next;
	 while (first != NULL)
	 {
		 cout << first->data << endl;
		 first = first->next;

	}
 }

 //获取元素位置
 void  getelement(lnode *head, int  position)
 {  
	 int   i = 1;
	 lnode *elementary = head->next;  //头节点不存数据
	 if (position < 1)
	 {
		 cout << "查找的位置不对" << endl;
	 }
	 if (position == 0)

		 cout << "查找位置为头节点" << endl;
	 
	 while (i <position&&elementary->next!=NULL)
	 {
		 elementary = elementary->next;//查找下一个结点
		 i++;
	 }
	 cout << "查找指定位置元素的值为" << elementary->data << endl;
	
 }

 //对链表进行插入元素操作
 bool insert(lnode *head,char data[10],int position )
 {
	
	 int i = 1;
	 lnode *pre = head->next;
	 lnode  *temp = new lnode;
	 if (position < 0)
		 cout << "插入的位置不对" << endl;
	 while (i < position-1)
	 {
		 pre = pre->next;
		 i++;
	 }
	 //在位置点i之前插入元素

	 //  temp->data = data;
	 strcpy_s(temp->data, data);
	 temp->next = pre->next;
	 pre->next = temp;
	 return true;
 }

 //对链表进行删除元素操作

 bool remove  (lnode *head, int rposition)
 {
	 int i = 1;
	 lnode * pre = head;
	 lnode *temp = new lnode;
	 while (i < rposition)
	 {
		 pre = pre->next;  //逐个结点的往后走
		 i++;
	 }
	 temp = pre->next;
	 pre->next = temp->next;
	 delete(temp);
	 return true;
  }
int main()
{
	int iposition,rposition;
	char data[10];
	lnode  *head =TailcreateList(4);
//	lnode  *head = HeadcreateList(5);
	show(head);
 //   getelement(head, 2);
	/*
	cout << "开始插入" << endl;
	cin >> data >> iposition;
	 insert(head, data,iposition);
	cout << "插入后的链表为" << endl;
	show(head);
	*/
	cout << "开始删除元素" << endl;
	cin >> rposition;
	remove(head, rposition);
	cout << "删除后的链表为" << endl;
	show(head);

	return 0;
}
