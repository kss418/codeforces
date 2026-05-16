#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		int m = max({ a,b,c });
		int n = min({ a,b,c });
		for (auto i : { a,b,c }) {
			if (i != m && i != n) {
				cout << i << "\n";
			}
		}
	}
	
	
	return 0;
}
