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
ll x[4], y[4];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		int cnt1 = 0, cnt2 = 0;
		for (int i = 1; i <= 3; i++) {
			cin >> x[i] >> y[i];
		}

		if (x[1] != x[2] && x[2] != x[3] && x[3] != x[1]) {
			cout << "YES\n";
		}
		else if (y[1] != y[2] && y[2] != y[3] && y[3] != y[1]) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}


	}


	return 0;
}
