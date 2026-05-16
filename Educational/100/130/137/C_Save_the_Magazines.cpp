#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int n, arr[200001];
		string ch;
		cin >> n;
		cin >> ch;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		int num = 0;
		for (int i = 1; i <= n; i++) {
			if (i < n && ch[i - 1] == '0' && ch[i] == '1' && arr[i - 1] >= arr[i]) {
				ch[i] = '0';
				ch[i - 1] = ' 1';
			}
			else if (ch[i - 1] == '0') {
				int cur = i;
				while (ch[cur] == '1') {
					if (cur >= n) {
						break;
					}
					if (arr[i - 1] >= arr[cur] && cur != i - 1) {
						ch[i - 1] = '1';
						ch[cur] = '0';
						break;
					}
					cur++;
				}
			}


			if (ch[i - 1] == '1') {
				num += arr[i - 1];
			}

		}
		cout << num << "\n";
	}

	return 0;
}
