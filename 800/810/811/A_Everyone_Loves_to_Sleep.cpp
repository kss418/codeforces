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
ll arr[MAX];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		ll result = 1e9;
		cin >> n >> m >> k;
		for (int i = 1; i <= n; i++) {
			ll ho, mi;
			cin >> ho >> mi;
			result = min(result, (ho * 60 + mi - m * 60 - k + 1440) % 1440);
		}

		cout << result / 60 << " " << result % 60 << "\n";
	}

	return 0;
}
