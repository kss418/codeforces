#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector <int> arr;



int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	while (n--) {
		int num, cur;
		arr.clear();
		cin >> num;
		for (int i = 0; i < num; i++) {
			cin >> cur;
			arr.push_back(cur);
		}
		sort(arr.begin(), arr.end());

		bool flag = 1;
		int prev = 0;
		for (auto i : arr) {
			cur = i;
			if (prev == cur) {
				cout << "NO" << "\n";
				flag = 0;
				break;
			}
			prev = i;
		}
		if (flag) {
			cout << "YES" << "\n";
		}
	}

	
	
	

	
	return 0;
}
