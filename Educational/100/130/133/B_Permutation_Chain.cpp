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

    int t, temp;
    int arr[101];
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << n << "\n";
        for (int i = 1; i <= n; i++) {
            arr[i] = i;
            cout << arr[i] << " ";
        }
        cout << "\n";

        temp = arr[1];
        arr[1] = arr[2];
        arr[2] = temp;

        for (int i = 1; i <= n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";

        for (int i = 3; i <= n; i++) {
            temp = arr[2];
            arr[2] = arr[i];
            arr[i] = temp;



            for (int j = 1; j <= n; j++) {
                cout << arr[j] << " ";
            }
            cout << "\n";
        }

    }

    return 0;
}
