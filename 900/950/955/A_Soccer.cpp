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
        ll a, b;
        cin >> a >> b;
        ll c, d;
        cin >> c >> d;
        if (a > b && d > c) cout << "NO\n";
        else if (b > a && c > d) cout << "NO\n";
        else cout << "YES\n";
    }


    return 0;
}
