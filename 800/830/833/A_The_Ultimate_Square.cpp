#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int num;
		cin >> num;
		if (num % 2 == 0) {
			cout << num / 2 << "\n";
		}
		else {
			cout << (num + 1) / 2 << "\n";
		}
	}




	return 0;
}
