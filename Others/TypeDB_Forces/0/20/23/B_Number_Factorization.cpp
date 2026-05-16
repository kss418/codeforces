#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <stack>
using namespace std; typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, ll> pll;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 10;
vector <ll> prime;
ll arr[50];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		prime.clear();
		cin >> n;

		int cur = n;
		while (cur != 1) {
			int flag = 0;
			for (int i = 2; i * i <= n; i++) {
				if (cur % i == 0) {
					cur /= i;
					flag = 1;
					prime.push_back(i);
					break;
				}
			}

			if (!flag) {
				prime.push_back(cur);
				cur = 1;
			}
		}

		int cnt = 1;
		memset(arr, 0, sizeof(arr));
		for (int i = 0; i < prime.size() - 1; i++) {
			if (prime[i] == prime[i + 1]) {
				cnt++;
			}
			else {
				for (int j = 1; j <= cnt; j++) {
					if (!arr[j]) {
						arr[j] = 1;
					}

					arr[j] *= prime[i];
				}
				cnt = 1;
			}
		}

		for (int j = 1; j <= cnt; j++) {
			if (!arr[j]) {
				arr[j] = 1;
			}

			arr[j] *= prime.back();
		}

		ll result = 0;
		cur = 0;
		for (int i = 1; i < 50; i++) {
			if (arr[i] != arr[i + 1]) {
				result += (i - cur) * arr[i];
				cur = i;
			}
		}

		cout << result << "\n";
	}



	return 0;
}
