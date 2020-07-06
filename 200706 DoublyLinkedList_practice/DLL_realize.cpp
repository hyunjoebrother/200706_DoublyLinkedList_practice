//Doubly Linked List를 realize해보자
//SLL 단점 보완, 앞 node 위치 previous까지 저장

#include <string>
#include <iostream>
using namespace std;

class DNode
{
private:
	string elem; //원소값 정보
	DNode* prev; //리스트의 이전 항목
	DNode* next; //리스트의 다음 항목

	friend class DLinkedList; //friend로 클래스에 접근 제공
};

class DLinkedList
{
private:
	DNode* header; //dummy 더미/센트럴 node -> 원소 저장x
	DNode* trailer; 

protected: //나와 자식 class만 접근 가능
	void add(DNode* v, const string& e); //v 전에 새로운 node 삽입
	void remove(DNode* v); //v 노드 제거

public:
	bool empty() const; //리스트가 비었나?
	const string& front() const; //앞의 원소를 얻는다
	const string& back() const; //뒤의 원소를 얻는다
	
	void addFront(const string& e); //리스트의 앞에서 추가
	void addBack(const string& e); //리스트의 뒤에서 추가

	void removeFront(); //앞에서 제거
	void removeBack(); //뒤에서 제거

	//생성자 -> 센티널 node들을 생성하고 서로가 서로를 가르키도록 설정
	DLinkedList();

	//소멸자 -> 센티널/dummy더미 node를 제외한 모든 node들을 제거
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
	//공간 u를 할당받아서 새로 추가할 node 생성
	DNode* u = new DNode;
	//u에 새로운 데이터 값을 넣는다
	u->elem = e;
	//node u를 next로 header와 연결
	u->next = v;
	//node v를 prev로 trailer와 연결, u가 들어간다
	u->prev = v->prev = u;
	//node v를 prev로 node u와 연결
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
void DLinkedList::remove(DNode* v) //삭제할 node v
{
	//선행자
	DNode* u = v->prev;
	//후속자
	DNode* w = v->next;
	//앞 node를 삭제할 node 다음 node와 연결한다
	u->next = w;
	//뒤 node를 삭제할 node 앞 node와 연결한다
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

//생성자
DLinkedList::DLinkedList()
{
	header = new DNode; //dummy더미/센티널 node 생상
	trailer = new DNode;
	header->next = trailer; //서로를 가르키도록 한다
	trailer->prev = header;
}

//소멸자
DLinkedList::~DLinkedList()
{
	while (!empty()) 
		removeFront(); //dummy들을 제외한 모든 node 삭제
	delete header; //dummy더미들을 삭제
	delete trailer;
}