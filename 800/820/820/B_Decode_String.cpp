#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		string ch;
		int n, cur, prev;
		char code;
		cin >> n;
		cin >> ch;
		vector <char> arr;
		for (int i = ch.size() - 1; i >= 0;i--) {
			if (ch[i] == '0') {
				cur = ch[i - 2] - '0';
				prev = ch[i - 1] - '0';
				code = (char)(10 * cur + prev + 'a' - 1);
				arr.push_back(code);
				i -= 2;
			}
			else {
				cur = ch[i] - '0';
				code = (char)(cur + 'a' - 1);
				arr.push_back(code);
			}
		}
		reverse(arr.begin(), arr.end());
		for (auto i : arr) {
			cout << i;
		}
		cout << "\n";
	}



	return 0;
}
