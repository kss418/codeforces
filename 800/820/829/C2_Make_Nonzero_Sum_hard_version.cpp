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
		int count = 0;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			if (arr[i] != 0) {
				count++;
			}
		}

		if (count % 2 == 1) {
			cout << -1 << "\n";
			continue;
		}

		int cnt = 0;
		vector <pair <int, int>> track;

		for (int i = 1; i <= n; i++) {
			if (arr[i] == 0) {
				track.push_back({ i,i });
				cnt++;
			}
			else {
				if (arr[i] == arr[i + 1]) {
					track.push_back({ i,i + 1 });
					cnt++;
					i++;
				}
				else if (arr[i] == -arr[i + 1]) {
					track.push_back({ i,i });
					i++;
					track.push_back({ i,i });
					cnt += 2;
				}
				else {
					int cur = i + 1;
					while (arr[cur] == 0) {
						cur++;
					}
					if (arr[cur] == arr[i]) {
						track.push_back({ i,cur - 2 });
						track.push_back({ cur - 1 ,cur });
						cnt += 2;
					}
					else if (arr[cur] == -arr[i]) {
						track.push_back({ i,cur - 1 });
						track.push_back({ cur,cur });
						cnt += 2;

					}
					i = cur;
				}
			}
		}

		cout << cnt << "\n";
		for (auto j : track) {
			cout << j.first << " " << j.second << "\n";
		}

	}

	return 0;
}
