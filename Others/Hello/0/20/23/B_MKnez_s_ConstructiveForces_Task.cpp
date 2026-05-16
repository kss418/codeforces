#include <iostream>
#include <algorithm>
#include <vector>
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
        if (n == 3) {
            cout << "No" << "\n";
            continue;
        }
        
        cout << "YES" << "\n";
        if (n % 2) {
            n--;
            int cur = n / 2;
            for (int i = 1; i <= cur; i++) {
                cout << cur - 1 << " " << -cur << " ";
            }
            cout << cur - 1 << "\n";
 
        }
        else {
            for (int i = 1; i <= n; i++) {
                if (i % 2) {
                    cout << 1 << " ";
                }
                else {
                    cout << -1 << " ";
                }
            }
            cout << "\n";
        }
 
 
    }
    
 
 
 
   
    return 0;
}
