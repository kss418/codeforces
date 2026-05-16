#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101010;
constexpr ll MOD = 1e9 + 7;
ll arr[MAX], mx, result[MAX];

int main() {
    fastio;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        mx = 0;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            mx = max(mx, arr[i]);
        }

        for(int i =1;i<=m;i++) {
            char c; ll l, r;
            cin >> c >> l >> r;
            if (mx < l || mx > r) {
                result[i] = mx;
                continue;
            }
            if (c == '+') mx++;
            else mx--;

            result[i] = mx;
        }

        for (int i = 1; i <= m; i++) cout << result[i] << " ";
        cout << "\n";
    }



    return 0;
}
