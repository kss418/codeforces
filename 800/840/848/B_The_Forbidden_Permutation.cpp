#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>
#include <string>
#include <map>
using namespace std; typedef long long ll;
typedef pair <int, int> pi; typedef pair <ll, ll> pll;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 101010;
ll arr[MAX], pos[MAX], num[MAX];



int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			num[arr[i]] = i;
		}

		for (int i = 1; i <= m; i++) cin >> pos[i];

		ll result = INF;
		for (int i = 1; i < m; i++) {
			if (k < n - 1) {
				result = min(result, max(k + num[pos[i]] - num[pos[i + 1]] + 1, 0ll));
			}
			result = min(result, max(num[pos[i + 1]] - num[pos[i]], 0ll));
		}

		cout << result << "\n";
	}

	return 0;
}
