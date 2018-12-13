#ifndef LinkList_H	//避免包含重复的LinkList.h头文件
#define LinkList_H	
//定义单链表的结点
template<class DataType>
struct Node
{
	DataType data;
	Node<DataType> *next;
};
//类LinkList的声明
template<class DataType>
class LinkList
{
public:
	LinkList();	//无参构造函数,建立空链表
	LinkList(DataType a[], int n);	//带参数的构造函数，建立有n个元素的链表
	~LinkList();		//析构函数
	int Locate(DataType x);		//查找值为x的元素序号
	void Insert(int i, DataType x);	//在第i个位置插入元素值为x的结点
	DataType Delete(int i);		//在单链表中删除第i个结点
	void PrintList();				//按序号依次输出各元素
private:
	Node<DataType> *first;			//单链表的头指针
};
#endif // !1
