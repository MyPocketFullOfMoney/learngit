#include<iostream>
using namespace std;
#include"List.h"
int main()
{
	int n = 0, m = 0;
	cout << "������Լɪ�򻷵�����n�ͳ�����m��";
	cin >> n >> m;
	if (n < 0 && m <= 1) cout << "�������"<<endl;
	List L(n);
	L.PrintList();
	L.Search(m);
	
	
	system("pause");
	return 0;
}