#include "LinkedList.h"

// 생성자
LinkedList::LinkedList() {}

// 소멸자
// 링크드 리스트의 값들의 주소값 반환
LinkedList::~LinkedList() 
{
	clear();
}

// 링크드리스트의 헤드 값 출력
Node* LinkedList::getHead() 
{
	return head.getNext();
}

// 링크드리스트가 비었을 경우
bool LinkedList::isEmpty() 
{
	return getHead() == nullptr;
}

// 해당 위치의 노드 값 출력
int LinkedList::getEntry(int pos) 
{
	// 만약 링크드 리스트가 비었을 경우와
	// 위치가 범위 밖일 경우에는
	// 예외처리
	if (isEmpty() || pos < 0 || pos >= size())
	{
		cout << "ERROR!" << endl;
		return -1;	// exit(1);
	}

	// 링크드 리스트가 비어있지 않다는 가정하에
	// 해당 위치까지 반복문을 통해 포인터 주소 가져오기
	Node* current = getHead();
	for (int i = 0; i < pos; i++)
		current = current->getNext();
	
	// 해당 위치의 데이터 조회
	return current->getData();
}

// 해당 위치에 해당 데이터의 노드 삽입
void LinkedList::insert(int pos, const int data) 
{
	// 삽입할 위치가 범위 밖인 예외처리
	if (pos < 0 || pos > size())
	{
		cout << "Invaild position!" << endl;
		exit(1);
	}

	// 새로운 노드 값에 대한 동적 할당(매개변수로 받은 data 값 할당)
	Node* newNode = new Node(data);

	// 삽입할 위치의 전까지 반복문을 돌건데, 이는 연결리스트이므로 순차 탐색해줘야됨
	Node* prev = &head;
	for (int i = 0; i <= pos-1; i++)
		prev = prev->getNext();
	
	// 새로운 노드 값의 next 값을 이전에 있었던 노드의 next 값으로 할당
	newNode->setNext(prev->getNext());

	// 삽입할 위치 직전의 노드 값의 next 주소는 새로 추가된 노드로 할당
	prev->setNext(newNode);
}

// 해당 위치의 노드 제거
Node* LinkedList::rmv(int pos) 
{
	// 링크드 리스트가 비었을 경우와
	// 위치가 범위 밖일 경우의
	// 예외처리
	if (isEmpty() || pos < 0 || pos >= size())
	{
		cout << "ERROR!" << endl;
		exit(1);
	}

	// 반환할 삭제된 노드 변수 생성
	Node* removedNode = nullptr;

	// 삭제할 값 위치 직전까지 반복문 시작
	// 이를 위해선 head부터 시작해야됨(순차탐색) -> 단일 연결 리스트
	Node* prev = &head;

	// 삭제할 값 위치 직전까지
	// getNext() 메서드 이용해서 해당 위치 직전 노드 찾기
	for (int i = 0; i <= pos-1; i++)
		prev = prev->getNext();
	
	// prev 변수는 삭제할 위치의 직전에 있는 노드이므로
	// 삭제할 노드의 값을 getNext()를 통해 초기화
	removedNode = prev->getNext();

	// 삭제할 직전 위치의 노드의 다음 값은 다다음 값을 가리켜야됨
	prev->setNext(removedNode->getNext());

	// 삭제할 값의 다음 값은 nullptr로 초기화
	removedNode->setNext(nullptr);

	return removedNode;
}

// 해당 data 값이 존재하는지 탐색
bool LinkedList::find(int data) 
{
	// 해당 링크드 리스트가 비었을 경우엔 항상 거짓
	if (isEmpty())
		return false;
	
	Node* current = getHead();
	for (int i = 0; i < size(); i++)
	{
		if (current->getData() == data)
			return true;
	}

	return false;

	// 교수님 코드
	// Node* current = getHead();
	// while (current != nullptr)
	// {
	// 	if (current->getData() == data)
	// 		return true;
	// 	current = current->getNext();
	// }
	// return false;
}

// 해당 위치의 데이터 값을 매개변수의 data로 변경
void LinkedList::replace(int pos, const int data) 
{
	if (isEmpty() || pos < 0 || pos >= size())
	{
		cout << "ERROR!" << endl;
		exit(1);
	}

	Node* current = getHead();
	
	for (int i = 0; i <= pos; i++)
		current = current->getNext();

	current->setData(data);
}

int LinkedList::size() 
{
	if (isEmpty())
		return 0;

	Node* current = getHead();
	int count = 1;

	while(current->getNext())
	{
		current = current->getNext();
		count++;
	}

	return count;

	// 교수님 코드
	// int count = 0;

	// Node* current = getHead();
	// while (current != nullptr)
	// {
	// 	++count;
	// 	current = current->getNext();
	// }
	// return count;
}

void LinkedList::showList() 
{
	if(isEmpty())
	{
		cout << "LinkedList is Empty" << endl;
		exit(1);
	}

	Node* current = getHead();

	for (int i = 0; i <= size(); i++)
		cout << current->getData() << "  ";
	cout << endl;

	// 교수님 코드
	// Node* current = getHead();
	// while (current != nullptr)
	// {
	// 	cout << current->getData() << "  ";
	// 	current = current->getNext();
	// }
	// cout << endl;
}

void LinkedList::clear() 
{
	Node* current = getHead();
	while (current != nullptr)
	{
		Node* temp = current;
		delete temp;
		current = current->getNext();
	}

	// 교수님 코드
	// while(!isEmpty())
		// delete rmv(0);
}

// 모든 노드 값들 합산
int LinkedList::calcSum() 
{
	int sum = 0;
	Node* current = getHead();
	while (current != nullptr)
	{
		sum += current->getData();
		current = current->getNext();
	}
	return sum;
}

// 매개변수 데이터가 몇 개 존재하는지
int LinkedList::countNode(int val) 
{
	int count = 0;
	Node* current = getHead();
	while (current != nullptr)
	{
		if (current->getData() == val)
			++count;
		current = current->getNext();
	}
	return count;
}

// 역으로 출력
void LinkedList::reverse() 
{
	Node* current = getHead();
	Node* previous = nullptr;
	Node* next = nullptr;

	while (current != nullptr)
	{
		next = current->getNext();
		
		current->setNext(previous);

		previous = current;
		current = next;
	}

	head.setNext(previous);
}

// 두 리스트 합치기
// 현재 리스트의 마지막 노드를
// 매개변수 리스트의 헤드와 연결
void LinkedList::merge(LinkedList* that) 
{
	// 해당 객체의 리스트가 비어있다면
	if (isEmpty())
	{
		// 해당 리스트의 헤드를 매개인자의 포인터 값으로 할당
		head.setNext(that->getHead());
	} else 
	{
		Node* current = getHead();

		// 해당 객체의 리스트의 마지막 값을 찾기 위해 반복문
		while(current->getNext() != nullptr)
		{
			current->getNext();
		}

		// current는 마지막 노드임을 알 수 있다.
		// nullptr을 가리키고 있기 때문이다.
		// 따라서, 해당 객체의 리스트의 마지막 값과
		// 매개인자의 리스트 주소 값의 헤드와 연결해준다.
		current->setNext(that->getHead());
	}
}