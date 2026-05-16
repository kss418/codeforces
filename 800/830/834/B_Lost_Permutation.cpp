#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int n, s;
		cin >> n >> s;
		int arr[200];
		int m = 0;
		fill(arr, arr + 200, 0);
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			arr[num] = 1;
			m = max(m, num);
		}


		for (int i = 1; i <= 199;i++) {
			if (!arr[i]) {
				s -= i;
				arr[i] = 1;
			}

			if (s <= 0) {
				break;
			}
		}

		bool flag = true;
		bool zero = false;
		for (int i = 1; i <= 199; i++) {
			if (arr[i] == 0 && !zero) {
				zero = true;
			}
			else if (arr[i] == 1 && zero) {
				flag = false;
			}
		}

		if (s == 0 && flag) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}
	}


	return 0;
}
