#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101;
constexpr ll MOD = 1e9 + 7;
ll arr[MAX], cnt[MAX];

int main() {
    fastio;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;

        ll cur = k % 2;
        for (int i = 1; i < k; i++) {
            if (cur % 2) cout << 1 << " ";
            else cout << -1 << " ";
            cur++;
        }
        for (int i = k; i <= m; i++) cout << 1 << " ";
        cur = 1;
        for (int i = m + 1; i <= n; i++) {
            if (cur % 2) cout << -1 << " ";
            else cout << 1 << " ";
            cur++;
        }
        cout << "\n";
    }


    return 0;
}
