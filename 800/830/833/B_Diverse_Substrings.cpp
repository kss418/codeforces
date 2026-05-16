#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int use[10];
int cnt;
int m;
int result;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int n;
		string ch;
		result = 0;
		cin >> n >> ch;
		for (int j = 0; j < ch.size(); j++) {
			for (int i = 0; i <= 100; i++) {
				fill(use, use + 10, 0);
				cnt = 0;
				m = 0;
				if (j + i >= ch.size()) {
					break;
				}

				for (int k = 0; k <= i; k++) {
					use[ch[j + k] - '0']++;
				}


				for (int k = 0; k <= 9; k++) {
					if (use[k] != 0) {
						cnt++;
					}
					m = max(m, use[k]);
				}

				if (m <= cnt) {
					result++;
				}
			}
		}
		cout << result << "\n";
	}




	return 0;
}
