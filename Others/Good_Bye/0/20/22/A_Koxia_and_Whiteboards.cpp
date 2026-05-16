#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <stack>
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 110;
ll ch[MAX];
priority_queue <ll, vector<ll>, greater<ll>> arr;



int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			ll num;
			cin >> num;
			arr.push(num);
		}

		for (int i = 1; i <= m; i++) {
			cin >> ch[i];
		}

		for (int i = 1; i <= m;i++) {;
			arr.pop();
			arr.push(ch[i]);
		}

		ll sum = 0;
		while (!arr.empty()) {
			sum += arr.top();
			arr.pop();
		}

		cout << sum << "\n";
	}

	return 0;
}
