#include "pch.h"
#include <iostream>
using namespace std;


//通过链表表示一个二叉树，创建结构体指针
typedef struct Node
{
	int data;
	Node *left;     //左孩子指针
	Node *right;   //右孩子指针
}Node;

void show1(Node *a);
void show2(Node *a);
//创建二叉树
void createtree()
{
	Node *A = new Node;
	Node *B = new Node;
	Node *C = new Node;
	Node *D = new Node;
	Node *E = new Node;
	Node *F = new Node;
	Node *G = new Node;
	Node *H = new Node;
	A->data =0;
	B->data = 1;
	C->data = 2;
	D->data = 3;
	E->data = 4;
	F->data = 5;
	G->data = 6;
	H->data = 7;
	A->left = B;
	A ->right = C;
	B->left = D;
	B->right = E;
	C->right = F;
	C->left = NULL;
	F->left = G;
	F->right = H;
	D->left = D->right = NULL;
	E->left = E->right = NULL;
	G->left = G->right = NULL;
	H->left = H->right = NULL;
	cout << "先序遍历的结果为" << endl;
	show1(A);
	cout << "后序遍历的结果为" << endl;
	show2(A);
}
//先序遍历
void  show1(Node *root)
{
	if (root ==NULL)
		return ;
	cout << (root->data)<<endl;
	show1(root->left);
	show1(root->right);

}
//后序遍历
void  show2(Node *root)
{
	if (root == NULL)
		return;
	show2(root->left);
	show2(root->right);
	cout << (root->data) << endl;
	

}
/*
int main()
{
	cout << "创建并遍历二叉树" << endl;
	createtree();
	return 0;
}
*/
