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
		int n;
		cin >> n;
		string ch;
		cin >> ch;
		int m = 0;
		for (auto i : ch) {
			m = max(i - 'a' + 1, m);
		}
		cout << m << "\n";
	}
	
	
	return 0;
}
