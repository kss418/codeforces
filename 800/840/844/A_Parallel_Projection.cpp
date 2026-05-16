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
const int MAX = 1010101;
ll arr[MAX];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		ll x, y, z;
		cin >> x >> y >> z;
		ll x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		ll result = z + min(abs(x2 - x1) + min(y1 + y2, 2 * y - (y1 + y2)), abs(y2 - y1) + min(x1 + x2, 2 * x - (x1 + x2)));
		cout << result << "\n";
	}


	return 0;
}
