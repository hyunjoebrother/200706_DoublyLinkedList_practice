//Doubly Linked List�� realize�غ���
//SLL ���� ����, �� node ��ġ previous���� ����

#include <string>
#include <iostream>
using namespace std;

class DNode
{
private:
	string elem; //���Ұ� ����
	DNode* prev; //����Ʈ�� ���� �׸�
	DNode* next; //����Ʈ�� ���� �׸�

	friend class DLinkedList; //friend�� Ŭ������ ���� ����
};

class DLinkedList
{
private:
	DNode* header; //dummy ����/��Ʈ�� node -> ���� ����x
	DNode* trailer; 

protected: //���� �ڽ� class�� ���� ����
	void add(DNode* v, const string& e); //v ���� ���ο� node ����
	void remove(DNode* v); //v ��� ����

public:
	bool empty() const; //����Ʈ�� �����?
	const string& front() const; //���� ���Ҹ� ��´�
	const string& back() const; //���� ���Ҹ� ��´�
	
	void addFront(const string& e); //����Ʈ�� �տ��� �߰�
	void addBack(const string& e); //����Ʈ�� �ڿ��� �߰�

	void removeFront(); //�տ��� ����
	void removeBack(); //�ڿ��� ����

	//������ -> ��Ƽ�� node���� �����ϰ� ���ΰ� ���θ� ����Ű���� ����
	DLinkedList();

	//�Ҹ��� -> ��Ƽ��/dummy���� node�� ������ ��� node���� ����
	~DLinkedList();
};

bool DLinkedList::empty() const
{
	return (header->next == trailer);
}

const string& DLinkedList::front() const
{
	return header->next->elem;
}

const string& DLinkedList::back() const
{
	return trailer->prev->elem;
}

//Inserting at Header
void DLinkedList::add(DNode* v, const string& e)
{
	//���� u�� �Ҵ�޾Ƽ� ���� �߰��� node ����
	DNode* u = new DNode;
	//u�� ���ο� ������ ���� �ִ´�
	u->elem = e;
	//node u�� next�� header�� ����
	u->next = v;
	//node v�� prev�� trailer�� ����, u�� ����
	u->prev = v->prev = u;
	//node v�� prev�� node u�� ����
	v->prev->next = v->prev = u;
}


void DLinkedList::addFront(const string& e)
{
	add(header->next, e);
}


void DLinkedList::addBack(const string& e)
{
	add(trailer, e);
}

//Removing at Header
void DLinkedList::remove(DNode* v) //������ node v
{
	//������
	DNode* u = v->prev;
	//�ļ���
	DNode* w = v->next;
	//�� node�� ������ node ���� node�� �����Ѵ�
	u->next = w;
	//�� node�� ������ node �� node�� �����Ѵ�
	w->prev = u;

	delete v;
}

void DLinkedList::removeFront()
{
	remove(header->next);
}


void DLinkedList::removeBack()
{
	remove(trailer->prev);
}

//������
DLinkedList::DLinkedList()
{
	header = new DNode; //dummy����/��Ƽ�� node ����
	trailer = new DNode;
	header->next = trailer; //���θ� ����Ű���� �Ѵ�
	trailer->prev = header;
}

//�Ҹ���
DLinkedList::~DLinkedList()
{
	while (!empty()) 
		removeFront(); //dummy���� ������ ��� node ����
	delete header; //dummy���̵��� ����
	delete trailer;
}