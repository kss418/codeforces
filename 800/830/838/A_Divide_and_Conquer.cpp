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
		int arr[51], result = 1000;
		vector <int> odd_even, odd, even;
		ll num;
		cin >> num;
		for (int i = 0; i < num; i++) {
			cin >> arr[i];
			if (arr[i] % 2 == 0) {
				even.push_back(i);
			}
			else {
				odd.push_back(i);
			}
		}

		if (odd.size() % 2 == 0) {
			result = 0;
		}
		else {
			for (auto i : even) {
				int cur = arr[i];
				int cnt = 0;
				while (cur % 2 == 0) {
					cnt++;
					cur /= 2;
				}
				result = min(result, cnt);
			}

			for (auto i : odd) {
				int cur = arr[i];
				int cnt = 0;
				while (cur % 2 == 1) {
					cnt++;
					cur /= 2;
				}
				result = min(result, cnt);
			}
		}
		cout << result << "\n";
	}



	return 0;
}
