#include "Polynomial.h"

int i, j;

// 생성자
Polynomial::Polynomial(): degree(0), coef {0} {
	// degree = 0;
	// coef[MAX_ARRAY-1] = {0};
}

// 소멸자
Polynomial::~Polynomial() {}

// 값 입력
void Polynomial::read() {
	cin >> degree;
	for (i = degree; i >= 0; i--) {
		cin >> coef[i];
	}
}

// 덧셈
void Polynomial::add(Polynomial a, Polynomial b) {
	// 새로운 객체에 대한 차수 초기화 무조건!!
	// *this = a;

	if (a.degree > b.degree) {
		*this = a;
		// degree = a.degree;
		for (i = a.degree; i >= 0; i--) {
			// coef[i] = a.coef[i] + b.coef[i];
			coef[i] += b.coef[i];
		}
	} else {
		*this = b;
		// degree = b.degree;
		for (i = b.degree; i >= 0; i--) {
			// coef[i] = a.coef[i] + b.coef[i];
			coef[i] += a.coef[i];
		}
	}
}

// 뺄셈(덧셈 메서드를 활용해서 구현)
void Polynomial::sub(Polynomial a, Polynomial b) {
	
	for (i = b.degree; i >= 0; i--) b.coef[i] *= -1;

	add(a, b);
	// 빼기 다 하고나서, 최고차항 업데이트 해주기
	trim();

	for (i = b.degree; i >= 0; i--) b.coef[i] *= -1;

}

// 곱셈
void Polynomial::mul(Polynomial a, Polynomial b) {
	// 최고차항은 지수이므로 곱셈이 아닌 덧셈!!
	degree = a.degree + b.degree;
	for (i = a.degree; i >= 0; i--) {
		for (j = b.degree; i >= 0; j--) {
			// 같은 연산자 있을 수 있으니 
			coef[i+j] += coef[i] * coef[j];
		}
	}
}

// 뺄 경우에는 이전 최고차항이 0이 될 수 있으므로 초기화해야돰
void Polynomial::trim() {
	for (i = degree; i >= 0; i--) {
		if (coef[i] != 0)
			degree = i;
			break;
	}

	// 예외처리(모든 값들이 0이라서 최고차항이 상수인 경우)
	if (coef[0] == 0) 
		degree = 0;
}

void Polynomial::display() {
	for (i = degree; i > 0; i--) {
		if (coef[i] == 1) {
			cout << "x^" << i << "+";
		} else if (coef[i] > 1) {
			cout << coef[i] << "x^" << i << "+";
		}
	}

	if (coef[0]) {
		cout << coef[0];
	}

	cout << endl;
}