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
		cin >> n;
		int arr[200001];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		bool flag = true;
		bool plus = false;
		for (int i = 1; i < n; i++) {
			if (arr[i] - arr[i - 1] < 0) {
				if (plus) {
					cout << "NO" << "\n";
					flag = false;
					break;
				}
			}
			else if (arr[i] - arr[i - 1] > 0) {
				plus = true;
			}
		}

		if (flag) {
			cout << "YES" << "\n";
		}
	}
	
	
	return 0;
}
