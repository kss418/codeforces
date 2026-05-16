#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int visit[200001][2];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	ll t;
	cin >> t;

	while (t--) {
		ll n;
		cin >> n;
		string arr1, arr2;
		cin >> arr1 >> arr2;
		int x = -1;
		int y = -1;
		int cnt = 0;
		fill(&visit[0][0], &visit[n - 1][2], 0);

		for (int i = 0; i < n; i++) {
			if (arr1[i] == 'B') {
				cnt++;
			}
			if (arr2[i] == 'B') {
				cnt++;
			}
		}

		int count = 0;
		int flag1 = 0;
		if (arr1[0] == 'B') {
			x = 0;
			y = 0;
			while (1) {
				if (visit[x][y] == 1) {
					break;
				}
				visit[x][y] = 1;
				count++;

				if (cnt == count) {
					cout << "YES" << "\n";
					flag1 = 1;
					break;
				}

				if (y == 0) {
					if (arr2[x] == 'B' && visit[x][1] != 1) {
						y = 1;
					}
					else if (x < n - 1 && arr1[x + 1] == 'B' && visit[x + 1][y] != 1) {
						x++;
					}
					else {
						break;
					}
				}
				else {
					if (arr1[x] == 'B' && visit[x][0] != 1) {
						y = 0;
					}
					else if (x < n - 1 && arr2[x + 1] == 'B' && visit[x + 1][y] != 1) {
						x++;
					}
					else {
						break;
					}
				}
			}
		}

		if (flag1 == 1) {
			continue;
		}

		fill(&visit[0][0], &visit[n - 1][2], 0);
		count = 0;
		if (arr2[0] == 'B') {
			x = 0;
			y = 1;
			while (1) {
				if (visit[x][y] == 1) {
					cout << "NO" << "\n";
					break;
				}
				visit[x][y] = 1;
				count++;

				if (cnt == count) {
					cout << "YES" << "\n";
					break;
				}

				if (y == 0) {
					if (arr2[x] == 'B' && visit[x][1] != 1) {
						y = 1;
					}
					else if (x < n - 1 && arr1[x + 1] == 'B' && visit[x + 1][y] != 1) {
						x++;
					}
					else {
						cout << "NO" << "\n";
						break;
					}
				}
				else {
					if (arr1[x] == 'B' && visit[x][0] != 1) {
						y = 0;
					}
					else if (x < n - 1 && arr2[x + 1] == 'B' && visit[x + 1][y] != 1) {
						x++;
					}
					else {
						cout << "NO" << "\n";
						break;
					}
				}
			}
		}
		else {
			cout << "NO" << "\n";
		}


	}






	return 0;
}
