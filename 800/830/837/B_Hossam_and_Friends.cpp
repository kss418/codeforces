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
const int MAX = 201010;
ll arr[MAX];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		cin >> n >> m;
		memset(arr, 0x3f, sizeof(arr));

		while (m--) {
			ll st, en;
			cin >> st >> en;
			if (st > en) {
				swap(st, en);
			}
			arr[st] = min(arr[st], en);
		}

		for (int i = n - 1; i >= 1; i--) {
			arr[i] = min(arr[i + 1], arr[i]);
		}

		ll result = 0;
		for (int i = 1; i <= n; i++) {
			if (arr[i] != INF) {
				result += arr[i] - i;
			}
			else {
				result += n - i + 1;
			}
		}


		cout << result << "\n";

	}
	return 0;
}
