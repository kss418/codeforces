#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
 
 
int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
 
	int t;
	cin >> t;
	while (t--) {
		int n;
		int arr[200001];
		cin >> n;
		int last = -1;
		int first = -1;
		int zero = 0;
 
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			if (arr[i] == 1) {
				last = i;
			}
			else {
				zero++;
				if (first == -1) {
					first = i;
				}
			}
		}
		int usezero = zero;
 
	
 
		long long ret = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] == 0) {
				usezero--;
			}
			else {
				ret += usezero;
			}
		}
		long long result = ret;
 
		if (last != -1) {
			ret = 0;
			usezero = zero;
			arr[last] = 0;
			usezero++;
			for (int i = 0; i < n; i++) {
				if (arr[i] == 0) {
					usezero--;
				}
				else {
					ret += usezero;
				}
			}
			result = max(ret, result);
			arr[last] = 1;
		}
 
		if (first != -1) {
			ret = 0;
			usezero = zero;
			usezero--;
			arr[first] = 1;
			for (int i = 0; i < n; i++) {
				if (arr[i] == 0) {
					usezero--;
				}
				else {
					ret += usezero;
				}
			}
			result = max(ret, result);
		}
 
 
		cout << result << "\n";
	}
 
 
	return 0;
}
 
