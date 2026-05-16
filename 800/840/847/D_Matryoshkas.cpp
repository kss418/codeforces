#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>
#include <map>
using namespace std; typedef long long ll;
typedef pair <int, int> pi; typedef pair <ll, ll> pll;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 201010;
multiset <ll> arr;



int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			ll num;
			cin >> num;
			arr.insert(num);
		}

		ll result = 0;
		while (!arr.empty()) {
			result++;
			ll cur = *arr.lower_bound(0);
			arr.erase(arr.lower_bound(0));

			while (1) {
				if (arr.count(cur + 1)) {
					arr.erase(arr.lower_bound(cur + 1));
					cur++;
				}
				else {
					break;
				}
			}
;		}

		cout << result << "\n";
	}


	return 0;
}
