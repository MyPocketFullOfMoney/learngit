#include<iostream>
using namespace std;
struct date
{
	int y;//��
	int m;//��
	int d;//��
};
//�ж��Ƿ�����
bool isleap(int y)
{
	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
		return 1;
	else
		return 0;
}
//�·�����
int Daysofmonth(int y, int m)
{
	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (m != 2)
		return month[m - 1];
	else
		return month[1] + isleap(y);
}
//�����ܹ�������
int DaysSum(date d)
{
	int days = d.d;
	//�������������
	for (int y = 1; y < d.y; y++)
		days += 365 + isleap(y);
	//�����·ݵ�����
	for (int m = 1; m < d.m; m++)
		days += Daysofmonth(d.y, m);
	return days;
}
int main()
{
	date d1, d2;
	cout << "�����¸�ʽ�����������ڣ���2018��12��29��"<<endl;
	
	cin >> d1.y >> d1.m >> d1.d;
	cin >> d2.y >> d2.m >> d2.d;
	cout <<"��һ�����������Ϊ��"<< d1.y << "��" << d1.m << "��" << d1.d << "��"<<endl;
	cout <<"�ڶ������������Ϊ��"<< d2.y << "��" << d2.m << "��" << d2.d << "��"<<endl;
	int days1 = DaysSum(d1);
	int days2 = DaysSum(d2);
	cout << "�ܹ����" << days1 - days2<< "��"<<endl;
	cout << "����" << days1 % 7<<endl;
	cout<< "����"<< days2 % 7 << endl;
	system("pause");
	return 0;
}
