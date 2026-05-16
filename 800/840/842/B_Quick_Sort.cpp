#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;
ll n, m, k; string s;

const int MAX = 101010;
int arr[MAX];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        ll result;
        int seq = 1;
        int num;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            if (arr[i] == seq) {
                seq++;
            }
        }
        seq--;

        result = (n - seq) / m;
        if ((n - seq) % m != 0) {
            result++;
        }

        if (seq == n) {
            result = 0;
        }

        cout << result << "\n";
    }


    return 0;
}
