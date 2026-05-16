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
		int num;
		cin >> num;
		num--;
		int a = 1;
		num -= 2;
		int b = num / 3;
		int c = 2 * num / 3;
		cout << min({ abs(a - b), abs(b - c), abs(a - c) }) << "\n";
	}


	return 0;
}
