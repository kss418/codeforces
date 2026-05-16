#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int st, en;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, result = 0;
		multiset <int> orig;
		cin >> n;
		for (int i = 0; i < n;i++) {
			int num;
			cin >> num;
			orig.insert(-num);
		}



		for (int j = 100; j > 0;j--) {
			if (result != 0) {
				break;
			}

			multiset <int> arr;
			for (auto k : orig) {
				arr.insert(k);
			}

			for(int i = 1; i <= j;i++){
				if (arr.size() == 0) {
					break;
				}

				if (arr.lower_bound(-j + i - 1) != arr.end()) {
					arr.erase(arr.lower_bound(-j + i - 1));
					if (arr.size() != 0) {
						auto iter = arr.end();
						iter--;
						int cur = *iter - j + i - 1;
						arr.erase(iter);
						arr.insert(cur);
					}
				}
				else {
					break;
				}

				if (i == j) {
					result = j;
				}
			}
		}

		cout << result << "\n";
	}


	return 0;
}
