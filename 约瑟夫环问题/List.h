//ѭ��������ʵ��Լɪ������
struct Node
{
	int data;			//���
	Node *next;
};
class List
{
public:
	List(int n);			//����β�巨��������Ϊn��Լɪ��
	~List();
	void Search(int keynum);	//��Ȧ�㷨
	void PrintList();
private:
	Node *head;
	Node *first;			//ָ���һ��Ԫ�ص�ָ��
};
