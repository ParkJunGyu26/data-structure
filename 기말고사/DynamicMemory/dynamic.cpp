#include <iostream>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	int **ans = new int*[n];

	for (int i = 0; i < n; i++)
		ans[i] = new int[m];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> ans[i][j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ans[i][j] << "  ";
		}
		cout << endl;
	}

	for (int i = 0; i < n; i++)
		delete[] ans[i];
	delete[] ans;

	return 0;
}