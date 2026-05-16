#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	while (n--) {
		int num, a, b;
		cin >> num >> a >> b;

		if (a == num && b == num) {
			cout << "YES" << "\n";
		}
		else if (a + b <= num - 2) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}


	}
	
	
	return 0;
}
