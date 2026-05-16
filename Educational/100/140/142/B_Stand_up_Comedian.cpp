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
const int MAX = 5;
ll arr[MAX], a, b;



int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		for (int i = 1; i <= 4; i++) {
			cin >> arr[i];
		}
		ll result = arr[1];
		a = arr[1];	b = arr[1];

		if (a) {
			ll cur = min(arr[2], arr[3]);
			result += 2 * cur;
			arr[2] -= cur; arr[3] -= cur;
		}

		if (arr[2]) {
			ll cur = min(b, arr[2]);
			result += cur;
			b -= cur;
			a += cur;
			arr[2] -= cur;
		}
		else if (arr[3]) {
			ll cur = min(a, arr[3]);
			result += cur;
			b += cur;
			a -= cur;
			arr[3] -= cur;
		}


		ll cur = min({ a, b,arr[4] });
		result += cur;
		b -= cur;
		a -= cur;
		arr[4] -= cur;
		if (arr[2] || arr[3] || arr[4]) {
			result++;
		}


		cout << result << '\n';
	}

	return 0;
}
