#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;



int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);


	ll t;
	cin >> t;
	while (t--) {
		ll a, b;
		ll two = 0;
		ll five = 0;
		ll cur = 1;

		cin >> a >> b;
		ll first = a;
		while (a % 2 == 0) {
			two++;
			a /= 2;
		}

		while (a % 5 == 0) {
			five++;
			a /= 5;
		}



         if (five > two) {
			while (b >= cur * 2) {
				cur *= 2;
				two++;
				if (two == five) {
					break;
				}
			}
		}

		else if (two > five) {
			while (b >= cur * 5) {
				cur *= 5;
				five++;
				if (two == five) {
					break;
				}
			}
		}

		while (b >= cur * 10) {
			cur *= 10;
		}

		for (ll i = 9; i >= 1; i--) {
			if (b >= cur * i) {
				cur *= i;
				break;
			}
		}

		cout << first * cur << "\n";
	}


	return 0;
}
