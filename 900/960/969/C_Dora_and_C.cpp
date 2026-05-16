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
ll arr[2 * MAX];

int main() {
    fastio;

    cin >> t;
    _gcd gcd;
    while (t--) {
        cin >> n >> m >> k;
        ll g = gcd.ret(m, k);
        for (int i = 1; i <= n; i++) {
            cin >> arr[i]; arr[i] %= g;
        }
        sort(arr + 1, arr + n + 1);

        ll result = INF;
        for (int i = n + 1; i <= 2 * n; i++) {
            arr[i] = arr[i - n] + g;
            result = min(arr[i] - arr[i - n + 1], result);
        }

        cout << result << "\n";
    }


    return 0;
}
