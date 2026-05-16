#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long a[61];
long long b[61];
const long long mod = 998244353;
long long triangle[61][61];


void tri() {
	triangle[0][0] = 1;
	for (int i = 1; i <= 60; i++) {
		triangle[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			triangle[i][j] = (triangle[i - 1][j - 1] % mod + triangle[i - 1][j] % mod) % mod;
		}
	}
}



int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	tri();

	for (long long j = 2; j <= 60; j += 2) {
		long long s = j / 2;
		a[j] = (long long)((triangle[j - 1][s] + b[j - 2]) % mod);
		b[j] = (long long)((triangle[j - 1][s] - b[j - 2] - 1 + mod) % mod);
	}

	while (n--) {
		long long num;
		cin >> num;
		cout << a[num] % mod << " " << b[num] % mod << " " << 1 << "\n";
	}

	return 0;
}
