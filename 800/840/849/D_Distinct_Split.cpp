#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>
#include <string>
#include <map>
using namespace std; typedef long long ll;
typedef pair <int, int> pi; typedef pair <ll, ll> pll;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 201010;
int cnt[MAX][30];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		cin >> n >> s;
		fill(&cnt[0][0], &cnt[n][29], 0);
		cnt[0][s[0] - 'a'] = 1;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j <= 26; j++) {
				if (j == s[i] - 'a') {
					cnt[i][j] = cnt[i - 1][j] + 1;
				}
				else {
					cnt[i][j] = cnt[i - 1][j];
				}
			}
		}

		int result = 0;
		for (int i = 0; i < n - 1; i++) {
			int fi = 0, se = 0;
			for (int j = 0; j <= 26; j++) {
				if (cnt[i][j]) {
					fi++;
				}

				if (cnt[n - 1][j] - cnt[i][j]) {
					se++;
				}
			}

			result = max(result, fi + se);
		}

		cout << result << "\n";
	}

	return 0;
}
