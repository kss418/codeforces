#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int l, r, x, a, b;



int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		cin >> l >> r >> x;
		cin >> a >> b;


		int cnt = 0;
		bool flag = true;
		while (a != b) {
			if (abs(l - a) < x && abs(r - a) < x) {
				flag = false;
				break;
			}
			else if (abs(a - b) >= x) {
				b = a;
			}
			else if (r >= b + x && l <= b - x) {
				if (abs(a - b - x) >= abs(a - b + x)) {
					b = r;
				}
				else {
					b = l;
				}
			}
			else if (r >= b + x) {
				b = r;
			}
			else if (l <= b - x) {
				b = l;
			}
			else {
				flag = false;
				break;
			}
			cnt++;
		}

		if (!flag) {
			cout << -1 << "\n";
		}
		else {
			cout << cnt << "\n";
		}


	}


	return 0;
}
