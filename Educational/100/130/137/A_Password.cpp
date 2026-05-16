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
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
		}
		int cnt = 10;
		cnt -= n;
		int result = cnt * (cnt - 1);
		result *= 3;
		cout << result << "\n";
	}

	return 0;
}
