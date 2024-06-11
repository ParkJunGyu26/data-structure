#include "Calculator.h"

// 생성자
Calculator::Calculator() {
	num1 = num2 = -1;
}

// 소멸자
Calculator::~Calculator() {}

// 빼기
int Calculator::sub(int n1, int n2) {
	return n1 - n2;
}

// 나누기(분모가 0인지 체크)
double Calculator::div(int n1, int n2) {
	return n1/n2;
}

// 입력
void Calculator::set(int n1, int n2) {
	if (n2 == 0) {
		cout << "분모에 0은 입력할 수 없습니다." << endl;
	} else {
	num1 = n1;
	num2 = n2;
	}
}

// 출력
void Calculator::display() {
	cout << num1 << ", " << num2 << endl;
}