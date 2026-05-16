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
const int MAX = 22;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		cin >> n >> s;
		ll result = n;
		for (int i = 1; i <= n / 2; i++) {
			if (s[i - 1] != s[n - i]) {
				result -= 2;
			}
			else {
				break;
			}
		}

		cout << result << "\n";
	}

	return 0;
}
