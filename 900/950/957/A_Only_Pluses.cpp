#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 1e9 + 7;


int main() {
    fastio;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        ll cnt = 5;
        while (cnt--) {
            if (n <= m && n <= k)n++;
            else if (m <= n && m <= k) m++;
            else k++;
        }

        cout << n * m * k << '\n';
    }


    return 0;
}
