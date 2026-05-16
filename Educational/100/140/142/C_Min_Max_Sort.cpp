#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
using namespace std; typedef long long ll;
typedef pair <int, int> pi; typedef pair <ll, ll> pll;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 201010;
int arr[MAX], use[MAX];



int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		cin >> n;

		int result = 0;
		memset(use, 0, sizeof(use));
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];

			if (use[arr[i] - 1]) {
				use[arr[i]] = use[arr[i] - 1];
			}
			else {
				use[arr[i]] = arr[i];
			}
		}

		for (int i = n; i >= n / 2; i--) {
			if (use[i] <= n - i + 1) {
				break;
			}
			result++;
		}


		cout << result << '\n';
	}

	return 0;
}
