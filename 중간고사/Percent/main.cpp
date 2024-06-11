#include <iostream>

using namespace std;

int main()
{
	int num;
	cin >> num;

	int ans = 1;

	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= num; j++) {
			cout << ans % 10;
			ans++;
			if (j % num == 0) cout << endl;
			else cout << " ";
		}
	}

	// int five = 0;

	// for (int i = 2; i < 51; i++) {
	// 	int cnt = 0;

	// 	for (int j = 1; j < i; j++) {
	// 		if (i % j == 0) cnt++;
	// 	}

	// 	if (cnt == 1) {
	// 		five++;
	// 		cout << i;
	// 		if (five % 5 != 0) cout << " ";
	// 		else cout << endl;
	// 	}
	// }
}