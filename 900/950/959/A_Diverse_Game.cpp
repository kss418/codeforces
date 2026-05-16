#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 11;
ll arr[MAX * MAX];


int main()
{
    fastio;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) cin >> arr[m * (i - 1) + j];
        }

        if (n == 1 && m == 1) {
            cout << -1 << "\n";
            continue;
        }

        cout << arr[m * n];
        if (m == 1) cout << "\n";
        else cout << " ";

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << arr[m * (i - 1) + j] << " ";
            }
            cout << "\n";
        }

        for (int j = 1; j < m; j++) cout << arr[m * (n - 1) + j] << " ";
        cout << "\n";
    }


    return 0;
}
