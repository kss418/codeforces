#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int n, arr[1000];
		string ch;
		bool flag = true;
		char al[1000];
		fill(al, al + 1000, '0');
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		cin >> ch;
		for (int i = 0; i < ch.size(); i++) {
			if (al[arr[i]] == '0') {
				al[arr[i]] = ch[i];
			}
			else {
				if (al[arr[i]] == ch[i]) {
					continue;
				}
				else {
					cout << "NO" << "\n";
					flag = false;
					break;
				}
			}
		}

		if (flag) {
			cout << "YES" << "\n";
		}
	}

	return 0;
}
