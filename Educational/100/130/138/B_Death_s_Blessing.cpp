#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
int st, en;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, num;
		long long sum = 0;
		deque <int> heal;
		cin >> n;
		for (int i = 0; i < n;i++) {
			cin >> num;
			sum += num;
		}
		for (int i = 0; i < n; i++) {
			cin >> num;
			heal.push_back(num);
		}

		while (heal.size() != 1) {
			if (heal[0] >= heal[heal.size() - 1]) {
				sum += heal[heal.size() - 1];
				heal.pop_back();
			}
			else {
				sum += heal[0];
				heal.pop_front();
			}
		}

		cout << sum << "\n";

	}


	return 0;
}
