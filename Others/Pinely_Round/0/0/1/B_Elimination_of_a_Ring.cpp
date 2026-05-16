#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;



int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);


	int t;
	cin >> t;
	while (t--) {
		set <int> arr;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			arr.insert(num);
		}

		if (arr.size() >= 3) {
			cout << n << "\n";
		}
		else if (arr.size() == 2) {
			cout << n / 2 + 1 << "\n";
		}
		else {
			cout << 1 << "\n";
		}
	}


	return 0;
}
