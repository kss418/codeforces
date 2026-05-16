#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
ll num[MAX], st[MAX], en[MAX];

int main() {
    fastio;

    cin >> t;
    while (t--) {
        cin >> n >> m >> k;

        memset(st, 0, sizeof(st));
        memset(en, 0, sizeof(en));
        for (int i = 1; i <= k; i++) {
            ll l, r;
            cin >> l >> r;
            st[max<ll>(l - m + 1, 1)]++; en[r]++;
        }

        ll cnt = 0;
        for (int i = 1; i <= n; i++) {
            cnt += st[i]; cnt -= en[i - 1];
            num[i] = cnt;
        }

        ll mn = INF, mx = 0;
        ll mnd = 0, mxd = 0;
        for (int i = 1; i <= n - m + 1; i++) {
            ll cur = num[i];

            if (mn > cur) mn = cur, mnd = i;
            if (mx < cur) mx = cur, mxd = i;
        }

        cout << mxd << " " << mnd << "\n";
    }


    return 0;
}
