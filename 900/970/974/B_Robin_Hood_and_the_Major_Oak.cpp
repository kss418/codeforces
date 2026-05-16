#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 998244353;
ll arr[MAX];

int main() {
    fastio;

    cin >> t;
    while (t--) {
        cin >> n >> m;
        ll sum = 0;
        sum += n * (n + 1) / 2;
        sum -= (n - m) * (n - m + 1) / 2;

        if (sum % 2) cout << "NO\n";
        else cout << "YES\n";
    }


    return 0;
}
