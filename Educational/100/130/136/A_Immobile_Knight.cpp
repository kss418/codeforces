#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
vector <tuple <double, int, int>> arr;


bool cmp(tuple<double, int, int> i, tuple<double, int, int> j) {
	double cmp1, cmp2;
	int a1, a2, b1, b2;
	tie(cmp1, a1, b1) = i;
	tie(cmp2, a2, b2) = j;
	if (cmp1 == cmp2) {
		return a1 > a2;
	}
	else {
		return cmp1 < cmp2;
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		if (a <= 3 && b <= 3) {
			cout << (int)((a + 1) / 2) << " " << (int)((b + 1) / 2) << "\n";
		}
		else if (a == 1 || b == 1) {
			cout << a << " " << b << "\n";
		}
		else {
			cout << a << " " << b << "\n";
		}

	}

	return 0;
}
