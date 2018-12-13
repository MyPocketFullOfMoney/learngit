#include<iostream>
using namespace std;
#include"List.h"
int main()
{
	int n = 0, m = 0;
	cout << "请输入约瑟夫环的总数n和出队数m：";
	cin >> n >> m;
	if (n < 0 && m <= 1) cout << "输入错误"<<endl;
	List L(n);
	L.PrintList();
	L.Search(m);
	
	
	system("pause");
	return 0;
}