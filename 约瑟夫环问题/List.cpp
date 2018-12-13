#include<iostream>
using namespace std;
#include"List.h"

List::List(int n)
{
	Node *r, *s;
	first = new Node;
	r = first;
	for (int i = 1; i <= n; i++)		//β�巨��������
	{
		s = new Node;
		s->data = i;
		r->next = s; r = s;
	}
	r->next = first->next;				//����βָ��ָ���һ�����ݽ��
	head = first->next;					//��һ�����ݽ��
	delete first;						//ɾ��ͷָ��
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
	Node *pre = head;Node *p = head->next; int count = 2;		//count=2����Ϊpreָ���һ�����ݽ�㣬pָ��ڶ������ݽ��
	Node *q = NULL;
	while (p != pre)
	{
		if (count == keynum)
		{
			cout << p->data << " ";						//ɾ�����
			q = p;
			pre->next = q->next;
			delete q;
			p = pre->next;
			count = 1;									//1��ʼ��������
		}
		else
		{
			pre = pre->next;
			p = p->next;
			count++;
		}
	}
	cout << endl << "������һ����㣺" ;
	cout << p->data << endl;
}