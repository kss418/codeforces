#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int n, arr[200001], cnt = 0;
		vector <int> mul;
		cin >> n;
		int pow = n;

		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			int num = arr[i];
			int cur = i;
			int two = 0;
			while (1) {
				if (cur % 2 == 0) {
					cur >>= 1;
					two++;
				}
				else {
					mul.push_back(two);
					break;
				}
			}

			while (1) {
				if (num % 2 == 0) {
					num >>= 1;
					pow--;
				}
				else {
					break;
				}
			}
		}

		sort(mul.begin(), mul.end());
		reverse(mul.begin(), mul.end());

		int cur = 0;
		while (1) {
			if (pow <= 0 || cur == n) {
				if (pow > 0) {
					cout << -1 << "\n";
				}
				else {
					cout << cnt << "\n";
				}

				break;
			}

			cnt++;
			pow -= mul[cur];
			cur++;
		}
	}

	return 0;
}
