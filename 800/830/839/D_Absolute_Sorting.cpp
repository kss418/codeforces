#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 201010;
ll arr[MAX];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}

		ll mn = 0, mx = 1e9;
		for (int i = 1; i < n; i++) {
			if (arr[i] < arr[i + 1]) {
				mx = min(mx, (arr[i] + arr[i + 1]) / 2);
			}

			if (arr[i] > arr[i + 1]) {
				mn = max(mn, (arr[i] + arr[i + 1] + 1) / 2);
			}
		}

		if (mn <= mx) {
			cout << mn << "\n";
		}
		else {
			cout << -1 << "\n";
		}
	}



	return 0;
}
