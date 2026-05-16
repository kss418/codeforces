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
		int arr[101];
		cin >> n;
		int m = 10000000;


		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			m = min(arr[i], m);
		}
		int cnt = 0;

		for (int i = 0; i < n; i++) {
			if (arr[i] >= 2 * m) {
				int moc = arr[i] / (2 * m - 1);
				if (arr[i] % (2 * m - 1) == 0) {
					cnt += moc - 1;
				}
				else {
					cnt += moc;
				}
			}
		}



		cout << cnt << "\n";
	}


	return 0;
}
