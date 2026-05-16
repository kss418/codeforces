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
		vector <pair <int, int>> track;
		int n,num;
		cin >> n >> num;
		int arr[8][8] = { 0, };
		while (num--) {
			int y, x;
			cin >> y >> x;
			track.push_back({ x,y });
			for (int i = 0; i < n; i++) {
				arr[y - 1][i]++;
				arr[i][x - 1]++;
			}
		}

		bool flag = false;
		for (auto j : track) {
			if (flag) {
				break;
			}

			for (int i = 0; i < n; i++) {
				if (arr[j.second - 1][i] == 1) {
					flag = true;
					break;
				}
				if (arr[i][j.first - 1] == 1) {
					flag = true;
					break;
				}
			}
		}

		if (flag) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}
	}


	return 0;
}
