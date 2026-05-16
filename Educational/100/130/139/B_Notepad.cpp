#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	ll t;
	cin >> t;

	while (t--) {
		ll n;
		cin >> n;
		string ch;
		cin >> ch;

		int flag = 0;
		for (int i = 0; i < ch.size() - 1; i++) {
			for (int j = 0; j < i - 1; j++) {
				if (ch[i] == ch[j]) {
					i++;
					j++;
					if (ch[i] == ch[j]) {
						flag = 1;
						break;
					}
					else {
						i--;
						j--;
					}
				}
			}

			if (flag) {
				break;
			}
		}

		if (flag) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}
	}






	return 0;
}
