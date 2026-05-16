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
typedef pair <int, int> pi; typedef pair <ll, ll> pll;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 10101;
ll arr[MAX];



int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		cin >> n;
		ll cnt = 0;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			if (arr[i] == 1) {
				cnt++;
			}
		}

		cout << n - (int)(cnt / 2) << "\n";
	}

	return 0;
}
