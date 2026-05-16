#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll dp[1000000];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	ll t;
	cin >> t;
	for (int i = 1; i < 1000000; i++) {
		int cur = i;
		while (cur % 10 == 0) {
			cur /= 10;
		}
		if (cur < 10) {
			dp[i] = dp[i - 1] + 1;
		}

		else {
			dp[i] = dp[i - 1];
		}
	}

	while (t--) {
		ll n;
		cin >> n;
		cout << dp[n] << "\n";
	}






	return 0;
}
