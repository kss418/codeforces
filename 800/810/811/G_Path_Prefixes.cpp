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
vector <ll> arr[MAX];
ll a[MAX], b[MAX], result[MAX];
ll sa[MAX], sb[MAX], dp[MAX], depth[MAX];
vector <ll> num;

ll bound(ll n) {
	ll st = 1, en = num.size();
	if (en == 0) {
		return 0;
	}
	else if (num[0] > n) {
		return 0;
	}

	while (st < en) {
		int mid = (st + en + 1) / 2;
		if (num[mid - 1] > n) {
			en = mid - 1;
		}
		else {
			st = mid;
		}
	}

	return en;
}

void mk(ll cur, ll p, ll d) {
	sa[cur] = a[cur];
	sb[cur] = b[cur];

	sa[cur] += sa[p];
	sb[cur] += sb[p];
	if (cur != 1) {
		num.push_back(sb[cur]);
	}

	result[cur] = bound(sa[cur]);

	for (auto nxt : arr[cur]) {
		mk(nxt, cur, d + 1);
	}

	if (cur != 1) {
		num.pop_back();
	}
}


int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		cin >> n;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(dp, 0, sizeof(dp));

		for (int i = 1; i <= n; i++) arr[i].clear();
		for (int i = 2; i <= n; i++) {
			ll st, c, v;
			cin >> st >> c >> v;
			arr[st].push_back(i);
			a[i] = c;
			b[i] = v;
		}

		mk(1, 0, 0);

		for (int i = 2; i <= n; i++) cout << result[i] << " ";
		cout << "\n";
	}

	return 0;
}
