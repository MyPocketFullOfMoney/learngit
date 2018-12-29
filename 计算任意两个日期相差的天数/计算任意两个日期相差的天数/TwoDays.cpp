#include<iostream>
using namespace std;
struct date
{
	int y;//年
	int m;//月
	int d;//日
};
//判断是否闰年
bool isleap(int y)
{
	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
		return 1;
	else
		return 0;
}
//月份天数
int Daysofmonth(int y, int m)
{
	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (m != 2)
		return month[m - 1];
	else
		return month[1] + isleap(y);
}
//计算总共的天数
int DaysSum(date d)
{
	int days = d.d;
	//计算年的总天数
	for (int y = 1; y < d.y; y++)
		days += 365 + isleap(y);
	//计算月份的天数
	for (int m = 1; m < d.m; m++)
		days += Daysofmonth(d.y, m);
	return days;
}
int main()
{
	date d1, d2;
	cout << "按以下格式输入两个日期，如2018年12月29日"<<endl;
	
	cin >> d1.y >> d1.m >> d1.d;
	cin >> d2.y >> d2.m >> d2.d;
	cout <<"第一个输入的日期为："<< d1.y << "年" << d1.m << "月" << d1.d << "日"<<endl;
	cout <<"第二个输入的日期为："<< d2.y << "年" << d2.m << "月" << d2.d << "日"<<endl;
	int days1 = DaysSum(d1);
	int days2 = DaysSum(d2);
	cout << "总共相差" << days1 - days2<< "天"<<endl;
	cout << "星期" << days1 % 7<<endl;
	cout<< "星期"<< days2 % 7 << endl;
	system("pause");
	return 0;
}
