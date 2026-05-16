#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 2) {
            cout << 2 << " " << 1 << "\n";
        }
        else if (n == 3) {
            cout << -1 << "\n";
        }
        else {
            cout << n << " " << n - 1 << " ";
            for (int i = 1; i <= n - 2; i++) {
                cout << i << " ";
            }
            cout << "\n";
        }
    }




    return 0;
}
