#include <iostream>

using namespace std;

int main()
{
	// 세 번째 예제
	int num2;
	cin >> num2;

	int first = num2 / 10;
	int second = num2 % 10;
	int check = 3;

	if (first % 3 == 0 && second % 3 == 0) check = 1;
	else if (first % 3 == 0 || second % 3 == 0) check = 2;

	if (check == 1) cout << "**";
	else if (check == 2) cout << "??";
	else cout << "--";
	
	// 두 번째 예제
	// char c;
	// cin >> c;
	// if ('A' <= c && c <= 'Z') cout << "대문자";
	// else if ('a' <= c && c <= 'z') cout << "소문자";
	// else if ('0' <= c && c <= '9') cout << "숫자";
	// else cout << "기타";

	// 첫 번째 예제
	// int num;
	// cin >> num;

	// bool three = false; 
	// bool five = false;
	// bool seven = false;

	// for (int i = 1; i <= num; i++) {
	// 	if (num % 3 == 0) three = true;
	// 	if (num % 5 == 0) five = true;
	// 	if (num % 7 == 0) seven = true;
	// }

	// if (three) cout << "3의 배수" << endl;
	// if (five) cout << "5의 배수" << endl;
	// if (seven) cout << "7의 배수" << endl;

}