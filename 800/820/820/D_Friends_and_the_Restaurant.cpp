#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> diff;
int money[200000], value[200000];




int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int n;
		diff.clear();
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> value[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> money[i];
		}

		for (int i = 0; i < n; i++) {
			diff.push_back(money[i] - value[i]);
		}
		sort(diff.begin(), diff.end());
		int st = 0, en = n - 1;
		int count = 0;
		while (en > st) {
			if (diff[st] + diff[en] >= 0) {
				count++;
				en--;
				st++;
			}
			else {
				st++;
			}
		}
		cout << count << "\n";
	}



	return 0;
}
