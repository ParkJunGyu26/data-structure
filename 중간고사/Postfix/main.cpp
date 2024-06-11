#include "Postfix.h"

#include <string>

int is_priority(char cal) {
	if (cal == '(' || cal == ')')
		return 1;
	if (cal == '+' || cal == '-')
		return 2;
	if (cal == '*' || cal == '/')
		return 3;
}

int main() {
	// input -> 입력값, cal -> 연산기호, ans -> 정답
	Stack cal, ans;
	string input;

	cin >> input;

	for (int i = 0; i < input.size(); i++) {
		if ('A' <= input[i] || input[i] <= 'Z')
			ans.push(input[i]);
		else {
			if (input[i] == '(')
				cal.push(input[i]);
			else if (input[i] == ')')
				while (!cal.isEmpty()) {
					char tmp = cal.peek();
					if 
				}
		}
	}	
}