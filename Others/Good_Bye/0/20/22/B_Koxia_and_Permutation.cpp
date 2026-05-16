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
priority_queue <ll, vector<ll>, greater<ll>> ch, arr;



int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		cin >> n >> k;
		if (n % 2) {
			cout << n << " ";
			for (int i = 1; i <= n / 2; i++) {
				cout << i << " " << n - i << " ";
			}
		}
		else {
			for (int i = n; i > n / 2; i--) {
				cout << i << " " << n - i + 1 << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}
