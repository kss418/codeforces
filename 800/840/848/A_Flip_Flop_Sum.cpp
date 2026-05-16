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
ll arr[MAX];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);


	cin >> t;
	while (t--) {
		cin >> n;
		int flag1 = 0, flag2 = 0;
		ll sum = 0;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			sum += arr[i];
			if (arr[i] == -1 && arr[i - 1] == -1) {
				flag1 = 1;
			}

			if (arr[i] == -1) {
				flag2 = 1;
			}
		}

		if (flag1) {
			cout << sum + 4;
		}
		else if (flag2) {
			cout << sum;
		}
		else {
			cout << sum - 4;
		}
		cout << "\n";
	}

	return 0;
}
