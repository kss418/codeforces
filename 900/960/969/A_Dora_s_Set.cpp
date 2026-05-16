#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std; typedef long long ll;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 201010;
constexpr ll MOD = 1e9 + 7;
vector <ll> arr;

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
    cin >> t;
    _gcd gcd;
    while (t--) {
        cin >> n >> m;

        ll result = 0;
        arr.clear();
        for (int i = n; i <= m; i++) {
            if (i % 2 == 0) continue;
            arr.push_back(i);
        }

        for (int i = 0; i < arr.size() - 1; i++) {
            if (i + 1 > arr.size()) break;
            ll g = gcd.ret(arr[i], arr[i + 1]);
            if (g != 1) continue;
            result++; i++;
        }

        cout << result << "\n";
    }



    return 0;
}
