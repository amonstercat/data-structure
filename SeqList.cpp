
#include <iostream>
using namespace std;
#define Max 100
typedef struct {
	int length;
	int *data;  //动态分配数组空间
}sqlist;


//创建顺序表
void createlist(sqlist &L)
{
	int n,e;
	cout << "请输入顺序表的长度"<<endl;
	cin >> n;
	L.length = n;
	
	cout << "开始为顺序表赋值"<<endl;
	for (int i = 0; i < n; i++)
	{
		cin >> e;
		L.data[i] = e;
	}
}

//定义顺序表的插入操作函数
void sqlistInsert(sqlist &L, int i, int element)
{
	if (i<1 || i>L.length + 1)
		cout << "出现越界" << endl;
	
	if (L.length >= Max)
		cout << "顺序表已满" << endl;
	
	for (int j = L.length; j >= i; j--)

	{
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = element;
	L.length++;
	
}

//定义顺序表的删除操作函数
void  sqlistDelete(sqlist *L ,int location)
{
	if (location<1 || location>L->length )
		cout << "出现越界" << endl;
	for (int i =location; i<L->length; i++)
	{
		L->data[i-1] = L->data[i];
		
	}
	L->length--;
}

void show (sqlist &L)
{
	int m;
	for ( m = 0; m < L.length; m++)
	{

		cout << L.data[m] <<" " ;
		cout << endl;
	}
}

int  sqlistPosition(int element, sqlist &L)
{
	int i0;
	for ( i0 = 0; i0 < L.length; i0++)
		if (L.data[i0] == element)
			break;
	return i0+1;
  }
/*
int main()
{
	int i,element,location;
	int pos;
	sqlist L;//创建一个 sqlist类型变量
	L.data = new int[Max];
	createlist(L);
	cout << "请输入插入元素的位置和数值" << endl;
    cin >> i >> element;
	sqlistInsert(L, i,element);
	cout << "插入后的顺序表为" << endl;
	show(L);
cout << "请输入删除的位置" << endl;
	cin >> location;
	sqlistDelete(&L, location);
	cout << "删除元素后的顺序表为" << endl;
	show(L);

	pos=sqlistPosition(50, L);
		cout << "第一个符合条件值为50的元素的位置为" << pos << endl;
	return 0;
}

*/
