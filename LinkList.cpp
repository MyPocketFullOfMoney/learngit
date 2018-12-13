#include<iostream>
using namespace std;
#include"LinkList.h"
//��������LinkList�ĳ�Ա��������
template<class DataType>
LinkList<DataType>::LinkList()
{
	first = new Node<DataTyoe>;		//����ͷ���
	first->next = NULL;				//ͷ����ָ�����ÿ�
}
template<class DataType>
//β�巨
LinkList<DataType>::LinkList(DataType a[], int n)
{
	Node<DataType> *rear, *insert_s;	//	insert_s��ʾ������
	first = new Node<DataType>;		//����ͷ���
	rear = first;					//βָ���ʼ��
	for (int i = 0; i < n; i++)
	{
		insert_s = new Node<DataType>;						//Ϊÿ������Ԫ�ؽ���һ����㣬�����inset_s���뵽�ն˽��֮��
		insert_s->data = a[i];
		rear->next = insert_s; rear = insert_s;
	}
	rear->next = NULL;				//���ն˽���ָ�����ÿ�
}
template<class DataType>
LinkList<DataType>::~LinkList()
{
	Node<DataType> *q = NULL;
	while (first != NULL)
	{
		q = first;					//�ݴ汻�ͷŵĽ��
		first = first->next;		//firstָ���ͷŽ�����һ�����
		delete q;
	}
}
template<class DataType>
void LinkList<DataType>::Insert(int i, DataType x)
{
	Node<DataType> *p = first, *s = NULL;		//����ָ��pָ��ͷ���
	int count = 0;
	while (p != NULL&&count < i - 1)			//���ҵ�i-1�����
	{
		p = p->next;
		count++;
	}
	if (p == NULL) throw"λ��";					//û���ҵ���i-1�����
	else
	{
		s = new Node<DataType>; s->data = x;	//���s��������Ϊx
		s->next = p->next; p->next = s;			//�����s������p֮��
	}
}
template<class DataType>
DataType LinkList<DataType>::Delete(int i)
{
	Node<DataType> *p = first, *q = NULL;		//����ָ��p��ʼ��
	DataType x;
	int count = 0;
	while (p != NULL&&count < i - 1)					//���ҵ�i-1�����
	{
		p = p->next;
		count++;
	}
	if (p == NULL||p->next==NULL) throw"λ��";		//���p����p�ĺ�̽�㲻����
	else
	{
		q = p->next; x = q->data;					//�ݴ汻ɾ���
		p->next = q->next;						//ժ��
		delete q;
		return x;
	}
}
template<class DataType>
int LinkList<DataType>::Locate(DataType x)
{
	Node<DataType>*p = first->next;			//����ָ��p��ʼ��
	int count = 1;
	while (p!=NULL)
	{
		if (p->data == x)return count;		//���ҳɹ��������
		p = p->next;
		count++;
	}
	return 0;								//�˳�ѭ������ʧ��
}
template<class DataType>
void LinkList<DataType>::PrintList()
{
	Node<DataType> *p = first->next;		//����ָ��p��ʼ��
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;						//����ָ��p����
	}
	cout << endl;
}