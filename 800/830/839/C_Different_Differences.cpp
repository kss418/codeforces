#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
using namespace std;
typedef long long ll;
ll n, m, k, t; string s;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 101010;
ll arr[3][3];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);


	cin >> t;
	while (t--) {
		cin >> n >> m;
		int cur = 1;
		int diff = 0;
		cout << cur << " ";
		for (int i = 2; i <= n; i++) {
			if (m - cur - diff > n - i) {
				diff++;
				cur += diff;
			}
			else {
				cur++;
			}
			cout << cur << " ";
		}
		cout << "\n";
	}
	return 0;
}
