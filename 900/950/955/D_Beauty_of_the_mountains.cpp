#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 501;
constexpr ll MOD = 1e9 + 7;
ll arr[MAX][MAX], sum[2];
ll ps[MAX][MAX];
string st[MAX];
set <ll> d;

class _gcd {
public:
    _gcd() {}

    tuple <ll, ll, ll> init(ll a, ll b) {
        if (!b) return { a, 1, 0 };
        auto [g, x, y] = init(b, a % b);
        return { g, y, x - a / b * y };
    }

    ll ret(ll a, ll b) {
        return get<0>(init(a, b));
    }

    ll inv(ll a, ll mod) {
        auto [g, x, y] = init(a, mod);
        if (!a || g != 1) return -1;
        return (x < 0 ? x + mod : x);
    }
};

int main() {
    fastio;

    _gcd gcd;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) cin >> arr[i][j];
        }

        d.clear(); memset(sum, 0, sizeof(sum));
        for (int i = 0; i < n; i++) cin >> st[i];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) sum[st[i][j] - '0'] += arr[i][j];
        }
        ll diff = abs(sum[1] - sum[0]);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                ps[i][j] = ps[i][j - 1] + ps[i - 1][j] - ps[i - 1][j - 1] + (st[i - 1][j - 1] - '0');
            }
        }

        for (int i = k; i <= n; i++) {
            for (int j = k; j <= m; j++) {
                ll one = ps[i][j] - ps[i - k][j] - ps[i][j - k] + ps[i - k][j - k];
                ll zero = k * k - one;

                d.insert(abs(one - zero));
            }
        }

        ll g = 0;
        for (auto& i : d) g = gcd.ret(g, i);

        if (!diff) cout << "YES\n";
        else if (!g) cout << "NO\n";
        else if (diff % g == 0) cout << "YES\n";
        else cout << "NO\n";
    }


    return 0;
}
