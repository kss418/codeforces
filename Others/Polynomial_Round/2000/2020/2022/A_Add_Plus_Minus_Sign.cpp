#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string ch;
		cin >> ch;
		int cur = ch[0] - '0';

		for (int i = 1; i < n; i++) {
			if (ch[i] == '0') {
				cout << "+";
			}
			else {
				if (cur == 1) {
					cout << "-";
					cur = 0;
				}
				else {
					cout << "+";
					cur = 1;
				}
			}
		}
		cout << "\n";
	}


	return 0;
}

