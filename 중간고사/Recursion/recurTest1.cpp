#include <iostream>

using namespace std;

void recursion(int x)
{
	if (x / 10 == 0) {
		cout << x%10;
	} else {
		cout << x%10;
		recursion(x/10);
	}
}

int main()
{
	int num;
	cin >> num;

	recursion(num);
}