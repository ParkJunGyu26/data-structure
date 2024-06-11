// 반복문으로 역순 출력(퍼센트 써서)

#include <iostream>
#include <cmath>

using namespace std;

int recurTest2()
{
	int num, cnt, tmp;
	cin >> num;

	// 10의 제곱 확인
	tmp = num;
	while (tmp > 10) {
		tmp /= 10;
		cnt++;
	}

	for (int i = tmp; i > 0; i--) {
		int target = pow(10, i);
		cout << (num % target);
	}
}