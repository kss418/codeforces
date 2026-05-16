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
		int n, q, num;
		long long odd = 0, even = 0;
		int even_cnt = 0, odd_cnt = 0;
		cin >> n >> q;
		for (int i = 0; i < n; i++) {
			cin >> num;
			if (num % 2 == 0) {
				even += num;
				even_cnt++;
			}
			else {
				odd += num;
				odd_cnt++;
			}
		}

		int com;
		for (int i = 0; i < q; i++) {
			cin >> com >> num;
			if (com == 0) {
				if (num % 2 == 0) {
					even += even_cnt * num;
				}
				else {
					odd += even;
					even = 0;
					odd += even_cnt * num;
					odd_cnt += even_cnt;
					even_cnt = 0;
				}
			}
			else {
				if (num % 2 == 0) {
					odd += odd_cnt * num;
				}
				else {
					even += odd;
					odd = 0;
					even += odd_cnt * num;
					even_cnt += odd_cnt;
					odd_cnt = 0;
				}
			}
			cout << even + odd << "\n";
		}
	}

	return 0;
}
