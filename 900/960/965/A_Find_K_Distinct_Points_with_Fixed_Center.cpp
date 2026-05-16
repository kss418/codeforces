#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101010;
constexpr ll MOD = 1e9 + 7;


int main()
{
    fastio;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        if (k % 2) {
            cout << n << " " << m << "\n";
            for (int i = 1; i <= k / 2; i++) {
                cout << n + i << " " << m + i << "\n";
                cout << n - i << " " << m - i << "\n";
            }
        }
        else {
            for (int i = 1; i <= k / 2; i++) {
                cout << n + i << " " << m + i << "\n";
                cout << n - i << " " << m - i << "\n";
            }
        }
    }



    return 0;
}
