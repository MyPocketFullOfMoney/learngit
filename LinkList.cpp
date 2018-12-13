#include<iostream>
using namespace std;
#include"LinkList.h"
//以下是类LinkList的成员函数定义
template<class DataType>
LinkList<DataType>::LinkList()
{
	first = new Node<DataTyoe>;		//生产头结点
	first->next = NULL;				//头结点的指针域置空
}
template<class DataType>
//尾插法
LinkList<DataType>::LinkList(DataType a[], int n)
{
	Node<DataType> *rear, *insert_s;	//	insert_s表示插入结点
	first = new Node<DataType>;		//生产头结点
	rear = first;					//尾指针初始化
	for (int i = 0; i < n; i++)
	{
		insert_s = new Node<DataType>;						//为每个数组元素建立一个结点，讲结点inset_s插入到终端结点之后
		insert_s->data = a[i];
		rear->next = insert_s; rear = insert_s;
	}
	rear->next = NULL;				//将终端结点的指针域置空
}
template<class DataType>
LinkList<DataType>::~LinkList()
{
	Node<DataType> *q = NULL;
	while (first != NULL)
	{
		q = first;					//暂存被释放的结点
		first = first->next;		//first指向被释放结点的下一个结点
		delete q;
	}
}
template<class DataType>
void LinkList<DataType>::Insert(int i, DataType x)
{
	Node<DataType> *p = first, *s = NULL;		//工作指针p指向头结点
	int count = 0;
	while (p != NULL&&count < i - 1)			//查找第i-1个结点
	{
		p = p->next;
		count++;
	}
	if (p == NULL) throw"位置";					//没有找到第i-1个结点
	else
	{
		s = new Node<DataType>; s->data = x;	//结点s的数据域为x
		s->next = p->next; p->next = s;			//讲结点s插入结点p之后
	}
}
template<class DataType>
DataType LinkList<DataType>::Delete(int i)
{
	Node<DataType> *p = first, *q = NULL;		//工作指针p初始化
	DataType x;
	int count = 0;
	while (p != NULL&&count < i - 1)					//查找第i-1个结点
	{
		p = p->next;
		count++;
	}
	if (p == NULL||p->next==NULL) throw"位置";		//结点p或结点p的后继结点不存在
	else
	{
		q = p->next; x = q->data;					//暂存被删结点
		p->next = q->next;						//摘链
		delete q;
		return x;
	}
}
template<class DataType>
int LinkList<DataType>::Locate(DataType x)
{
	Node<DataType>*p = first->next;			//工作指针p初始化
	int count = 1;
	while (p!=NULL)
	{
		if (p->data == x)return count;		//查找成功返回序号
		p = p->next;
		count++;
	}
	return 0;								//退出循环查找失败
}
template<class DataType>
void LinkList<DataType>::PrintList()
{
	Node<DataType> *p = first->next;		//工作指针p初始化
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;						//工作指针p后移
	}
	cout << endl;
}