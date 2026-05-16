#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>
#include <map>
using namespace std; typedef long long ll;
typedef pair <int, int> pi; typedef pair <ll, ll> pll;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 110;
ll num[MAX][MAX], indegree[MAX];
set <ll> arr[MAX];
deque <ll> q;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			arr[i].clear();
		}
		memset(indegree, 0, sizeof(indegree));

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j < n; j++) {
				cin >> num[i][j];
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 2; j < n; j++) {
				if (!arr[num[i][j - 1]].count(num[i][j])) {
					arr[num[i][j - 1]].insert(num[i][j]);
					indegree[num[i][j]]++;
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			if (!indegree[i]) {
				q.push_back(i);
			}
		}

		while (!q.empty()) {
			ll cur = q.front();
			q.pop_front();
			cout << cur << " ";

			for (auto nxt : arr[cur]) {
				indegree[nxt]--;
				if (!indegree[nxt]) {
					q.push_back(nxt);
				}
			}
		}

		cout << "\n";
	}


	return 0;
}
