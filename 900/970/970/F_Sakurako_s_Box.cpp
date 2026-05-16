#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 1e9 + 7;
ll arr[MAX], sum[MAX];
ll pow_mod(ll a, ll b, ll c) {
    if (!b) return 1;
    ll ret = pow_mod(a, b / 2, c) % c;

    if (b % 2) return ((ret * ret) % c * (a % c)) % c;
    return (ret * ret) % c;
}

ll prime_inv(ll a, ll b) {
    return pow_mod(a, b - 2, b);
}

ll ret(ll a, ll b, ll m) {
    return (a % m * prime_inv(b, m) % m) % m;
}

int main() {
    fastio;

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        sum[n + 1] = 0;

        for (int i = n; i >= 1; i--) {
            sum[i] = sum[i + 1] + arr[i]; sum[i] %= MOD;
        }

        ll result = 0;
        for (int i = 1; i <= n; i++) {
            result += ((sum[i + 1] % MOD) * arr[i] % MOD) % MOD;
            result %= MOD;
        }
        ll m = ((n % MOD) * ((n - 1) % MOD)) % MOD;
        m = ret(m, 2, MOD);

        cout << ret(result, m, MOD) << '\n';
    }


    return 0;
}
