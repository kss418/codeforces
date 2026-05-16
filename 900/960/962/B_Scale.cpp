#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 1010;
string st[MAX];

int main()
{
    fastio;

    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> st[i];
        for (int i = 1; i <= n; i += m) {
            for (int j = 0; j < n; j += m) cout << st[i][j];
            cout << "\n";
        }
    }


    return 0;
}
