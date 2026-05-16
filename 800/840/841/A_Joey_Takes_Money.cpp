#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		ll sum = 1;
		for (int i = 1; i <= n; i++) {
			ll num;
			cin >> num;
			sum *= num;
		}
		sum += n - 1;



		cout << sum * 2022 << "\n";
	}



	return 0;
}
