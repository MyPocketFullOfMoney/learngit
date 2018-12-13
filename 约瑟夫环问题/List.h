//循环单链表，实现约瑟夫环问题
struct Node
{
	int data;			//编号
	Node *next;
};
class List
{
public:
	List(int n);			//利用尾插法，构造编号为n的约瑟夫环
	~List();
	void Search(int keynum);	//出圈算法
	void PrintList();
private:
	Node *head;
	Node *first;			//指向第一个元素的指针
};
