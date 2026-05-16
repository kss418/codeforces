#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n % 2 == 0) {
			for (int i = n; i > n / 2; i--) {
				cout << i - n / 2 << " " << i << " ";
			}
			cout << "\n";
		}
		else {
			cout << n << " ";
			for (int i = n - 1; i > (n - 1)/ 2; i--) {
				cout << i - n / 2 << " " << i << " ";
			}
			cout << "\n";
		}

	}

	return 0;
}
