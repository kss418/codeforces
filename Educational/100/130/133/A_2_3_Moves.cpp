#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
typedef long long ll;
using namespace std;


int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int result = 2000000000;

        if (n == 1) {
            cout << 2 << "\n";
            continue;
        }

        if (n % 3 == 0) {
            cout << n / 3 << "\n";
            continue;
        }
        else {
            result = min(result, n / 3 + 1);
        }


        if (n % 2 == 0) {
            result = min(result, n / 2);
        }

        cout << result << "\n";
    }

    return 0;
}
