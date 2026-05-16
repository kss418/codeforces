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
const int MAX = 101010;
const ll MOD = 1e9 + 7;
int arr[MAX];
ll dp[MAX], sum[MAX];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		cin >> n;
		dp[0] = 1;
		sum[0] = 0;
		for (int i = 1; i <= n; i++) {
			dp[i] = (dp[i - 1] % MOD * i) % MOD;
			sum[i] = (sum[i - 1] % MOD + 2 * (i - 1)) % MOD;
		}

		cout << (dp[n] % MOD * sum[n] % MOD) % MOD << "\n";
	}



	return 0;
}
