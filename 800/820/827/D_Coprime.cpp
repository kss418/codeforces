#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
using namespace std;
typedef long long ll;
ll n, m, k, t; string s;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 201010;
int arr[MAX], num[MAX];

int gcd(int a, int b) {
	while (b) {
		int mod = a % b;
		a = b;
		b = mod;
	}

	return a;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	

	cin >> t;
	while (t--) {
		cin >> n;
		memset(num, 0, sizeof(num));
		memset(arr, 0, sizeof(arr));

		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			num[arr[i]] = i;
		}

		int result = -1;
		for (int i = 1; i <= 1000; i++) {
			for (int j = 1; j <= 1000; j++) {
				if (gcd(i,j) == 1 && num[j] != 0 && num[i] != 0) {
					result = max(result, num[i] + num[j]);
				}
			}
		}

		cout << result << "\n";
	}


	return 0;
}
