#include <iostream>
#include <typeinfo>
#include <string>

using namespace std;
#define MAX_ARRAY_SIZE 100

// 매개변수에 배열 크기 생략 테스트
void print_arr2 (int x[][5], int n);

// 레퍼런스 반환해주는 함수 테스트
int& refer (int &n1);

// 클래스 참조자를 위한 테스트
class Test
{
private:
	int n;
	char c;
	string s;

public:
	Test() {
		n = 1;
		c = 'c';
		s = "st";	
	} // 디폴트 생성자(오버로딩 가능)

	Test(int num, char ch, string st) {
		n = num;
		c = ch;
		s = st;
	}; // 매개변수 생성자

	~Test() {}; // 소멸자(오버로딩 불가능)

	void set_n() {
		cin >> n;
	};
	void set_c() {
		cin >> c;
	};
	void set_s() {
		cin >> s;
	};

	void get_n() {
		cout << n << endl;
	};

	void get_c() {
		cout << c << endl;
	};

	void get_s() {
		cout << s << endl;
	};

	int tt = 5;
};

int main()
{
	int a[3][5] = { {10, 30, 50}, {70, 90} };

	int refedNum = 111;
	int &refNum1 = refedNum;

	cout << "^^^^^^ about return ref start! ^^^^^^" << endl;
	cout << "refedNum : " << refedNum << endl;
	cout << "refNum1 : " << refNum1 << endl;

	cout << "returning ..." << endl;

	int &refNum2 = refer(refNum1);

	cout << "refedNum : " << refedNum << endl;
	cout << "refNum1 : " << refNum1 << endl;
	cout << "refNum2 : " << refNum2 << endl;

	cout << "about address " << endl;

	cout << "&refedNum : " << &refedNum << endl;
	cout << "&refNum1 : " << &refNum1 << endl;
	cout << "&refNum2 : " << &refNum2 << endl;

	cout << "^^^^^^ about return ref end! ^^^^^^" << endl;

	 // class1 인스턴스 생성
	Test class1;

	// class1에 대한 클래스 포인터 변수
	Test *classPtr = &class1;

	cout << "********* class pointer start! *********" << endl;
	cout << classPtr->tt << endl;
	classPtr->get_c();
	(classPtr)->get_n();
	(*classPtr).get_s();

	class1.set_c();
	class1.set_n();
	class1.set_s();

	cout << classPtr->tt << endl;
	classPtr->get_c();
	(classPtr)->get_n();
	(*classPtr).get_s();

	classPtr->set_c();
	classPtr->set_n();
	classPtr->set_s();

	cout << (&class1)->tt << endl;
	(&class1)->get_c();
	(&class1)->get_n();
	class1.get_s();

	cout << "********* class pointer end! *********" << endl;

	cout << "&&&&&&&&& reference start! &&&&&&&&" << endl;

	// 참조자가 헷갈려서 테스트
	cout << "a :" << a << endl; // a의 배열이름이면서 배열의 시작 주소(a[0][0])
	cout << "a[1] : " << a[1] << endl; // a 배열의 두 번째 행이다. 주소는 a[1][0]을 가리킨다.
	cout << "&a : " << &(a) << endl; // 배열 전체 주소를 나타낸다. 이는 a[0][0]과 동일하지만 타입이 다르다.
	cout << "(&a)[1] : " << (&a)[1] << endl; // 배열 전체를 가리키는 포인터(&a)에서 한 단위 더 가리키는 주소. 여기에서 한 단위는 [3][5]이므로 15를 뜻한다.
	cout << "---" << endl;
	cout << "(a)'s type : " << typeid(a).name() << endl; // 3행 5열의 정수 배열
	cout << "(a[0])'s type : " << typeid(a[0]).name() << endl; // 5개의 정수로 구성된 배열
	cout << "(a[1])'s type : " << typeid(a[1]).name() << endl; // 5개의 정수로 구성된 배열
	cout << "(&a)'s type : " << typeid(&a).name() << endl; // 3행 5열의 정수 배열을 가리키는 포인터
	cout << "(&a)[0]'s type : " << typeid(&a[0]).name() << endl; // 5개의 정수로 구성된 배열을 가리키는 포인터
	cout << "(&a)[1]'s type : " << typeid(&a[1]).name() << endl; // 5개의 정수로 구성된 배열을 가리키는 포인터

	cout << "&&&&&&&&& reference end! &&&&&&&&" << endl;

	int array[MAX_ARRAY_SIZE] = { 1, 2, 3, 4, }; // 배열
	int num = 5; // 변수(정수형)
	int &ref = num; // 변수에 대한 참조(레퍼런스)
	int (&coef)[MAX_ARRAY_SIZE] = array; // 배열에 대한 참조(레퍼런스)
	const int num2 = 50; // 상수

	int cnt1 = 1;
	int cnt2 = 100;
	int cnt3 = 10;

	int *ptr1 = &cnt1; // 포인터 변수 ptr1에 대하여 주소값을 cnt1으로 할당
	const int *ptr2 = &cnt2; // "값에 대한 상수화" -> 주소값, 즉 ptr2를 가리키는 주소값은 바꿀 수 있지만, ptr2를 가리키는 값은 바꿀 수 없다.
	int* const ptr3 = &cnt3; // "포인터(주소)에 대한 상수화" -> 값, 즉 ptr3을 가리키는 값은 바꿀 수 있지만, ptr3을 가리키는 주소값은 바꿀 수 없다.
	
	cout << "*ptr1 : " << *(ptr1) << ", &ptr1 : " << ptr1 << endl;
	cout << "*ptr2 : " << *(ptr2) << ", &ptr2 : " << ptr2 << endl;
	cout << "*ptr3 : " << *(ptr3) << ", &ptr3 : " << ptr3 << endl;
	cout << "*num : " << (num) << ", &num : " << &num << endl;
	cout << "-------" << endl;

	// 포인터에 할당된 주소값 초기화
	ptr1 = &num; // ptr1은 cnt1의 주소값을 가지고 있었음. 이제는 num의 주소값을 가짐. 즉, 얕은 복사(ptr1을 수정하면 num도 수정됨)
	ptr2 = &num; // ptr2은 cnt1의 주소값을 가지고 있었음. 이제는 num의 주소값을 가짐. 즉, 얕은 복사(ptr2을 수정하면 num도 수정됨)
	// ptr3 = &num; -> 컴파일 에러 (주소값을 상수화했으므로 주소값을 수정할 수 없다.)

	cout << "*ptr1 : " << *(ptr1) << ", &ptr1 : " << ptr1 << endl;
	cout << "*ptr2 : " << *(ptr2) << ", &ptr2 : " << ptr2 << endl;
	cout << "*ptr3 : " << *(ptr3) << ", &ptr3 : " << ptr3 << endl;
	cout << "*num : " << (num) << ", &num : " << &num << endl;
	cout << "-------" << endl;

	// 포인터 참조된 값 초기화
	(*ptr1)++;
	// (*ptr2)++; -> 컴파일 에러 (값을 상수화했으므로 값을 수정할 수 없다.)
	(*ptr3)++;

	cout << "*ptr1 : " << *(ptr1) << ", &ptr1 : " << ptr1 << endl;
	cout << "*ptr2 : " << *(ptr2) << ", &ptr2 : " << ptr2 << endl;
	cout << "*ptr3 : " << *(ptr3) << ", &ptr3 : " << ptr3 << endl;
	cout << "*num : " << (num) << ", &num : " << &num << endl;
	cout << "*cnt3 : " << (cnt3) << ", &cnt3 : " << &cnt3 << endl;
	cout << "-------" << endl;

	// cout << *(array) << endl;

	// cout << *(array+2) << endl;

	// cout << *array << endl;

	// cout << *array+5 << endl;

	// cout << "---" << endl;

	// cout << &num2 << endl;

	// cout << num2 << endl;

	// cout << "----" << endl;
 
	// *(주소) = 값, *(주소)에 대한 멤버 접근 방법은 *(주소).멤버
	// 주소에 대한 멤버 접근 방법은 (주소)->멤버
	// int *ptr = &num;

	// cout << *array << endl;

	// cout << &array << endl;

	// cout << array << endl;

	// cout << "-----" << endl;

	// cout << *num << endl; -> 에러 발생

	// cout << &num << endl;

	// cout << num << endl;

	// cout << "----" << endl;

	// cout << *ref << endl; -> 에러 발생

	// cout << &ref << endl;

	// cout << ref << endl;

	// cout << "---" << endl;

	// cout << *ptr << endl;

	// cout << &ptr << endl;

	// cout << ptr << endl;

	// print_arr2(a , 3);

	return 0;
}

void print_arr2 (int x[][5], int n) {
	int i, j;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < 5; ++j) {
			printf("% d", x[i][j]);
		}
		printf("\n");
	}
}

int& refer(int& n1){
	n1 = n1 * 2;
	return n1;
}