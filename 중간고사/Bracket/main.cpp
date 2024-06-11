#include "Bracket.h"

int main()
{
	string str;
	cout << "괄호를 입력해주세요." << endl;
	cin >> str;

	Stack stack;

	for (auto c : str) {
		if (c == '(' || c == '[' || c == '{') {
			stack.push(c);
		} else {
			if (stack.isEmpty()) {
				cout << "조건2 위배" << endl;
				break;
			} else {
				if (c == ')') {
					if (stack.peek() == '(') stack.pop();
					else cout << "조건3 위배" << endl;
					break;
				} else if (c == ']') {
					if (stack.peek() == '[') stack.pop();
					else cout << "조건3 위배" << endl;
					break;
				} else {
					if (stack.peek() == '{') stack.pop();
					else cout << "조건3 위배" << endl;
					break;
				}
			}
		}
	}

	if (stack.isEmpty()) cout << "괄호 검사 완료" << endl;
	else cout << "조건1 위배" << endl;
	
}