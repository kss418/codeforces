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
const int MAX = 1;
vector <int> arr;



int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		cin >> n;
		arr.clear();
		ll a = 0, b = 0, en = 0;

		for (int i = 0; i <= 30; i++) {
			if (n < (1 << i)) {
				en = i - 1;
				break;
			}

			if (n & (1 << i)) {
				a |= (1 << i);
			}
		}

		if ((2 * n - a) % 2 == 1) {
			cout << -1 << "\n";
			continue;
		}

		ll x = (2 * n - a) / 2;
		if (((n + x) ^ (n - x)) != n) {
			cout << -1 << "\n";
			continue;
		}

		cout << n + x << " " << n - x << "\n";
	}


	return 0;
}
