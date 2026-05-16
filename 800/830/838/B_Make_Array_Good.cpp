#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	ll n;
	cin >> n;
	while (n--) {
		ll num;
		vector < pair <ll, ll >> arr;
		cin >> num;
		for (int i = 0; i < num; i++) {
			ll t;
			cin >> t;
			arr.push_back({ t ,i + 1 });
		}
		sort(arr.begin(), arr.end());
		ll m = arr[0].first;

		cout << num << "\n";
		for (int i = 0; i < num; i++) {
			cout << arr[i].second << " " << (m - arr[i].first % m) % m << "\n";
			arr[i].first += (m - arr[i].first % m) % m;
			m = max(arr[i].first, m);
		}
	}



	return 0;
}
