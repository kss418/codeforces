#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
using namespace std;
typedef long long ll;
ll n, m, k, t; string s;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 101010;
ll arr[MAX], sum[MAX], mi = INF;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);


	cin >> t;
	while (t--) {
		cin >> s;
		cout << s[0] - '0' + s[2] - '0' << "\n";


	}
	return 0;
}
