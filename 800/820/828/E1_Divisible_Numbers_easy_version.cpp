#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
	while (b != 0) {
		ll temp = a % b;
		a = b;
		b = temp;
	}

	return a;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);




	ll t;
	cin >> t;
	while (t--) {
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		ll mul = a * b;
		pair <ll, ll> result;

		bool flag = false;
		for (ll i = a + 1; i <= c; i++) {
			ll cur = mul / gcd(i, mul);
			ll se = b;
			se += cur - se % cur;

			for (ll j = se; j <= d; j += cur) {
				result = { i,j };
                 flag = true;
				break;
			}

			if (flag) {
				break;
			}
		}

		if (flag) {
			cout << result.first << " " << result.second << "\n";
		}
		else {
			cout << -1 << " " << -1 << "\n";
		}
	}


	return 0;
}
