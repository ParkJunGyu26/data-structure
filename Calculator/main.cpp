#include "Calculator.h"

int main()
{
	Calculator a;
	a.display();

	int num1, num2;
	cin >> num1 >> num2;

	a.set(num1, num2);
	a.display();
	cout << "------" << endl;

	int ans1, ans2;
	ans1 = a.sub(num1, num2);
	ans2 = a.div(num1, num2);

	a.set(ans1, ans2);
	a.display();
	cout << "-----" << endl;
}