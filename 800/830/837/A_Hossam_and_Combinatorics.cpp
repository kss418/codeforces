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
const int MAX = 101010;
ll arr[MAX], cnt[MAX];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		cin >> n;
		memset(cnt, 0, sizeof(cnt));
		ll ma = 0, mi = INF;

		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			cnt[arr[i]]++;
			ma = max(ma, arr[i]);
			mi = min(mi, arr[i]);
		}
		ll diff = ma - mi;

		sort(arr + 1, arr + n + 1);
		ll st = 1, en = n;
		ll result = 0;
		while (st < en) {
			if (arr[en] - arr[st] > diff) {
				en--;
			}
			else if (arr[en] - arr[st] < diff) {
				st++;
			}
			else {
				if (arr[st] == arr[en]) {
					result += (cnt[arr[st]] * (cnt[arr[st]] - 1)) / 2;
					break;
				}
				result += (cnt[arr[st]] * cnt[arr[en]]);
				while (arr[st] == arr[st + 1]) {
					st++;
				}
				st++;

				while (arr[en] == arr[en - 1]) {
					en--;
				}
				en--;
			}
		}

		cout << 2 * result << "\n";
	}


	return 0;
}
