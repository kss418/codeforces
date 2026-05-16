#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> diff;
int money[200000], value[200000];




int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int n, arr1[101], arr2[101];
		int sarr1 = 0, sarr2 = 0;
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> arr1[i];
			sarr1 += arr1[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> arr2[i];
			sarr2 += arr2[i];
		}

		int diff = 0;
		for (int i = 0; i < n; i++) {
			if (arr1[i] != arr2[i]) {
				diff++;
			}
		}

		cout << min(diff, abs(sarr1 - sarr2) + 1) << "\n";
	}



	return 0;
}
