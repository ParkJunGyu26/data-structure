#include <iostream>

using namespace std;

// 
int main2()
{
	int a[5] = {4, 5, 6, 7, 8};
	int b[5] = {1, 3, 5, 7, 9};
	int c[5] = {0, 2, 4, 6, 8};

	int* p[3] = {a, b, c};

	for (int i = 0; i < 3; i++)
	{
		cout << "주소 값" << endl;
		cout << p+i << endl;
		cout << "-----" << endl;
		cout << "원소 값" << endl;
		cout << **(p+i) << endl;
	}

	return 0;
}