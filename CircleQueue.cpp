#include"pch.h"
#include<iostream>
using namespace std;
int  const maxsize = 20;
typedef struct  circlequeue {

	int  front;
	int   rear;
	int *base;        //存储内存分配的基地址，用它来访问队列
}circlequeue;


 void  initqueue(circlequeue *q)
{
	q->base = new int[maxsize];
	if(!q->base)    
	exit(0);

	q->rear = q->front = 0;

}
 //循环队列入队
 void insertqueue(circlequeue *q, int element)
 {
	 if ((q->rear + 1) % maxsize == q->front)
		 cout << "队列已经满了，无法再插入元素" << endl;

	 q->base[q->rear] = element;
	 q->rear = (q->rear + 1) % maxsize;      //取余就是为了防止假溢出，使得队列可以一直循环下去 

 }

 //循环队列出队
 int    deletequeue(circlequeue *q)
 {
	 int pop;
	 if (q->rear == q->front)
	 
		 cout << "队列已经为空" << endl;
	 
	 pop= q->base[q->front];
	 q->front = (q->front + 1) % maxsize;
	 return pop;
 }

int main()
{
	int popelement;
	circlequeue *queue=new circlequeue;
	initqueue(queue);
	insertqueue(queue, 98);
	insertqueue(queue, 97);
	insertqueue(queue, 96); 
	insertqueue(queue, 95);
	insertqueue(queue, 94);
	popelement = deletequeue(queue);
	popelement = deletequeue(queue);
	cout << "出队的元素为" <<popelement <<endl;
	return 0;
}
