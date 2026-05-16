#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int num, n, x, cur;
bool flag;
int arr[600001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr[num]++;
		cur = num;
		while (arr[cur] >= cur + 1) {
			arr[cur] -= cur + 1;
			arr[cur + 1]++;
			cur++;
		}
	}

	flag = true;
	for (int i = 1; i < x; i++) {
		if (arr[i] != 0) {
			flag = false;
			break;
		}
	}

	if (flag) {
		cout << "Yes" << "\n";
	}
	else {
		cout << "No" << "\n";

	}

	return 0;
}
