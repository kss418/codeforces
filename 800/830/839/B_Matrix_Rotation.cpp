#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
using namespace std;
typedef long long ll;
ll n, m, k, t; string s;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 101010;
ll arr[3][3];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);


	cin >> t;
	while (t--) {
		for (int i = 1; i <= 2; i++) {
			for (int j = 1; j <= 2; j++) {
				cin >> arr[i][j];
			}
		}

		bool flag = 0;
		if (arr[1][1] < arr[1][2] && arr[1][1] < arr[2][1] && arr[2][1] < arr[2][2] && arr[1][2] < arr[2][2]) {
			flag = 1;
		}

		ll temp[3][3] = {};
		for (int i = 1; i <= 3; i++) {
			temp[1][1] = arr[2][1];
			temp[1][2] = arr[1][1];
			temp[2][2] = arr[1][2];
			temp[2][1] = arr[2][2];

			for (int k = 1; k <= 2; k++) {
				for (int l = 1; l <= 2; l++) {
					arr[k][l] = temp[k][l];
				}
			}

			if (arr[1][1] < arr[1][2] && arr[1][1] < arr[2][1] && arr[2][1] < arr[2][2] && arr[1][2] < arr[2][2]) {
				flag = 1;
			}
		}

		if (flag) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}
