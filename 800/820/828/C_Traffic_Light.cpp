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
		int n, result = 0, cur;
		char rgb;
		string ch;
		cin >> n >> rgb;
		cin >> ch;

		if (rgb == 'g') {
			cout << 0 << "\n";
			continue;
		}

		for (int i = 0; i < n; i++) {
			if (ch[i] != rgb) {
				continue;
			}
			cur = i;
			int cnt = 0;
			while (1) {
				if (ch[cur] == 'g') {
					result = max(result, cnt);
					i += cnt;
					break;
				}
				else {
					if (cur == n - 1) {
						cur = 0;
					}
					else {
						cur++;
					}
					cnt++;
				}
			}
		}
		cout << result << "\n";
	}

	return 0;
}
