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
const int MAX = 1010;
ll arr[MAX];
string p = "314159265358979323846264338327";


int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		cout << m - k << " ";
		int mod = k / (n - 1);
		int moc = k % (n - 1);
		for (int i = 1; i <= moc; i++) {
			cout << mod + 1 << " ";
		}

		for (int i = moc + 1; i < n; i++) {
			cout << mod << " ";
		}

		cout << "\n";
	}


	return 0;
}
