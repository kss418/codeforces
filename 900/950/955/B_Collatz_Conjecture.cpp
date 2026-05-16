#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 1010101;
constexpr ll MOD = 1e9 + 7;


int main() {
    fastio;

    cin >> t;
    while (t--) {
        cin >> n >> m >> k;

        while (n != 1 && k) {
            ll mod = n % m;
            n += min(k, m - mod);
            k -= min(k, m - mod);

            while (n % m == 0) n /= m;
        }

        ll mod = n % m;

        if (k < m - mod) cout << n + k << '\n';
        else if ((n + k) % (m - 1) == 0) cout << m - 1 << "\n";
        else cout << (n + k) % (m - 1) << "\n";
    }


    return 0;
}
