#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp1(pair <int, int> i, pair<int, int> j) {
	if (i.first < j.first) {
		return true;
	}
	else if (i.first == j.first) {
		return i.second < j.second;
	}
	else {
		return false;
	}
}

bool cmp2(pair <int, int> i, pair<int, int> j) {
	if (i.first > j.first) {
		return true;
	}
	else if (i.first == j.first) {
		return i.second < j.second;
	}
	else {
		return false;
	}
}


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		string ch;
		vector <pair<int,int>> arr;
		vector <int> track;
		int sum = 0, cnt = 0, prev;
		cin >> ch;
		for (int i = 0; i < ch.size();i++) {
			arr.push_back({ ch[i] - 'a' + 1, i + 1});
		}

		if (arr[0].first > arr[ch.size() - 1].first) {
			sort(arr.begin(), arr.end(),cmp2);
			track.push_back(1);
			prev = ch[0] - 'a' + 1;
			for (auto i : arr) {
				if (i.first <= ch[0] - 'a' + 1 && i.second != 1) {
					sum += abs(prev - i.first);
					cnt++;
					track.push_back(i.second);
					prev = i.first;
					if (i.second == ch.size()) {
						break;
					}
				}
			}
		}
		else {
			sort(arr.begin(), arr.end(),cmp1);
			track.push_back(1);
			prev = ch[0] - 'a' + 1;
			for (auto i : arr) {
				if (i.first >= ch[0] - 'a' + 1 && i.second != 1) {
					sum += abs(i.first - prev);
					cnt++;
					track.push_back(i.second);
					prev = i.first;
					if (i.second == ch.size()) {
						break;
					}
				}
			}
		}

		cout << sum << " " << cnt + 1 << "\n";
		for (auto i : track) {
			cout << i << " ";
		}
		cout << "\n";
	}



	return 0;
}
