#include "pch.h"
#include <iostream>
using namespace std;

//定义顺序存储的队列
typedef struct {
	int data[50];
	int rear;
	int front;
}queue;
//定义链式存储的队列
typedef  struct node
{
	int  data;
	node* next;
}node;
typedef struct linkqueue
{
	//声明了front指针指向队首，rear指针指向队尾，两个指针分别指向某一地址
	node *front;     
	node *rear;
}linkqueue;

//初始化队列
void initqueue(queue *queue)
{
	queue->front = 0;
	queue->rear = queue->front;
}
void initlinkqueue(linkqueue  *linkqueue)
{
	//动态创建一个头结点，使得队列的头节点，尾结点都指向它,且均指向null。
	node * newnode = new node;
	linkqueue->front = newnode;
	linkqueue->rear = linkqueue->front;
	linkqueue->front->next = NULL;
	cout << "链表队列创建成功" << endl;
}

void emptyqueue(linkqueue *linkqueue)
{
	if (linkqueue->front == linkqueue->rear)
	{
		cout << "队列为空队列" << endl;
	}
	else
	{
		cout << "队列不为空" << endl;
	}

}

//入队操作
void insertqueue(queue *queue)
{
	int  num, i ;
		cout << "输入你想入队的元素的个数" << endl;
		cin >> num;
		if (num > 50)
			cout << "队列空间不够" << endl;
		initqueue(queue);
		for (i = 0; i < num; i++)
		{
			int element=0;
			cout << " 输入第" << i + 1 << "个元素" << endl;
			cin >> element;
			queue->rear++;
			queue->data[i] = element;
		}
}

void inslinkqueue(linkqueue *linkqueue,int element)
{
	node *temp = new node;
	temp->data = element;
	temp->next = NULL;
	linkqueue->rear->next = temp;
	linkqueue->rear = temp;
	

}
//链式队列出队操作
bool dellinkqueue(linkqueue  *linkqueue )
{
	
	if (linkqueue->front == linkqueue->rear)    //即front 指针和rear指针指向同一个地址，即为空队列
		cout << "此队列为空队列" << endl;
	node *temp =linkqueue->front->next;
	
	 linkqueue->front->next = temp->next;      //出错的位置
	 free(temp);
	 temp = NULL;
	 return true;
}

void getfront(queue *queue,int frontelement)
{
	frontelement = queue->data[queue->front];
	cout << "队列头元素为" << frontelement << endl;

}
void show(linkqueue *linkqueue)
{
	node *travel = linkqueue->front;
	while (travel !=linkqueue->rear)
	{
		
		travel = travel->next;
		int a = travel->data;
		cout << a << endl;
	}
}

/*
int main()
{
	int frontelement=0;
	queue queue;
	insertqueue(&queue);
	getfront(&queue, frontelement);
	return 0;
}
*/


/*
int main()
{  
	int element;
	linkqueue linkqueue;
	initlinkqueue(&linkqueue);
	emptyqueue(&linkqueue);
	inslinkqueue(&linkqueue,225);
	inslinkqueue(&linkqueue, 226);
	inslinkqueue(&linkqueue, 227);
	inslinkqueue(&linkqueue, 228);
	inslinkqueue(&linkqueue, 229);
	inslinkqueue(&linkqueue, 230);
	cout << "插入成功" << endl;
	cout << "插入元素后的队列为" << endl;
	show(&linkqueue);
	dellinkqueue(&linkqueue);
	//cout << "被删除的元素为" << endl;
	cout << "删除元素后的队列为" << endl;
	show(&linkqueue);
	return 0;
}

*/
