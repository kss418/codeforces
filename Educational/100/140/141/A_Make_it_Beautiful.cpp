#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;
ll n, m, k, t; string s;

const int MAX = 51;
vector <int> arr;
int a[MAX];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        cin >> n;
        arr.clear();
        for (int i = 1; i <= n; i++) {
            int num;
            cin >> num;
            arr.push_back(num);
        }

        sort(arr.begin(), arr.end());
        reverse(arr.begin(), arr.end());

        int pre = 0;
        int flag = 1;
        int cnt = 0;
        if (arr[0] == arr[n - 1]) {
            flag = 0;
        }

        a[1] = arr[0];
        a[2] = arr[n - 1];
        for (int i = 3; i <= n; i++) {
            a[i] = arr[i - 2];
        }

        if (flag) {
            cout << "YES" << "\n";
            for (int i = 1; i <= n; i++) {
                cout << a[i] << " ";
            }
            cout << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
    }


    return 0;
}
