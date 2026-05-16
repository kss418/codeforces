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
		int num;
		int arr[101];
		int diff[101];
		cin >> num;
		for (int i = 0; i < num; i++) {
			cin >> arr[i];
		}

		bool flag = true;
		for (int i = 0; i < num; i++) {
			if (i == 0) {
				diff[i] = arr[i];
			}
			else {
				if (diff[i - 1] >= arr[i] && arr[i] != 0) {
					flag = false;
					break;
				}
				else {
					diff[i] = arr[i] + diff[i - 1];
				}
			}
		}

		if (flag) {
			for (int i = 0; i < num;i++) {
				cout << diff[i] << " ";
			}
			cout << "\n";
		}
		else {
			cout << -1 << "\n";
		}

	}

	return 0;
}
