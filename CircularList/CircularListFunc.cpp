#include "CircularList.h"

// 생성자
CircularList::CircularList() : tail(nullptr), listsize(0) {}

// 사용했던 메모리들을 모두 반납
CircularList::~CircularList() 
{
	clear();
}

// 여기에서 head는 첫 번째 노드를 가리킨다.
// 따라서, 제일 마지막 값인 tail의 다음 포인터 주소를 가리킨다.
// 원형연결리스트이므로 서로 돌고돈다.
Node* CircularList::getHead() 
{
	if (isEmpty())
		return nullptr;
	return tail->getNext();
}

// 여기에서 tail은 첫 번째 노드를 가리키기 직전을 가리킨다.
// tail은 제일 마지막 노드를 가리킨다.
Node* CircularList::getTail() 
{
	return tail;
}

// tail 새로운 값 할당
void CircularList::setTail(Node* n) 
{
	tail = n;
}

// 리스트가 비었는지 체크
bool CircularList::isEmpty() 
{
	return tail == nullptr;
	// return listsize == 0;
}

// 크기 반환
int CircularList::size()
{
	return listsize;
}

// 특정 위치의 값 조회
int CircularList::getEntry(int pos) 
{
	if (isEmpty() || pos < 0 || pos > listsize)
	{
		cout << "ERROR" << endl;
		return -1;
	}

	Node* current = getHead();
	int count = 0;

	while (count != pos)
	{
		++count;
		current = current->getNext();
	}

	return current->getData();
}

// 리스트에 새로운 노드 추가
// 위치가 범위 밖일 경우 예외처리 해주기
// 또한, 여기에 끝이 아니라
// "헤드 부분 추가"
// "테일 부분 추가"
// 이 둘에 대해서도 예외처리해줘야 됨.
// 그리고 "처음 노드 추가"
// 이 부분에 대해서도 처리해줘야 됨.
void CircularList::insert(int pos, const int data) 
{
	// 적절하지 않은 범위 예외처리
	if (pos < 0 || pos > size())
	{
		cout << "ERROR" << endl;
		exit(1);
	}

	Node* newNode = new Node(data);
	Node* current = getHead();

	// 헤드에 추가하는 경우
	if (pos == 0)
	{

	}
	// 추가하려는 위치 직전의 노드 주소값 탐색(순차)
	for (int i = 0; i <= pos-1; i++)
		current = current->getNext();

	// 새로운 노드는 직전 노드가 가리키고 있던 노드를 가리키도록 초기화
	newNode->setNext(current->getNext());

	// 직전 노드가 가리키던 노드를 새로운 노드를 가리키도록 초기화
	current->setNext(newNode);

	// 노드가 추가되었으니 사이즈는 1 증가
	listsize++;

	// gpt 코드

	// 리스트가 비었을 경우를 고려해서 코드 작성
	// 왜냐하면, tail은 처음에는 nullptr 이므로
	// 처음에 노드를 삽입하면,
	// 처음 노드에 대해서 tail 으로 설정해줘야 되기 때문

	// if (pos < 0 || pos > listsize)
	// 	return;

	// Node* newNode = new Node(data);

	// 리스트가 비었을 경우
	// if (isEmpty())
	// {
	// 	newNode->setNext(newNode);
	// 	tail = newNode;
	// } else 
	// {
	// 	Node* current = tail;

	// 	for (int i = 0; i < pos; i++)
	// 		current = current->getNext();
		
	// 	newNode->setNext(current->getNext());
	// 	current->setNext(newNode);

	// 	if (pos == 0)
	// 		tail->setNext(newNode);
	// }

	// if (pos == listsize)
	// 	tail = newNode;
	
	// listsize++;
}

// 일반적인 위치의 노드 제거와
// 양 끝에 head, tail 노드 제거했을 경우를
// 처리해줘야 됨.
Node* CircularList::rmv(int pos) 
{
	// 적절한 범위에서 진행되도록
	// 예외처리
	if (isEmpty() || pos < 0 || pos > size())
	{
		cout << "ERROR" << endl;
		return nullptr;
	}

	// 현재 헤드 위치 조회
	Node* current = getHead();

	// 헤드를 지울 경우
	if (pos == 0)
	{
		// tail이 가리키는 헤드 위치를
		// 현재 가리키는 헤드 다음 위치로 변경
		tail->setNext(current->getNext());

		// 삭제된 헤드 next는 nullptr로 변경
		current->setNext(nullptr);

		return current;

	// tail을 지울 경우
	} else if (pos == size())
	{
		// 삭제시킬 tail 변수 할당
		Node* removedItem = getTail();

		// tail 직전 위치까지 이동시키기
		while(current->getNext() != tail) 
			current = current->getNext();
		
		// tail 직전 노드가 이제 tail 이므로
		// 가리키는 곳은 
		// head 가 되도록 변경
		current->setNext(getHead());

		// tail 값을 직전 노드로 변경
		setTail(current);

		return removedItem;

	// 일반적인 위치를 지울 경우
	} else 
	{
		// 삭제시킬 위치 직전까지 current 값을 이동
		for (int i = 0; i <= pos-1; i++)
			current = current->getNext();
		
		// 삭제할 값 변수 할당
		Node* removedItem = current->getNext();

		// 삭제 직전 노드와 삭제 직후 노드를 연결시키는 작업
		current->setNext( removedItem -> getNext());

		return removedItem;
	}

	// gpt 코드

	// 여기에서는 첫 번째 노드 삭제와
	// 그 외의 삭제로 두 가지로 분류
	// if (isEmpty() || pos >= listsize || pos < 0)
	// 	return nullptr;

	// Node* current = tail;
	// Node* toRemove = nullptr;

	// 삭제 위치가 헤드일 경우
	// if (pos == 0)
	// {
	// 	toRemove = current->getNext();
	// 	if (listsize == 1)
	// 		tail = nullptr;
	// 	else
	// 		current->setNext(toRemove->getNext());

	// } else
	// {
	// 	for (int i = 0; i < pos; i++)
	// 		current = current->getNext();
		
	// 	toRemove = current->getNext();
	// 	current->setNext(toRemove->getNext());

	// 	if (pos == listsize - 1)
	// 		tail = current;
	// }

	// listsize--;
	// return toRemove;
}

// 리스트 모두 출력
void CircularList::showList() 
{
	if (isEmpty())
	{
		cout << "List is Empty" << endl;
		exit(1);
	}

	Node* current = getHead();
	while (current != tail->getNext())
	{
		cout << current->getData() << "  ";
		current = current->getNext();
	}
	cout << endl;

	// gpt 코드
	// Node* start = getHead();
	// Node* current = start;

	// do {
	// 	cout << current->getData();
	// 	current = current->getNext();
	// } while (current != start);

	// cout << endl;
}

// 노드 메모리 반납
void CircularList::clear() 
{
	while (!isEmpty())
	{
		Node* temp = rmv(0);
		delete temp;
	}
}