#include<iostream>
using namespace std;
#include"LinkList.cpp"		//������LinkList�ĳ�Ա��������
//����Ϊ������
void main()
{
	int r[5] = { 1,2,3,4,5 };
	LinkList<int>L(r, 5);
	cout << "ִ�в������ǰ����Ϊ��" ;
	L.PrintList();				//��ʾ��������Ԫ��
	cout << "�ڵ�2��λ�ò���ֵΪ3��Ԫ��:";
	try
	{
		L.Insert(2, 3);			//�ڵ�2��λ�ò���ֵΪ3��Ԫ��
		
	}
	catch (char *s)
	{
		cout << s << endl;
	}
	L.PrintList();
	cout << "ɾ����һ��Ԫ��:";
	try
	{
		L.Delete(1);			//ɾ����һ��Ԫ��
	}
	catch (char *s)
	{
		cout << s << endl;
	}
	L.PrintList();
	
	cout <<"ֵΪ3��Ԫ��λ��Ϊ��"<< L.Locate(3)<<endl;
	system("pause");
}
