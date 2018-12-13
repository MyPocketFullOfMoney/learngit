#include<iostream>
using namespace std;
#include"LinkList.cpp"		//引入类LinkList的成员函数定义
//以下为主函数
void main()
{
	int r[5] = { 1,2,3,4,5 };
	LinkList<int>L(r, 5);
	cout << "执行插入操作前数据为：" ;
	L.PrintList();				//显示链中所有元素
	cout << "在第2个位置插入值为3的元素:";
	try
	{
		L.Insert(2, 3);			//在第2个位置插入值为3的元素
		
	}
	catch (char *s)
	{
		cout << s << endl;
	}
	L.PrintList();
	cout << "删除第一个元素:";
	try
	{
		L.Delete(1);			//删除第一个元素
	}
	catch (char *s)
	{
		cout << s << endl;
	}
	L.PrintList();
	
	cout <<"值为3的元素位置为："<< L.Locate(3)<<endl;
	system("pause");
}
