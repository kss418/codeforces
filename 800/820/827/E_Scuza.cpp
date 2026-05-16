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
const int MAX = 201010;
ll arr[MAX], sum[MAX], ned[MAX];
ll ma;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	

	cin >> t;
	while (t--) {
		cin >> n >> m;
		ma = 0;

		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			ma = max(arr[i], ma);
			ned[i] = ma;
			sum[i] = sum[i - 1] + arr[i];
		}


		while (m--) {
			int num;
			cin >> num;
			int st = 0, en = n;
			while (st < en) {
				int mid = (st + en + 1) / 2;
				if (num >= ned[mid]) {
					st = mid;
				}
				else {
					en = mid - 1;
				}
			}

			cout << sum[en] << " ";
		}
		cout << "\n";
	}


	return 0;
}
