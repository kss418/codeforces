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
		int arr[200001];
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}

		int num = 0, cnt = 0;
		vector <pair <int, int>> track;

		if (n % 2 == 1) {
			cout << -1 << "\n";
			continue;
		}

		for (int i = 1; i <= n; i++) {
			if (i < n && arr[i] == arr[i + 1]) {
				track.push_back({ i,i + 1 });
				i++;
			}

			else {
				track.push_back({ i,i });
				i++;
				track.push_back({ i,i });
				cnt++;
			}
			cnt++;
		}

		if (num == 0) {
			cout << cnt << "\n";
			for (auto j : track) {
				cout << j.first << " " << j.second << "\n";
			}
		}
		else {
			cout << -1 << "\n";
		}
	}

	return 0;
}
