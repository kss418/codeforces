#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>
#include <string>
#include <map>
using namespace std; typedef long long ll;
typedef pair <int, int> pi; typedef pair <ll, ll> pll;
ll n, m, k, t; string s;


const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 201010;
ll arr[MAX];


int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		cin >> n;
		int flag1 = 0, flag2 = 0, flag3 = 0;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			ll mod = arr[i] % 10;
			if (mod == 5 || mod == 0) {
				flag3 = 1;
			}

			if ((arr[i] / 10ll) % 2 == 0) {
				if (mod == 2 || mod == 4 || mod == 8 || mod == 1) {
					flag1 = 1;
				}

				if(mod == 3 || mod == 6 || mod == 7 || mod == 9) {
					flag2 = 1;
				}
			}
			else {
				if (mod == 2 || mod == 4 || mod == 8 || mod == 1) {
					flag2 = 1;
				}

				if (mod == 3 || mod == 6 || mod == 7 || mod == 9) {
					flag1 = 1;
				}
			}
		}


		int cnt = flag1 + flag2 + flag3;
		if (cnt != 1) {
			cout << "No\n";
			continue;
		}

		if(flag3){
			int flag = 1;
			int pre = 0, cur = 0;
			for (int i = 2; i <= n; i++) {
				if (arr[i] % 10 == 0) {
					cur = arr[i] / 10;
				}
				else {
					cur = arr[i] / 10 + 1;
				}

				if (arr[i - 1] % 10 == 0) {
					pre = arr[i - 1] / 10;
				}
				else {
					pre = arr[i - 1] / 10 + 1;
				}

				if(pre != cur){
					flag = 0;
					break;
				}
			}

			if (!flag) {
				cout << "No\n";
				continue;
			}
		}

		cout << "Yes\n";
	}

	return 0;
}
