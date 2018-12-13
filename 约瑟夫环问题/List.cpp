#include<iostream>
using namespace std;
#include"List.h"

List::List(int n)
{
	Node *r, *s;
	first = new Node;
	r = first;
	for (int i = 1; i <= n; i++)		//尾插法建立链表
	{
		s = new Node;
		s->data = i;
		r->next = s; r = s;
	}
	r->next = first->next;				//链表尾指针指向第一个数据结点
	head = first->next;					//第一个数据结点
	delete first;						//删除头指针
}
List::~List()
{
	Node *q = NULL;
	while (head != NULL)
	{
		q = head;
		head = head->next;
		delete q;
	}
}
void List::PrintList()
{
	Node *p = head;
	while (p != NULL)
	{
		cout << p->data<<" ";
		p = p->next;
		if (p == head)
		{
			cout << endl;
			return;
		}
	}
	
}
void List::Search(int keynum)
{
	Node *pre = head;Node *p = head->next; int count = 2;		//count=2是因为pre指向第一个数据结点，p指向第二个数据结点
	Node *q = NULL;
	while (p != pre)
	{
		if (count == keynum)
		{
			cout << p->data << " ";						//删除结点
			q = p;
			pre->next = q->next;
			delete q;
			p = pre->next;
			count = 1;									//1开始重新数数
		}
		else
		{
			pre = pre->next;
			p = p->next;
			count++;
		}
	}
	cout << endl << "输出最后一个结点：" ;
	cout << p->data << endl;
}