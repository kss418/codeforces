#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int n;
		int arr[200001];
		cin >> n;
		int m = 0;
		int se = 0;
		int cur;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			if (arr[i] >= m) {
				se = m;
				m = arr[i];
				cur = i;
			}
			else if (arr[i] >= se) {
				se = arr[i];
			}
		}

		for (int i = 0; i < n; i++) {
			if (i != cur) {
				cout << arr[i] - m << " ";
			}
			else {
				cout << arr[i] - se << " ";
			}
		}
		cout << "\n";
	}


	return 0;
}
