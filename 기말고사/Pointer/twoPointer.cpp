#include <iostream>

using namespace std;

// 2차원 배열 출력
int main3()
{
	// int a[5] = {4, 5, 6, 7, 8};
	// int b[5] = {1, 3, 5, 7, 9};
	// int c[5] = {0, 2, 4, 6, 8};

	// int* p[3] = {a, b, c};
	// int** pp = p;

	// for (int i = 0; i < 3; i++) {
	// 	for (int j = 0; j < 5; j++) {
	// 		cout << *(*(p+i)+j) << "  ";
	// 	}
	// 	cout << endl;
	// }

	int A = 1, B = 2, C = 3;
	int *pi[3] = {&A, &B, &C};
	int **ppi = nullptr;

	ppi = pi;

	for (int i = 0; i < 3; i++) {
		cout << "pi[" << i << "] :" << *(ppi+i) << endl;
		cout << "pi[" << i << "] :" << *ppi+i << endl;
		cout << "pi[" << i << "] :" << **(ppi+i) << endl;
		cout << "pi[" << i << "] :" << **ppi+i << endl;
		cout << "----" << endl;
	}
}