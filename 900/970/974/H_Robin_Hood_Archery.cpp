#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first
#define y second
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
ll sum[MAX][100];

int main() {
    fastio;

    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> k;
            for(int j = 0;j < 100;j++) sum[i][j] = sum[i - 1][j] ^ (j * (2 * k - 1));
        }

        while (m--) {
            ll st, en;
            cin >> st >> en;

            ll flag = 0;
            for (int i = 0; i < 100; i++) {
                ll cur = sum[en][i] ^ sum[st - 1][i];
                if (cur) flag = 1;
            }

            if (flag) cout << "NO\n";
            else cout << "YES\n";
        }
    }


    return 0;
}
