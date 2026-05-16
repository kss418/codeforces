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
		bool flag = true;
		string ch;
		cin >> ch;
		if (ch.size() == 1) {
			if (ch[0] == 'Y' || ch[0] == 'e' || ch[0] == 's') {
				flag = true;
			}
			else {
				flag = false;
			}
		}

		for (int i = 1; i < ch.size();i++) {
			if (ch[i - 1] == 'Y' && ch[i] == 'e') {
				continue;
			}
			else if (ch[i - 1] == 'e' && ch[i] == 's') {
				continue;
			}
			else if (ch[i - 1] == 's' && ch[i] == 'Y') {
				continue;
			}
			else {
				flag = false;
			}
		}

		if (flag) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}
	}


	return 0;
}
