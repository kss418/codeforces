#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector <int> arr;



int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	char arr[8][8];
	cin >> n;
	while (n--) {
		string ch;
		for (int i = 0; i < 8; i++) {
			cin >> ch;
			for (int j = 0; j < 8; j++) {
				arr[i][j] = ch[j];
			}
		}

		int count = 0;
		for (int i = 0; i < 8; i++) {
			count = 0;
			for (int j = 0; j < 8; j++) {
				if(arr[i][j] == 'R') {
					count--;
				}
			}
			if (count == -8) {
				cout << 'R' << "\n";
				break;
			}
		}

		for (int i = 0; i < 8; i++) {
			count = 0;
			for (int j = 0; j < 8; j++) {
				if (arr[j][i] == 'B') {
					count++;
				}
			}
			if (count == 8) {
				cout << 'B' << "\n";
				break;
			}
		}
	}





	return 0;
}
