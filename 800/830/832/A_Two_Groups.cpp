#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	ll t;
	cin >> t;
	while (t--) {
		ll n, num;
		ll arr[100001];
		arr[0] = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> num;
			arr[i] = arr[i - 1] + num;
		}

		ll result = 0;
		for (int i = 0; i <= n; i++) {
			result = max(abs(arr[n] - arr[i]) - abs(arr[i]), result);
		}

		cout << result << "\n";
	}

	return 0;
}
