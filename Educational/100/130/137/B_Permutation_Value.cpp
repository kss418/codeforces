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
		vector <int> arr;
		for (int i = 1; i <= n; i+= 2) {
			arr.push_back(i);
		}
		if (n % 2 == 0) {
			for (int i = n; i > 0; i -= 2) {
				arr.push_back(i);
			}
		}
		else {
			for (int i = n - 1; i > 0; i -= 2) {
				arr.push_back(i);
			}
		}
		for (auto i : arr) {
			cout << i << " ";
		}
		cout << "\n";
	}

	return 0;
}
