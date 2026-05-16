#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a - 1 < abs(b - c) + c - 1) {
			cout << 1 << "\n";
		}
		else if (a - 1 > abs(b - c) + c - 1) {
			cout << 2 << "\n";
		}
		else {
			cout << 3 << "\n";
		}
	}


	return 0;
}
