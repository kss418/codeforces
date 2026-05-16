#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int fun(int a, int b) {
	while (b != 0) {
		int temp = a % b;
		a = b;
		b = temp;
	}

	return a;
}

int lcm(int a, int b) {
	return a * b / fun(a,b);
}


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int n, arr[100001];
		int gcd[100001];
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}

		bool flag = true;
		arr[0] = 1;
		arr[n + 1] = 1;
		for (int i = 1; i <= n + 1; i++) {
			gcd[i] = lcm(arr[i], arr[i - 1]);
		}

		for(int i =1 ;i<=n;i++){
			if (fun(gcd[i], gcd[i + 1]) != arr[i]) {
				flag = false;
				break;
			}
		}

		if (flag) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}

	}
	return 0;
}
