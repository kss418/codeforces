#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string ch;
		cin >> ch;
		int cnt = 0;
		for (int i = 0; i < ch.size(); i++) {
			if (ch[i] == 'Q') {
				cnt++;
			}
			else {
				if (cnt > 0) {
					cnt--;
				}
			}
		}

		if (cnt <= 0) {
			cout << "Yes" << "\n";
		}
		else {
			cout << "No" << "\n";
		}
	}

	return 0;
}
