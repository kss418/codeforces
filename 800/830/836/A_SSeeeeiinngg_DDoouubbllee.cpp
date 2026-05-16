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
		string ch;
		cin >> ch;
		cout << ch;
		for (int i = ch.size() - 1; i >= 0; i--) {
			cout << ch[i];
		}
		cout << "\n";
	}


	return 0;
}
