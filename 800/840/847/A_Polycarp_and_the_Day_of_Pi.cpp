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
const int MAX = 1010;
ll arr[MAX];
string p = "314159265358979323846264338327";


int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		cin >> s;
		int result = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == p[i]) {
				result++;
			}
			else {
				break;
			}
		}

		cout << result << '\n';
	}


	return 0;
}
