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
const int MAX = 101010;
ll arr[MAX];
vector <ll> odd, even, result;



int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		cin >> n;
		odd.clear();
		even.clear();
		result.clear();
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			if (arr[i] % 2) {
				odd.push_back(i);
			}
			else {
				even.push_back(i);
			}
		}

		if (odd.size() >= 3 || (even.size() >= 2 && odd.size() >= 1)) {
			cout << "YES\n";
			if (odd.size() >= 3) {
				for (int i = 0; i < 3; i++) {
					cout << odd[i] << " ";
				}
			}
			else {
				cout << even[0] << " " << even[1] << " " << odd[0];
			}
			cout << "\n";
		}
		else {
			cout << "NO\n";
		}
	}


	return 0;
}
