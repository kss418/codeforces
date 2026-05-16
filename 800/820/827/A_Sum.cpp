#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;




int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	int a, b, c;
	while (n--) {
		cin >> a >> b >> c;
		if (c >= a && c >= b) {
			if (c == a + b) {
				cout << "YES" << "\n";
			}
			else {
				cout << "NO" << "\n";
			}
		}
		else if (b >= a && b >= c) {
			if (b == a + c) {
				cout << "YES" << "\n";
			}
			else {
				cout << "NO" << "\n";
			}
		}
		else {
			if (a == b + c) {
				cout << "YES" << "\n";
			}
			else {
				cout << "NO" << "\n";
			}
		}
	}
	
	

	
	return 0;
}
